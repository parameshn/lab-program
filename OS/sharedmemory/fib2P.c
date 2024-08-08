#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
    // Check if the correct number of arguments are passed
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <number_of_terms>\n", argv[0]);
        exit(1);
    }

    // Convert the argument to an integer
    int n = atoi(argv[1]);
    // Check if the number of terms is greater than 0
    if (n < 1)
    {
        fprintf(stderr, "Number of terms must be greater than 0.\n");
        exit(1);
    }

    const int SIZE = 4096; // Size of the shared memory
    pid_t pid = fork();    // Create a child process

    if (pid < 0)
    {
        // Error handling for fork
        perror("fork");
        exit(1);
    }

    if (pid == 0)
    {
        // Child process: Execute the child program
        execlp("./fib_child", "fib_child", argv[1], NULL);
    }
    else
    {
        // Parent process: Wait for the child to complete
        wait(NULL);
        printf("\n[PARENT]: Child Completed\n");

        // Open the shared memory
        int shm_fd = shm_open("OS", O_RDONLY, 0666);
        if (shm_fd == -1)
        {
            perror("shm_open");
            exit(1);
        }

        // Map the shared memory
        void *ptr = mmap(0, SIZE, PROT_READ, MAP_SHARED, shm_fd, 0);
        if (ptr == MAP_FAILED)
        {
            perror("mmap");
            exit(1);
        }

        // Print the Fibonacci series from shared memory
        printf("Parent printing:\n");
        printf("%s\n", (char *)ptr);

        // Unmap the shared memory
        munmap(ptr, SIZE);
        // Unlink the shared memory
        shm_unlink("OS");
    }

    return 0;
}
