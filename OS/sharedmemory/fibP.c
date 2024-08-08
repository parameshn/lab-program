#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <number_of_terms>\n", argv[0]);
        exit(1);
    }

    int num_terms = atoi(argv[1]);
    if (num_terms < 1)
    {
        fprintf(stderr, "Error: number of terms must be greater than 0\n");
        return 1;
    }

    // Create shared memory segment
    int shmid = shmget((key_t)1122, 4096, 0666 | IPC_CREAT);
    if (shmid == -1)
    {
        perror("shmget");
        exit(1);
    }

    // Fork a child process
    pid_t pid = fork();
    if (pid < 0)
    {
        perror("fork");
        exit(1);
    }

    if (pid == 0)
    {
        // Child process
        execlp("./fib_child", "fib_child", argv[1], NULL);
    }
    else
    {
        // Parent process
        wait(NULL);

        // Attach to the shared memory segment
        void *shm_ptr = shmat(shmid, NULL, 0);
        if (shm_ptr == (void *)-1)
        {
            perror("shmat");
            exit(1);
        }

        printf("\n[PARENT]: Child Completed\n");
        printf("Parent printing:\n");
        printf("%s\n", (char *)shm_ptr);

        // Detach from shared memory
        shmdt(shm_ptr);

        // Remove shared memory segment
        shmctl(shmid, IPC_RMID, NULL);
    }

    return 0;
}
