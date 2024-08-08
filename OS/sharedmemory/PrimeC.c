#include <sys/types.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SIZE 4096 // Size of the shared memory segment

// Function to check if a number is prime
int is_prime(int num)
{
    if (num <= 1)
        return 0;
    if (num == 2)
        return 1;
    if (num % 2 == 0)
        return 0;
    for (int i = 3; i <= sqrt(num); i += 2)
    {
        if (num % i == 0)
            return 0;
    }
    return 1;
}

int main(int argumentCount, char *argumentVector[])
{
    void *ptr;
    int sharedMemoryFileDescriptor;

    // Open or create a shared memory segment
    sharedMemoryFileDescriptor = shm_open("VSS", O_CREAT | O_RDWR, 0666);
    if (sharedMemoryFileDescriptor == -1)
    {
        perror("shm_open failed");
        exit(1);
    }

    // Set the size of the shared memory segment
    if (ftruncate(sharedMemoryFileDescriptor, SIZE) == -1)
    {
        perror("ftruncate failed");
        exit(1);
    }

    // Map the shared memory segment to the address space of the child process
    ptr = mmap(0, SIZE, PROT_WRITE, MAP_SHARED, sharedMemoryFileDescriptor, 0);
    if (ptr == MAP_FAILED)
    {
        perror("mmap failed");
        exit(1);
    }

    int M = atoi(argumentVector[1]);
    int N = atoi(argumentVector[2]);
    char buffer[SIZE];
    int offset = 0;

    // Generate prime numbers in the range [M, N] and write them to the shared memory
    for (int num = M; num <= N; num++)
    {
        if (is_prime(num))
        {
            offset += snprintf(buffer + offset, SIZE - offset, "%d ", num);
        }
    }

    // Write the buffer to the shared memory
    snprintf(ptr, SIZE, "%s", buffer);

    // Unlink (remove) the shared memory segment
    if (shm_unlink("VSS") == -1)
    {
        perror("shm_unlink failed");
        exit(1);
    }

    return 0;
}
