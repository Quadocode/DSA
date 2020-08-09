#include <stdio.h>
#include<stdlib.h>
#include<stdbool.h>

//freeing array space

int capacity;
int *queue;
int front = -1,rear = -1;

int queueSize()
{
    if(front == -1)
    {
        return 0;
    }
    return (rear-front) + 1; 
}

bool isQueueEmpty()
{
    if(front == -1 || front > rear)
    {
        return true;
    }
    return false;
}

bool isQueueFull()
{
    if(rear == capacity-1)
    {
        return true;
    }
    return false;
}

int peek()
{
    if(front == -1)
    {
        return -1;
    }
    return queue[front];
}


int dequeue()
{
    int dequeuedData;
    if(!isQueueEmpty())
    {
        dequeuedData = peek();
        front++;
    }
    else
    {
        dequeuedData = -1;
    }
    return dequeuedData;
}

void enqueue(int data)
{
    if(!isQueueFull())
    {
        rear++;
        queue[rear] = data;
        if(front == -1)
        {
            front++;
        }
    }
    else
    {
        printf("Queue overflow!!\n\n");
    }
}


int *createQueue(int capacity)
{
    queue =  (int *)malloc(capacity*sizeof(int));
}

void displayQueue()
{
    if(isQueueEmpty())
    {
        printf("queue Underflow\n\n");
        return;
    }
    for(int i=front; i<=rear; i++)
    {
        printf("%d ",queue[i]);
    }
    printf("\n\n");
}

int main()
{
    scanf("%d",&capacity);
    createQueue(capacity);
    printf("queue size : %d\n",queueSize());
    displayQueue(queue);
    
    enqueue(10);
    printf("queue size : %d\n",queueSize());
    displayQueue();
    
    enqueue(20);
    printf("queue size : %d\n",queueSize());
    displayQueue();
    
    enqueue(30);
    printf("queue size : %d\n",queueSize());
    displayQueue();
    
    enqueue(40);
    printf("queue size : %d\n",queueSize());
    displayQueue();
    
    enqueue(50);
    printf("queue size : %d\n",queueSize());
    displayQueue();
    
    enqueue(60);
    printf("queue size : %d\n",queueSize());
    displayQueue();
    
    
    int d = dequeue();
    printf("queue size : %d\n",queueSize());
    printf("dequeued = %d\n",d);
    displayQueue();
    
    d = dequeue();
    printf("queue size : %d\n",queueSize());
    printf("dequeued = %d\n",d);
    displayQueue();
    
     d = dequeue();
    printf("queue size : %d\n",queueSize());
    printf("dequeued = %d\n",d);
    displayQueue();
    
     d = dequeue();
    printf("queue size : %d\n",queueSize());
    printf("dequeued = %d\n",d);
    displayQueue();
    
     d = dequeue();
    printf("queue size : %d\n",queueSize());
    printf("dequeued = %d\n",d);
    displayQueue();
    
     d = dequeue();
    printf("queue size : %d\n",queueSize());
    printf("dequeued = %d\n",d);
    displayQueue();
    return 0;
}
