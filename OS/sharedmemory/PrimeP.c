#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <stdlib.h>

#define SIZE 4096 // Size of the shared memory segment

int main(int argumentCount, char *argumentVector[])
{
    int sharedMemoryFileDescriptor;
    pid_t processID;
    void *ptr;

    // Check if the correct number of command-line arguments are provided
    if (argumentCount > 2)
    {
        // Convert command-line arguments to integers
        int M = atoi(argumentVector[1]);
        int N = atoi(argumentVector[2]);

        if (M < 2)
        {
            printf("Error input: %d\n", M);
            return 0;
        }
    }
    else
    {
        printf("Error: Minimum of two arguments must be passed as command line arguments!\n");
        exit(0);
    }

    // Fork a child process
    processID = fork();
    if (processID == 0)
    {
        // In the child process, execute the child program
        execlp("./child", "child", argumentVector[1], argumentVector[2], NULL);
        perror("execlp failed");
        exit(1);
    }
    else if (processID > 0)
    {
        // In the parent process, wait for the child to complete
        wait(NULL);
        printf("\nParent: child complete!\n");

        // Open the shared memory segment created by the child
        sharedMemoryFileDescriptor = shm_open("VSS", O_RDONLY, 0666);
        if (sharedMemoryFileDescriptor == -1)
        {
            perror("shm_open failed");
            exit(1);
        }

        // Map the shared memory segment to the address space of the parent process
        ptr = mmap(0, SIZE, PROT_READ, MAP_SHARED, sharedMemoryFileDescriptor, 0);
        if (ptr == MAP_FAILED)
        {
            perror("mmap failed");
            exit(1);
        }

        // Print the prime numbers from the shared memory
        printf("%s", (char *)ptr);

        // Unlink (remove) the shared memory segment
        if (shm_unlink("VSS") == -1)
        {
            perror("shm_unlink failed");
            exit(1);
        }
    }
    return 0;
}
