#include<stdio.h>
#include<stdlib.h>

typedef struct {
    int *items;
    int front, rear, size;
} Que;

void insertRear(Que *pq) {
    int item;
    if ((pq->rear + 1) % pq->size == pq->front) {
        printf("\nQueue is full\n");
        return;
    }

    printf("\nEnter the element to be inserted: ");
    scanf("%d", &item);

    // This is for the first insertion when both front and rear are -1.
    if (pq->front == -1) {
        pq->front = 0;
    }
    
    pq->rear = (pq->rear + 1) % pq->size;
    pq->items[pq->rear] = item;
}

void insertFront(Que *pq) {
    int item;
    if ((pq->rear + 1) % pq->size == pq->front) {
        printf("\nQueue is full\n");
        return;
    }

    printf("\nEnter the item to be inserted: ");
    scanf("%d", &item);

    // This condition is for first insertion when both front and rear are -1.
    if (pq->front == -1) {
        pq->front = pq->rear = 0;
    } else if (pq->front == 0) {
        pq->front = pq->size - 1;
    } else {
        pq->front--;
    }
    
    pq->items[pq->front] = item;
}

void deleteFront(Que *pq) {
    if (pq->front == -1) {
        printf("\nQueue is empty\n");
        return;
    }

    printf("\nDeleted element is %d\n", pq->items[pq->front]);

    if (pq->front == pq->rear) {
        pq->front = pq->rear = -1; // Queue becomes empty
    } else {
        pq->front = (pq->front + 1) % pq->size;
    }
}

void deleteRear(Que *pq) {
    if (pq->front == -1) {
        printf("\nQueue is empty\n");
        return;
    }

    printf("\nDeleted item is %d", pq->items[pq->rear]);

    if (pq->front == pq->rear) {
        pq->front = pq->rear = -1; // Queue becomes empty
    } else if (pq->rear == 0) {
        pq->rear = pq->size - 1;
    } else {
        pq->rear--;
    }
}

void display(Que *pq) {
    if (pq->front == -1) {
        printf("\nQueue is empty\n");
        return;
    }

    printf("\nThe elements are:\n");
    int i = pq->front;
    do {
        printf("%d\t", pq->items[i]);
        i = (i + 1) % pq->size;
    } while (i != (pq->rear + 1) % pq->size);
}

void qFront(Que *pq) {
    if (pq->front == -1) {
        printf("\nQueue is empty\n");
        return;
    }

    printf("\nFront element of the queue is %d\n", pq->items[pq->front]);
}

void qRear(Que *pq) {
    if (pq->front == -1) {
        printf("\nQueue is empty\n");
        return;
    }

    printf("\nRear element of the queue is %d\n", pq->items[pq->rear]);
}

void main() {
    Que Q;
    Q.front = -1;
    Q.rear = -1;

    printf("\nEnter the size of the queue: ");
    scanf("%d", &Q.size);

    Q.items = (int *)malloc(Q.size * sizeof(int));

    int choice;

    for (;;) {
        printf("\nEnter your choice\n1. Insert by rear\n2. Delete by front\n3. Display\n4. Insert by front\n5. Delete by rear\n6. Display first item of the queue\n7. Display last item of the queue\n8. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insertRear(&Q); display(&Q); break;
            case 2: deleteFront(&Q); display(&Q); break;
            case 3: display(&Q); break;
            case 4: insertFront(&Q); display(&Q); break;
            case 5: deleteRear(&Q); display(&Q); break;
            case 6: qFront(&Q); break;
            case 7: qRear(&Q); break;
            case 8: free(Q.items); exit(0);
            default: printf("\nInvalid choice\n"); break;
        }
    }
}
