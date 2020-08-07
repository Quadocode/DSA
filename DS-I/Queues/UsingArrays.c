#include <stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct Queue
{
    int *arr;
    int capacity;
    int front,rear;
};

bool isQueueEmpty(struct Queue *queue)
{
    if(queue->front == -1 || queue->front > queue->rear)
    {
        return true;
    }
    return false;
}

bool isQueueFull(struct Queue *queue)
{
    if(queue->rear == queue->capacity-1)
    {
        return true;
    }
    return false;
}

int peek(struct Queue *queue)
{
    if(isQueueEmpty(queue))
    {
        printf("Queue is Empty!!\n");
        return -1;
    }
    return queue->arr[queue->front];
}


int dequeue(struct Queue *queue)
{
    int dequeuedData;
    if(!isQueueEmpty(queue))
    {
        dequeuedData = peek(queue);
        queue->front++;
    }
    else
    {
        printf("Queue is Empty!!\n");
        dequeuedData = -1;
    }
    return dequeuedData;
}

void enqueue(struct Queue *queue,int data)
{
    if(!isQueueFull(queue))
    {
        queue->arr[queue->rear+1] = data;
        queue->rear++;
        if(queue->front == -1)
        {
            queue->front++;
        }
    }
    else
    {
        printf("Queue is full!!\n\n");
    }
}


struct Queue *createQueue(int capacity)
{
    struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = -1;
    queue->rear = -1;
    queue->arr = (int *)malloc(capacity*sizeof(int));
    return queue;
}

void displayFullQueueArray(struct Queue *queue)
{
    printf("printing full queue\n");
    for(int i=0; i<queue->capacity; i++)
    {
        printf("%d ",queue->arr[i]);
    }
    printf("\n");
}

void displayQueue(struct Queue *queue)
{
    printf("printing queue\n");
    if(isQueueEmpty(queue))
    {
        printf("Queue is Empty in display\n\n");
        return;
    }
    for(int i=queue->front; i<=queue->rear; i++)
    {
        printf("%d ",queue->arr[i]);
    }
    printf("\n\n");
}

int main()
{
    int noe;
    scanf("%d",&noe);
    struct Queue *queue1 = createQueue(noe);
    displayQueue(queue1);
    
    enqueue(queue1,10);
    displayQueue(queue1);
    
    enqueue(queue1,20);
    displayQueue(queue1);
    
    enqueue(queue1,30);
    displayQueue(queue1);
    
    enqueue(queue1,40);
    displayQueue(queue1);
    
    enqueue(queue1,50);
    displayQueue(queue1);
    
    enqueue(queue1,60);
    displayQueue(queue1);
    
    int dequeued = dequeue(queue1);
    displayQueue(queue1);
    
    dequeued = dequeue(queue1);
    displayQueue(queue1);
    
    dequeued = dequeue(queue1);
    displayQueue(queue1);
    
    dequeued = dequeue(queue1);
    displayQueue(queue1);
    
    dequeued = dequeue(queue1);
    displayQueue(queue1);
    
    dequeued = dequeue(queue1);
    displayQueue(queue1);
    
    displayFullQueueArray(queue1);
    return 0;
}
