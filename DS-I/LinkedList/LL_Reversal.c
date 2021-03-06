#include <stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct Node
{
    int data;
    struct Node *next;
};

int size(struct Node *head)
{
    struct Node *temp = head;
    int count = 0;
    while(temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

struct Node *delete(struct Node *head,int pos)
{
    struct Node *temp1 = head,*temp2;
    if(pos == 1)
    {
        head = head->next;
    }
    for(int i=0; i<pos-2; i++)
    {
        temp1 = temp1->next;
    }
    temp1->next = temp1->next->next;
    return head;
}

struct Node *insertAt(struct Node *head,int pos, int data)
{
    if(pos > size(head)+1)
    {
        printf("Index out of bounds!!\n");
        return head;
    }
    //printf("heere");
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    
    struct Node *temp1 = head,*temp2;
    if(pos == 1)
    {
        newNode->next = head;
        head = newNode;
        return head;
    }
    for(int i=0; i<pos-2; i++)
    {
        temp1 = temp1->next;
    }
    
    temp2 = temp1->next;
    temp1->next = newNode;
    newNode->next = temp2;
    
    return head;
}

struct Node *insert(struct Node *head,int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    
    struct Node *temp=head;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

struct Node *create(struct Node *head,int *arr,int len)
{
    struct Node *temp;
    for(int i=0; i<len; i++)
    {
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = arr[i];
        newNode->next = NULL;
        if(head == NULL)
        {
            head = newNode;
            temp = head;
        }
        else
        {
            temp->next = newNode;
            temp = newNode;
        }
    }
    
    return head;
}

void display(struct Node *head)
{
    printf("printing list\n");
    struct Node *temp = head;
    
    while(temp != NULL)
    {
        printf("%d->",temp->data);
        temp = temp->next;
    }
    printf("NULL\n\n");
    return;
}

struct Node *reverse(struct Node *head)
{
    printf("reversing List");
    struct Node *prev = NULL,*current = head,*next = NULL;
    while(current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

int main()
{
    int size;
    scanf("%d",&size);
    int *arr = (int *)malloc(size*sizeof(int));
    for(int i=0; i<size; i++)
    {
        scanf("%d", &arr[i]);
    }
    struct Node *head;
    head = create(head,arr,size);
    display(head);
    
    head = reverse(head);
    display(head);
    return 0;
}
