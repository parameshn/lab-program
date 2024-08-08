#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include <stdio.h>

#define MaxItems 3   // Maximum items a producer can produce or a consumer can consume
#define BufferSize 3 // Size of the buffer

// Shared buffer and indices
sem_t empty;            // Semaphore to count empty slots
sem_t full;             // Semaphore to count full slots
int in = 0;             // Index for producer
int out = 0;            // Index for consumer
int buffer[BufferSize]; // Buffer to store items
pthread_mutex_t mutex;  // Mutex to protect buffer access

// Producer thread function
void *producer(void *pno)
{
    int item;
    for (int i = 0; i < MaxItems; i++)
    {
        item = rand() % 100;        // Produce a random item
        sem_wait(&empty);           // Wait if buffer is full
        pthread_mutex_lock(&mutex); // Lock the buffer
        buffer[in] = item;          // Add item to buffer
        printf("Producer %d: Insert Item %d at %d\n", *((int *)pno), buffer[in], in);
        in = (in + 1) % BufferSize;   // Update the index
        pthread_mutex_unlock(&mutex); // Unlock the buffer
        sem_post(&full);              // Signal that buffer has a new item
    }
    return NULL;
}

// Consumer thread function
void *consumer(void *cno)
{
    for (int i = 0; i < MaxItems; i++)
    {
        sem_wait(&full);            // Wait if buffer is empty
        pthread_mutex_lock(&mutex); // Lock the buffer
        int item = buffer[out];     // Remove item from buffer
        printf("Consumer %d: Remove Item %d from %d\n", *((int *)cno), item, out);
        out = (out + 1) % BufferSize; // Update the index
        pthread_mutex_unlock(&mutex); // Unlock the buffer
        sem_post(&empty);             // Signal that buffer has an empty slot
    }
    return NULL;
}

int main()
{
    pthread_t pro[3], con[3];         // Thread identifiers
    pthread_mutex_init(&mutex, NULL); // Initialize mutex
    sem_init(&empty, 0, BufferSize);  // Initialize semaphore for empty slots
    sem_init(&full, 0, 0);            // Initialize semaphore for full slots

    int a[3] = {1, 2, 3}; // IDs for producer and consumer threads

    // Create producer threads
    for (int i = 0; i < 3; i++)
    {
        pthread_create(&pro[i], NULL, producer, (void *)&a[i]);
    }

    // Create consumer threads
    for (int i = 0; i < 3; i++)
    {
        pthread_create(&con[i], NULL, consumer, (void *)&a[i]);
    }

    // Wait for all producer threads to finish
    for (int i = 0; i < 3; i++)
    {
        pthread_join(pro[i], NULL);
    }

    // Wait for all consumer threads to finish
    for (int i = 0; i < 3; i++)
    {
        pthread_join(con[i], NULL);
    }

    // Cleanup
    pthread_mutex_destroy(&mutex);
    sem_destroy(&empty);
    sem_destroy(&full);

    return 0;
}
