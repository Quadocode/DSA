#include <stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Queue
{
    struct Node *front,*rear;
};

bool isEmpty(struct Queue *queue)
{
    if(queue->front == NULL)
    {
        return true;
    }
    return false;
}

int peek(struct Queue *queue)
{
    if(isEmpty(queue))
    {
        printf("Queue is Empty!!\n");
        return -1;
    }
    return queue->front->data;
}


int dequeue(struct Queue *queue)
{
    int dequeuedData;
    if(!isEmpty(queue))
    {
        dequeuedData = peek(queue);
        queue->front = queue->front->next;
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
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    
    if(queue->rear != NULL)
    {
        queue->rear->next = newNode;
    }
    queue->rear = newNode;
    
    if(queue->front == NULL)
    {
        queue->front = queue->rear;
    }
}


struct Queue *createQueue()
{
    struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

void displayQueue(struct Queue *queue)
{
    printf("printing queue\n");
    struct Node *temp = queue->front;
    
    if(isEmpty(queue))
    {
        printf("Queue is Empty in display\n\n");
        return;
    }
    while(temp != queue->rear)
    {
        printf("%d->",temp->data);
        temp = temp->next;
    }
    printf("%d\n\n",temp->data);
}

int main()
{
    struct Queue *queue1 = createQueue();
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
    return 0;
}
