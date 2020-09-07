#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct BSTNode{
    int data;
    struct BSTNode *left;
    struct BSTNode *right;
};

struct  BST
{
    struct BSTNode *root;
};

void BSTInsert_iter(int data ,struct BST *bst)
{
    //first create the data node which is to be inserted
    struct BSTNode *dataNode = (struct BSTNode *) malloc(sizeof(struct BSTNode));
    dataNode -> data = data;
    dataNode -> left = NULL;
    dataNode -> right = NULL;

    struct BSTNode *temp = bst->root;

    if (temp == NULL)
        bst->root = dataNode;
    else
    {
        while(temp!= NULL)
        {
            if (dataNode->data < temp->data)
                temp = temp -> left;
            else
            {
                if (dataNode->data > temp->data)
                    temp = temp->right;
            }
            
        }

        if (dataNode-> data  < temp -> data) 
            temp -> left = dataNode; 
        else
            if (dataNode-> data  > temp -> data) 
                temp -> right = dataNode; 
    }
}


struct BSTNode *BSTInsert_rec(int data ,struct BSTNode *root)
{
    if (root == NULL)
    {
        //first create the data node which is to be inserted
        struct BSTNode *dataNode = (struct BSTNode *) malloc(sizeof(struct BSTNode));
        dataNode -> data = data;
        dataNode -> left = NULL;
        dataNode -> right = NULL;

        root = dataNode;
        return root;
    }
    else
    {
        if (data < root->data)
            root->left = BSTInsert_rec(data,root->left);
        else if (data > root->data)
            root->right = BSTInsert_rec(data,root->right);
        return root;

    }  
}


int getLevelCount(struct BSTNode *node)
{
    if (node == NULL)
    {
        return 0;
    }
    int leftMaxLevel = 1 + getLevelCount(node->left);
    int rightMaxLevel = 1 + getLevelCount(node->right);
    if (leftMaxLevel > rightMaxLevel)
    {
        return leftMaxLevel;
    }
    else
    {
        return rightMaxLevel;
    }
}


void printLevel(struct BSTNode *node, int level)
{
    if (node != NULL && level == 0)
    {
        if ((node-> left != NULL) && (node-> right != NULL))
            printf("%d(%d and %d)\n", node->data,node -> left -> data , node -> right -> data);
        else if ((node-> left == NULL) && (node-> right != NULL)) 
            printf("%d( NULL and %d)\n", node->data, node -> right -> data);
        else if ((node-> right == NULL) && (node-> left != NULL)) 
            printf("%d( %d and NULL)\n", node->data, node -> left -> data);
        else
            printf("%d\n", node->data);
        
    }   
    else if (node != NULL)
    {
        printLevel(node->left, level - 1);
        printLevel(node->right, level - 1);
    }
}

void printElements(struct BSTNode *node)
{
    int i;
    int levelCount = getLevelCount(node);
    for (i = 0; i < levelCount; i++)
    {
        printLevel(node, i);
        printf("-----------------------------\n");
    }
}

struct BSTNode *FindMaxRec(struct BSTNode* root)
{
    //basically we need to traverse till the extreme right of the BST where we dont find a further right node
    //if empty BST
    if (root == NULL)
        return NULL;
    //a node which doesnt have a right node will be the maximum node
    else if(root->right == NULL)
        return root;
    else 
        return FindMaxRec(root->right);
}

struct BSTNode *FindMinRec(struct BSTNode* root)
{
    //basically we need to traverse till the extreme left of the BST where we dont find a further left node
    //if empty BST
    if (root == NULL)
        return NULL;
    //a node which doesnt have a right node will be the minimum node
    else if(root -> left == NULL)
        return root;
    else 
        return FindMinRec(root->left);
}

struct BSTNode *FindMaxIter(struct BSTNode* root)
{
    //basically we need to traverse till the extreme right of the BST where we dont find a further right node
    //if empty BST
    if (root == NULL)
        return NULL;
    //a node which doesnt have a right node will be the maximum node
    else 
    {
        struct BSTNode* temp = root;
        while(temp -> right != NULL)
            temp = temp -> right;
        return temp;
    }
    
}


struct BSTNode *FindMinIter(struct BSTNode* root)
{
    //basically we need to traverse till the extreme left of the BST where we dont find a further left node
    //if empty BST
    if (root == NULL)
        return NULL;
    //a node which doesnt have a left node will be the minimum node
    else 
    {
        struct BSTNode* temp = root;
        while(temp -> left != NULL)
            temp = temp -> left;
        return temp;
    }
    
}

//IOP = InOrder Predecessor
struct BSTNode *FindIOP(struct BSTNode *root)
{
    //find the max element in the left tree becuase if some node gets deleted it will be the next one to take it over
    return FindMaxRec(root->left);
}

//IOS = InOrder Successor
struct BSTNode *FindIOS(struct BSTNode *root)
{
    //find the min element in the right tree 
    return FindMinRec(root->right);
}


struct BSTNode *FindNodeRec(int data, struct BSTNode* root)
{

    if (root == NULL)
        return NULL;
    else 
    {
        if (data < root->data)
            return FindNodeRec(data,root->left); 
        else if (data > root->data)
            return FindNodeRec(data,root->right); 
    }
    return root;
    
}

struct BSTNode *BSTdelete(int data, struct BSTNode* root)
{
    struct BSTNode *temp;
    if(root == NULL)
        printf("Element not there in tree\n");
    else if(data < root -> data)
        root->left = BSTdelete(data,root->left);
    else if(data > root -> data)
        root->right = BSTdelete(data,root->right);
    else
    {
        //Found element 
        if(root -> left && root -> right)
        {
            temp = FindMaxIter(root->left);
            root->data = temp->data;
            root->left = BSTdelete(root->data , root->left);
        }
        else
        {
            //one child or leaf node
            temp = root;
            if(root->left== NULL)
                root = root->right;
            if(root->right== NULL)
                root = root->left;
            free(temp);
        }
    }
    return root;
}

int main()
{
    struct BST *bst = (struct BST *)malloc(sizeof(struct BST));
    bst -> root = NULL;


    // BSTInsert_iter(5,bst);

    // BSTInsert_iter(2,bst);

    // BSTInsert_iter(7,bst);

    // BSTInsert_iter(6,bst);

    // BSTInsert_iter(10,bst);

    // BSTInsert_iter(8,bst);
    // printElements(bst->root);

    bst->root = BSTInsert_rec(4,bst->root);
    bst->root = BSTInsert_rec(2,bst->root);
    bst->root = BSTInsert_rec(8,bst->root);
    bst->root = BSTInsert_rec(5,bst->root);
    bst->root = BSTInsert_rec(10,bst->root);
    bst->root = BSTInsert_rec(7,bst->root);
    bst->root = BSTInsert_rec(6,bst->root);
    printElements(bst->root);

    // bst->root = BSTdelete(8,bst->root);
    // printElements(bst->root);

    struct BSTNode *temp;
    temp = FindMaxRec(bst->root->right->left);


    printf("%d\n",temp->data);

    return 0;
}    


    
