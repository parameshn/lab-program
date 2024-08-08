#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>

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
        exit(1);
    }

    // Get shared memory ID
    int shmid = shmget((key_t)1122, 4096, 0666);
    if (shmid == -1)
    {
        perror("shmget");
        exit(1);
    }

    // Attach to the shared memory segment
    void *shm_ptr = shmat(shmid, NULL, 0);
    if (shm_ptr == (void *)-1)
    {
        perror("shmat");
        exit(1);
    }

    int n1 = 0, n2 = 1, n3;
    int k = 2;

    printf("CHILD:\n");
    printf("%d %d ", n1, n2);

    sprintf(shm_ptr, "%d ", n1);
    shm_ptr += strlen(shm_ptr);
    sprintf(shm_ptr, "%d ", n2);
    shm_ptr += strlen(shm_ptr);

    while (k < num_terms)
    {
        n3 = n1 + n2;
        sprintf(shm_ptr, "%d ", n3);
        shm_ptr += strlen(shm_ptr);
        printf("%d ", n3);
        n1 = n2;
        n2 = n3;
        k++;
    }

    // Detach from shared memory
    shmdt(shm_ptr);

    return 0;
}
