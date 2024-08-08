#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <sys/wait.h>

// Define the structure for the shared memory
typedef struct
{
    int n;        // Number of odd numbers to generate
    int arr[100]; // Array to store the odd numbers (maximum 100)
} pack_t;

int main()
{
    key_t key = 1234; // Key for the shared memory segment

    // Create the shared memory segment
    int shmid = shmget(key, sizeof(pack_t), 0666 | IPC_CREAT);
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

    printf("[PARENT] created memory with key=%d, id=%d, address=%p\n", key, shmid, shm_ptr);

    // Ask the user to enter the number of odd numbers to generate
    printf("[PARENT] enter n: ");
    scanf("%d", &shm_ptr->n);

    pid_t child_pid;

    // Create a child process
    if ((child_pid = fork()) == 0)
    {
        // In the child process, execute the odd_child program
        execlp("./odd_child", "./odd_child", NULL);
        perror("execlp failed");
        exit(1);
    }
    else
    {
        // In the parent process, wait for the child to finish
        wait(NULL);
        printf("[CHILD] finished execution\n");

        // Print the generated odd numbers
        printf("[CHILD] the first %d odd numbers are: ", shm_ptr->n);
        for (int i = 0; i < shm_ptr->n; i++)
        {
            printf("%d ", shm_ptr->arr[i]);
        }
        putchar('\n');
    }

    // Detach from the shared memory segment
    if (shmdt(shm_ptr) == -1)
    {
        perror("shmdt failed");
        exit(1);
    }

    // Delete the shared memory segment
    if (shmctl(shmid, IPC_RMID, NULL) == -1)
    {
        perror("shmctl failed");
        exit(1);
    }

    printf("[PARENT] shared memory deleted\n");

    return 0;
}
