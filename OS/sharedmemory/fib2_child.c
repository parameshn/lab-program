#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

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
    // Open the shared memory
    int shm_fd = shm_open("OS", O_CREAT | O_RDWR, 0666);
    // Set the size of the shared memory
    ftruncate(shm_fd, SIZE);
    // Map the shared memory
    void *ptr = mmap(0, SIZE, PROT_WRITE, MAP_SHARED, shm_fd, 0);

    if (ptr == MAP_FAILED)
    {
        perror("mmap");
        exit(1);
    }

    // Initialize the first two Fibonacci numbers
    int n1 = 0, n2 = 1, n3;
    sprintf(ptr, "%d ", n1); // Write the first number to shared memory
    ptr += strlen(ptr);
    printf("%d ", n1);

    if (n > 1)
    {
        sprintf(ptr, "%d ", n2); // Write the second number to shared memory
        ptr += strlen(ptr);
        printf("%d ", n2);
    }

    // Generate the Fibonacci series
    for (int i = 2; i < n; i++)
    {
        n3 = n1 + n2;
        sprintf(ptr, "%d ", n3); // Write the next number to shared memory
        printf("%d ", n3);
        n1 = n2;
        n2 = n3;
        ptr += strlen(ptr);
    }
    printf("\n");

    return 0;
}
