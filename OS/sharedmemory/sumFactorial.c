#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Function prototypes for the threads
void *sum_thread(void *arg);
void *factorial_thread(void *arg);

// Global variables to store the results
int sum_result = 0;
long long factorial_result = 1;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <n>\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);
    if (n < 0)
    {
        fprintf(stderr, "Please enter a non-negative integer.\n");
        return 1;
    }

    // Thread identifiers
    pthread_t sum_tid, factorial_tid;

    // Create the sum thread
    if (pthread_create(&sum_tid, NULL, sum_thread, &n) != 0)
    {
        perror("Failed to create sum thread");
        return 1;
    }

    // Create the factorial thread
    if (pthread_create(&factorial_tid, NULL, factorial_thread, &n) != 0)
    {
        perror("Failed to create factorial thread");
        return 1;
    }

    // Wait for both threads to complete
    if (pthread_join(sum_tid, NULL) != 0)
    {
        perror("Failed to join sum thread");
        return 1;
    }
    if (pthread_join(factorial_tid, NULL) != 0)
    {
        perror("Failed to join factorial thread");
        return 1;
    }

    // Print the results
    printf("Sum of first %d natural numbers: %d\n", n, sum_result);
    printf("Factorial of %d: %lld\n", n, factorial_result);

    return 0;
}

// Thread function to calculate the sum of first n natural numbers
void *sum_thread(void *arg)
{
    int n = *(int *)arg;
    printf("Sum thread started for n = %d\n", n);

    for (int i = 1; i <= n; i++)
    {
        sum_result += i;
    }

    printf("Sum thread completed\n");
    pthread_exit(NULL);
}

// Thread function to calculate the factorial of n
void *factorial_thread(void *arg)
{
    int n = *(int *)arg;
    printf("Factorial thread started for n = %d\n", n);

    for (int i = 1; i <= n; i++)
    {
        factorial_result *= i;
    }

    printf("Factorial thread completed\n");
    pthread_exit(NULL);
}
