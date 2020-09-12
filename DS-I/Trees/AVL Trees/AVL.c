#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node * left;
    struct Node * right;
    int height;
};

struct Node * createNode(int data)
{
    struct Node * newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data=data;
    newnode->left=NULL;
    newnode->right=NULL;
    newnode->height=1;

    return newnode;
}

int max (int a, int b)
{
    if(a>b) return a;
    return b;
}

int height(struct Node * node)
{
    if(node==NULL)
    return 0;
    
    return node->height;
    
}

struct Node *rightRotate(struct Node *root) 
{ 
    struct Node * l = root->left; 
    struct Node * l_r = l->right; 
  
    
    l->right = root; 
    root->left = l_r; 
  
    
    root->height = max(height(root->left), 
    height(root->right))+1; 

    l->height = max(height(l->left), 
    height(l->right))+1; 
  
    
    return l; 
} 
  

struct Node *leftRotate(struct Node *root) 
{ 
    struct Node * r = root->right; 
    struct Node * r_l = r->left; 
  
    
    r->left = root; 
    root->right = r_l; 
  
    
    root->height = max(height(root->left),
     height(root->right))+1; 
    r->height = max(height(r->left),
     height(r->right))+1; 
  
    
    return r; 
} 

int getBalance(struct Node *N) 
{ 
    if (N == NULL) 
        return 0; 
    return height(N->left) - height(N->right); 
}

struct Node * insert(struct Node * root, int data)
{
    if(root == NULL)
    {
        return createNode(data);
    }

    if(data>root->data)
    {
        root->right = insert(root->right,data);
    }
    else
    {
        root->left = insert(root->left,data);
    }

    root->height = max(height(root->left),height(root->right))+1;

    int bal = getBalance(root);

    if(bal>1 && data<root->left->data)
    {
        return rightRotate(root);
    }

    if(bal<-1 && data>root->right->data)
    {
        return leftRotate(root);
    }

    if(bal>1 && data>root->left->data)
    {
        root->left=leftRotate(root->left);
        return rightRotate(root);
    }

    if(bal<-1 && data<root->right->data)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    

    return root;
    
}

void preorder(struct Node * root)
{
    if(root==NULL)
    return;

    printf("%d ",root->data);
    
    preorder(root->left);
    preorder(root->right);
}

int main()
{
    int arr[11] = {10,20,30,40,50,60,70,80,90,100,65};
    struct Node * root = NULL;
    for(int i=0; i<11; ++i)
    {
        root=insert(root,arr[i]);
    }

    preorder(root);
    printf("\n");

    return 0;
}