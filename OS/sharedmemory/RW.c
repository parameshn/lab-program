#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>

sem_t wrt;             // Semaphore to control access for writers
pthread_mutex_t mutex; // Mutex to control access to numreader
int cnt = 1;           // Shared variable to be modified by writers
int numreader = 0;     // Number of active readers

// Writer thread function
void *writer(void *wno)
{
    sem_wait(&wrt); // Wait (decrement) the semaphore; block if value is zero

    // Critical section
    cnt = cnt * 2; // Modify the shared variable
    printf("Writer %d modified cnt to %d\n", *((int *)wno), cnt);

    sem_post(&wrt); // Signal (increment) the semaphore; unblock if any threads are waiting
    return NULL;
}

// Reader thread function
void *reader(void *rno)
{
    pthread_mutex_lock(&mutex); // Lock the mutex to update numreader
    numreader++;
    if (numreader == 1)
    {
        sem_wait(&wrt); // If this is the first reader, block writers
    }
    pthread_mutex_unlock(&mutex); // Unlock the mutex

    // Reading section
    printf("Reader %d: read cnt as %d\n", *((int *)rno), cnt);

    pthread_mutex_lock(&mutex); // Lock the mutex to update numreader
    numreader--;
    if (numreader == 0)
    {
        sem_post(&wrt); // If this is the last reader, unblock writers
    }
    pthread_mutex_unlock(&mutex); // Unlock the mutex
    return NULL;
}

int main()
{
    pthread_t read[3], write[3];      // Thread identifiers
    pthread_mutex_init(&mutex, NULL); // Initialize the mutex
    sem_init(&wrt, 0, 1);             // Initialize the semaphore (1 = binary semaphore, equivalent to mutex)

    int a[3] = {1, 2, 3}; // IDs for readers and writers

    // Create reader threads
    for (int i = 0; i < 3; i++)
    {
        pthread_create(&read[i], NULL, reader, (void *)&a[i]);
    }

    // Create writer threads
    for (int i = 0; i < 3; i++)
    {
        pthread_create(&write[i], NULL, writer, (void *)&a[i]);
    }

    // Wait for all reader threads to finish
    for (int i = 0; i < 3; i++)
    {
        pthread_join(read[i], NULL);
    }

    // Wait for all writer threads to finish
    for (int i = 0; i < 3; i++)
    {
        pthread_join(write[i], NULL);
    }

    // Cleanup
    pthread_mutex_destroy(&mutex); // Destroy the mutex
    sem_destroy(&wrt);             // Destroy the semaphore

    return 0;
}
