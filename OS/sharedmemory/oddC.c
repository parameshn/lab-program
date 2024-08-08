#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

// Define the structure for the shared memory
typedef struct
{
    int n;        // Number of odd numbers to generate
    int arr[100]; // Array to store the odd numbers (maximum 100)
} pack_t;

int main()
{
    key_t key = 1234; // Key for the shared memory segment

    // Get the shared memory segment ID
    int shmid = shmget(key, sizeof(pack_t), 0666);
    if (shmid == -1)
    {
        perror("shmget failed");
        exit(1);
    }

    // Attach to the shared memory segment
    pack_t *shm_ptr = (pack_t *)shmat(shmid, NULL, 0);
    if (shm_ptr == (void *)-1)
    {
        perror("shmat failed");
        exit(1);
    }

    printf("[CHILD] attached to shared memory with key=%d, id=%d, address=%p\n", key, shmid, shm_ptr);

    // Generate the first 'n' odd numbers and store them in the shared memory
    for (int i = 0; i < shm_ptr->n; i++)
    {
        shm_ptr->arr[i] = 2 * i + 1;
    }

    printf("[CHILD] finished generating first %d odd numbers\n", shm_ptr->n);

    // Detach from the shared memory segment
    if (shmdt(shm_ptr) == -1)
    {
        perror("shmdt failed");
        exit(1);
    }

    return 0;
}
