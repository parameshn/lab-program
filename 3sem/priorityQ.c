#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *items;
    int front, rear, count, size;
} Que;



void insert(Que *pq)
{
    int value ;
    if(pq->rear == pq->size -1)
    {
        printf("\nQueue is full!!");
        return;
    }
    printf("\nenter the element to be inserted\n");
    scanf("%d", &value);
    pq->rear = (pq->rear + 1) % pq->size;
    pq->items[pq->rear] = value;
    pq->count++;
}


void deletemin(Que *pq)
{
    int min,i,minindex;
    if(pq->front > pq->rear){
        printf("\nQueue underflow\n");
        return;
    }

    min = pq->items[pq->front];
    minindex = pq->front;
    for (i = pq->front ; i< pq->rear;i++)
    {
        if(pq->items[i] < min)
        {
            min = pq->items[i];
            minindex = i;
        }
    }

    for ( i = minindex;i <pq->rear;i++)
    {
        pq->items[i]= pq->items[i+1];
    }

    printf("\ndeleted elements is %d\n",min);
    pq->rear--;
}
void qFront(Que *pq) {
    if (pq->count == 0) {
        printf("\nqueue is empty\n");
        return;
    }

    printf("\nfront of the element of the queue is %d\n", pq->items[pq->front]);
}

void qRear(Que *pq) {
    if (pq->count == 0) {
        printf("\nqueue is empty\n");
        return;
    }

    printf("\nrear of the element of the queue is %d\n", pq->items[pq->rear]);
}

// void display(Que *pq) {
//     if (pq->front> pq->rear) {
//         printf("\nqueue is empty\n");
//         return;
//     }

//     printf("\nthe elements are\n");
//     for (int i = pq->front; i < pq->rear; i++) {
//         printf("%d\t", pq->items[i]);
//     }
    
// }
void display(Que *pq) {
    if (pq->rear == -1) {
        printf("\nQueue is empty\n");
        return;
    }

    printf("\nThe elements are:\n");
    int i = pq->front;
    do {
        printf("%d\t", pq->items[i]);
        i = (i + 1) % pq->size;
    } while (i != (pq->rear + 1) % pq->size);
    printf("\n");
}


void main() {
    Que Q;
    Q.front = 0;
    Q.rear = -1;

    printf("\nEnter the size of the queue: ");
    scanf("%d", &Q.size);

    Q.items = (int *)malloc(Q.size * sizeof(int));

    int choice;

    for (;;) {
        printf("\nEnter your choice\n1. Insert by rear\n2. Delete lowest\n3. Display\n4. Display first item of the queue\n5. Display last item of the queue\n6. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insert(&Q); display(&Q); break;
            case 2: deletemin(&Q); display(&Q); break;
            case 3: display(&Q); break;
            case 4: qFront(&Q); break;
            case 5: qRear(&Q); break;
            case 6: free(Q.items); exit(0);
            default: printf("\nInvalid choice\n"); break;
        }
    }
}