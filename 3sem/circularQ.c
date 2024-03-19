#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *items;
    int front, rear, count, size;
} Que;

void insert(Que *pq) {
    int value;

    if (pq->count == pq->size) {
        printf("\nqueue is full\n");
        return;
    }

    printf("\nenter the element to be inserted\n");
    scanf("%d", &value);
    pq->rear = (pq->rear + 1) % pq->size;
    pq->items[pq->rear] = value;
    pq->count++;
}

void display(Que *pq) {
    if (pq->count == 0) {
        printf("\nqueue is empty\n");
        return;
    }

    printf("\nthe elements are\n");
    for (int i = pq->front; i != pq->rear; i = (i + 1) % pq->size) {
        printf("%d\t", pq->items[i]);
    }
    printf("%d\t", pq->items[pq->rear]);
}

void delete(Que *pq) {
    if (pq->count == 0) {
        printf("\nqueue is empty\n");
        return;
    }
    printf("\nelement deleted is %d\n", pq->items[pq->front]);

    pq->front = (pq->front + 1) % pq->size;
    pq->count--;
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

int main() {
    Que Q;
    Q.front = 0;
    Q.rear = -1;
    Q.count = 0;

    int choice, size;

    printf("\nenter the size of the queue\n");
    scanf("%d", &size);

    Q.size = size;
    Q.items = (int *)malloc(size * sizeof(int));

    for (;;) {
        printf("\nEnter your choice\n1.insert\n2.delete\n3.display\n4.display first item of the queue\n5.display last item of the queue\n6.exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insert(&Q);
                display(&Q);
                break;
            case 2:
                delete(&Q);
                display(&Q);
                break;
            case 3:
                display(&Q);
                break;
            case 4:
                qFront(&Q);
                break;
            case 5:
                qRear(&Q);
                break;
            case 6:
                free(Q.items);
                exit(0);
            default:
                printf("\ninvalid choice\n");
                break;
        }
    }

    return 0;
}