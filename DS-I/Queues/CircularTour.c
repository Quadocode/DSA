#include <stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct PetrolPump
{
    int petrol;
    int distance;
    int id;
    struct PetrolPump *next;
};

struct Queue
{
    struct PetrolPump *front,*rear;
};


bool isEmpty(struct Queue *queue)
{
    if(queue->front == NULL)
    {
        return true;
    }
    return false;
}

struct PetrolPump *peek(struct Queue *queue)
{
    if(isEmpty(queue))
    {
        printf("Queue is Empty!!\n");
        return NULL;
    }
    return queue->front;
}


void displayQueue(struct Queue *queue)
{
    printf("printing queue\n");
    struct PetrolPump *temp = queue->front;
    
    if(isEmpty(queue))
    {
        printf("Queue is Empty in display\n\n");
        return;
    }
    while(temp != queue->rear)
    {
        printf("%d,%d<-",temp->petrol,temp->distance);
        temp = temp->next;
    }
    printf("%d,%d\n\n",temp->petrol,temp->distance);
}

struct PetrolPump *dequeue(struct Queue *queue)
{
    struct PetrolPump *dequeuedPump;
    if(!isEmpty(queue))
    {
        dequeuedPump = peek(queue);
        queue->front = queue->front->next;
    }
    else
    {
        printf("Queue is Empty!!\n");
        dequeuedPump = NULL;
    }
    return dequeuedPump;
}

void enqueue(struct Queue *queue,struct PetrolPump pump)
{
    struct PetrolPump *newPetrolPump = (struct PetrolPump *)malloc(sizeof(struct PetrolPump));
    newPetrolPump->petrol = pump.petrol;
    newPetrolPump->distance = pump.distance;
    newPetrolPump->id = pump.id;
    newPetrolPump->next = NULL;
    if(queue->rear != NULL)
    {
        queue->rear->next = newPetrolPump;
    }
    queue->rear = newPetrolPump;
    
    if(queue->front == NULL)
    {
        queue->front = queue->rear;
    }
}


struct Queue *createQueue(struct PetrolPump pumps[],int size)
{
    struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));
    queue->front = NULL;
    queue->rear = NULL;
    for(int i=0; i<size; i++)
    {
        enqueue(queue,pumps[i]);
    }
    return queue;
}



bool performCircularTour(struct Queue *pumpsQueue)
{
    int curr_petrol = 0;
    struct PetrolPump *temp = pumpsQueue->front;
    if(!isEmpty(pumpsQueue))
    {
        curr_petrol  = pumpsQueue->front->petrol - pumpsQueue->front->distance;
    }
     
    while(temp != pumpsQueue->rear)
    {
        if(curr_petrol > 0)
        {
            temp = temp->next;
            curr_petrol = (curr_petrol + temp->petrol) - temp->distance;
        }
        else
        {
            struct PetrolPump *dequeuedPump = dequeue(pumpsQueue);
            enqueue(pumpsQueue,*dequeuedPump);
            curr_petrol  = pumpsQueue->front->petrol - pumpsQueue->front->distance;
            displayQueue(pumpsQueue);
            if(pumpsQueue->front->id == 1)
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    struct PetrolPump pumps[] = {{6, 4, 1}, {3, 6, 2}, {7, 3, 3}, {4, 5, 4}};
    struct PetrolPump failPumps[] = {{3,4,1},{4,5,2},{5,6,3},{7,8,4}};
    struct Queue *pumpsQueue = createQueue(pumps,4);
    displayQueue(pumpsQueue);
    if(performCircularTour(pumpsQueue))
    {
        printf("start at pump - %d,%d\n",pumpsQueue->front->petrol,pumpsQueue->front->distance);
        displayQueue(pumpsQueue);
    }
    else
    {
        printf("Not possible");
    }
    return 0;
}
