#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Stack
{
    int top;
    int max_size;
    int *array;
};


struct Stack *createStack(int size)
{
    struct Stack *stk;
    stk = (struct Stack*) malloc(sizeof(struct Stack));

    stk->top = -1 ;
    stk->max_size = size;
    stk->array = (int*)malloc(stk->max_size * sizeof(int) );
    return stk;
    
};

int size(struct Stack *stk)
{
    return (stk->top + 1);
}


int peek(struct Stack *stk)
{
    if (stk->top == -1)
        return INT_MIN;
    return stk->array[stk->top];
}

int isFull(struct Stack *stk)
{
    if ((stk->top)+1 == stk->max_size)
    {
        printf("stack is full , cannot push due to overflow\n");
        return 1;
    }
    else
    {
        return 0;
    }
    
}


int isEmpty(struct Stack *stk)
{
    if (stk->top == -1)
    {
        printf("stack is empty\n");
        return 1;
    }
    else
    {
        return 0;
    }
    
}


void push(int data,struct Stack *stk)
{
    int full = isFull(stk);
    if (full == 1)
        return;
    //below is equal to 
    //top++;
    //stk->array[top] = data;
    stk->array[++stk->top] = data; // this increments the top to the new index and then assigns the data at that index
    printf("pushed %d\n",data);
}

void pop(struct Stack *stk)
{
    int empty = isEmpty(stk);
    if (empty == 1)
        return;
    printf("popping %d\n",stk->array[stk->top]);
    --stk->top;
}

void display(struct Stack *stk)
{
    printf("printing the stack ..... \n");
    int empty = isEmpty(stk);
    if (empty == 1)
    {
        printf("----------------------------------\n");
        return;
    }
    for(int j = stk->top;j>-1; j--)
    {
        printf("%d\n",stk->array[j]);
    }
    printf("----------------------\n");
}

int main()
{
    struct Stack* stk;
    stk = createStack(5);
    

    push(1,stk);
    printf("size of stack is %d\n",size(stk));
    printf("---------------\n");
    display(stk);



    push(2,stk);
    printf("size of stack is %d\n",size(stk));
    printf("----------------------\n");
    display(stk);

    push(3,stk);
    printf("size of stack is %d\n",size(stk));
    printf("----------------------\n");
    display(stk);

    push(4,stk);
    printf("size of stack is %d\n",size(stk));
    printf("----------------------\n");
    display(stk);

    push(5,stk);
    printf("size of stack is %d\n",size(stk));
    printf("----------------------\n");
    display(stk);

    push(6,stk);
    printf("size of stack is %d\n",size(stk));
    printf("----------------------\n");
    display(stk);

    pop(stk);
    printf("size of stack is %d\n",size(stk));
    printf("----------------------\n");
    display(stk);

    pop(stk);
    printf("size of stack is %d\n",size(stk));
    printf("----------------------\n");
    display(stk);

    pop(stk);
    printf("size of stack is %d\n",size(stk));
    printf("----------------------\n");
    display(stk);

    pop(stk);
    printf("size of stack is %d\n",size(stk));
    printf("----------------------\n");
    display(stk);

    pop(stk);
    printf("size of stack is %d\n",size(stk));
    printf("----------------------\n");
    display(stk);

}