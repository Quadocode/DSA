#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Node{
    int data;
    struct Node *next;    
};

struct Stack
{
    struct Node *top;
    // int max_size;
};

struct Stack *createStack()
{
    struct Stack *stk;
    stk = (struct Stack*) malloc(sizeof(struct Stack));
    stk->top = NULL;
    // stk->max_size=size;
    return stk;
    
};


int size(struct Stack* stk)
{
    int stk_size = 0;
    struct Node *temp = stk->top;
    if (temp == NULL)
        return stk_size;
    while(temp != NULL)
    {
        stk_size++;
        temp = temp->next;
    }
    return stk_size;
}

// int isFull(struct Stack *stk)
// {
//     if (stk->max_size == size(stk))
//     {
//         printf("stack overflow as the stack is full\n");
//         return 1;
//     }
//     else
//     {
//         return 0;
//     }
    
// }



int isEmpty(struct Stack *stk)
{
    if(stk->top == NULL) //if the stack is empty return INT_MIN
    {
        printf("stack is empty\n");
        return 1;
    }
    else
    {
        return 0;
    }
    
}


void push(int data, struct Stack *stk)
{
    // int full = isFull(stk);
    // if (full==1)
    // {
    //     return;
    // }
    //create the node to be pushed and assign data to it
    struct Node *temp = (struct Node*) malloc(sizeof(struct Node));
    //if temp==NULL heap overflow
    temp->data = data;

    temp->next  = stk->top; //attach the existing stack to its tail
    stk->top = temp; //make the temp as the top 
    printf("pushed %d\n",data);

}

void pop(struct Stack *stk)
{
    int empty = isEmpty(stk);
    if (empty == 1)
        return;

    struct Node *temp = stk -> top; //create a node to point to top to be freed

    stk->top = stk->top->next; //point the stack to the next element of top 

    printf("popping out %d\n", temp-> data);
    free(temp); //free the popped element
}

int peek(struct Stack *stk)
{
    if (stk->top == NULL)
        return INT_MIN;
    return stk->top->data;
}

void display(struct Stack *stk)
{   
    int empty = isEmpty(stk);
    if (empty == 1)
    {
        printf("----------------------------------\n");
        return;
    }
    struct Node *temp = stk->top;
    while(temp!= NULL)
    {
        printf("%d\n",temp->data);
        temp = temp->next;
    }
    printf("---------------------\n");
    
}

int main()
{
    struct Stack* stk;
    // stk = createStack(5);
    stk = createStack();
    

    push(1,stk);
    printf("---------------\n");
    display(stk);


    push(2,stk);
    printf("----------------------\n");
    display(stk);

    push(3,stk);
    printf("----------------------\n");
    display(stk);

    push(4,stk);
    printf("----------------------\n");
    display(stk);

    push(5,stk);
    printf("----------------------\n");
    display(stk);

    push(6,stk);
    printf("----------------------\n");
    display(stk);

    pop(stk);
    printf("----------------------\n");
    display(stk);

    pop(stk);
    printf("----------------------\n");
    display(stk);

    pop(stk);
    printf("----------------------\n");
    display(stk);

    pop(stk);
    printf("----------------------\n");
    display(stk);

    pop(stk);
    printf("----------------------\n");
    display(stk);

    pop(stk);
    printf("----------------------\n");
    display(stk);

    
    
}
