#include<stdio.h>
#include<stdlib.h>




typedef struct 
{
    int *items;
    int front ,rear,size;
}Que;


void insertRear(Que *pq)
{
    int item;
    if(pq->rear == pq->size -1)
    {
        if(pq->front != 0)
        {
            printf("\nfront insertion is possible\n");
            return;
        }
        else
        {
            printf("\nQueue is full\n");
            return;
        }
    }


    printf("\nEnter the element to be inserted\n");
    scanf("%d",&item);

    pq->rear++;
    pq->items[pq->rear] = item;
}


void deleteFront(Que *pq)
{
    if(pq->front > pq->rear)
    {
        printf("\nQueue underflow\n");
        return;
    }

    printf("\ndeleted element is %d\n",pq->items[pq->front]);
    pq->front++;

    if(pq->front > pq->rear)
    {
        pq->front = 0;
        pq->rear = -1;
    }
}

void display(Que *pq) {
    if (pq->front> pq->rear) {
        printf("\nqueue is empty\n");
        return;
    }

    printf("\nthe elements are\n");
    for (int i = pq->front; i <= pq->rear; i++) {
        printf("%d\t", pq->items[i]);
    }
    //printf("%d\t", pq->items[pq->rear]);
}

void insertFront(Que *pq)
{
    int item;
    if(pq->front ==0 && pq->rear == -1)
    {
        printf("\nEnter the item to inserted \n");
        scanf("%d",&item);

        pq->items[++pq->rear] = item;
        return;
    }

    // if(pq->front == -1)
    // {
    //     printf("enter the item to be inserted\n");
    //     scanf("%d",&item);
    //     pq->items[++pq->rear] = item;
    //     pq->front++;
    //     return;
    // }

    if(pq->front != 0 ){
        printf("\nEnter the item to inserted \n");
        scanf("%d",&item);
        pq->items[--pq->front] = item;
        return;
    }

    

    if(pq->rear == pq->size -1 && pq->front == 0)
    {
        printf("\nQueue is full!!\n");
        return;
    }

    if(pq->rear != pq->size -1)
    {
        printf("\nrear insertions is possible\n");
        return;
    }

}

void deleteRear(Que *pq)
{
    if(pq->front > pq->rear)
    {
        printf("\nqueue is full\n");
        return;
    }

    printf("\ndeleted item is %d",pq->items[pq->rear]);
    pq->rear--;

    if(pq->front > pq->rear)
    {
        pq->front = 0;
        pq->rear = -1;
    }
}

void qFront(Que *pq) {
    if (pq->front > pq->rear) {
        printf("\nqueue is empty\n");
        return;
    }

    printf("\nfront of the element of the queue is %d\n", pq->items[pq->front]);
}

void qRear(Que *pq) {
    if (pq->front > pq->rear) {
        printf("\nqueue is empty\n");
        return;
    }

    printf("\nrear of the element of the queue is %d\n", pq->items[pq->rear]);
}

void main(){

    Que Q;
    Q.front = 0;
    Q.rear = -1;

    printf("\n enter the size of the queue\n");
    scanf("%d",&Q.size);

    Q.items = (int *)malloc(Q.size * sizeof(int));



    int choice;

    for(;;){
        printf("\nEnter your choice\n1.insert by rear\n2.delete by front\n3.display\n4.insert by front \n5.delete by rear\n6.display first item of the queue\n7.display last item of the queue\n8.exit\n");
        scanf("%d",&choice);

        switch(choice){
            case 1 : insertRear(&Q);display(&Q);break;
            case 2 : deleteFront(&Q);display(&Q);break;
            case 3 : display(&Q);break;
            case 4 : insertFront(&Q);display(&Q);break;
            case 5 : deleteRear(&Q);display(&Q);break;
            case 6 : qFront(&Q);break;
            case 7 : qRear(&Q);break;
            case 8: free(Q.items);exit(0);
            default : printf("\ninvalid choice\n");break;
        }
    }


}