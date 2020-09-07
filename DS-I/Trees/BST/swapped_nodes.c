
#include <stdio.h> 
#include <stdlib.h> 

struct BSTNode 
{ 
    int data; 
    struct BSTNode *left, *right; 
}; 
  
void swap( int* a, int* b ) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
} 
  
/* Helper function that allocates a new BSTNode with the 
   given data and NULL left and right pointers. */
struct BSTNode* newBSTNode(int data) 
{ 
    struct BSTNode* BSTNode = (struct BSTNode *)malloc(sizeof(struct BSTNode)); 
    BSTNode->data = data; 
    BSTNode->left = NULL; 
    BSTNode->right = NULL; 
    return(BSTNode); 
} 
  
// This function does inorder traversal to find out the two swapped BSTNodes. 
// It sets three pointers, first, middle and last.  If the swapped BSTNodes are 
// adjacent to each other, then first and middle contain the resultant BSTNodes 
// Else, first and last contain the resultant BSTNodes 
void correctBSTUtil( struct BSTNode* root, struct BSTNode** first, 
                     struct BSTNode** middle, struct BSTNode** last, 
                     struct BSTNode** prev ) 
{ 
    if( root ) 
    { 
        // Recur for the left subtree 
        correctBSTUtil( root->left, first, middle, last, prev ); 
  
        // If this BSTNode is smaller than the previous BSTNode, it's violating 
        // the BST rule. 
        if (*prev && root->data < (*prev)->data) 
        { 
            // If this is first violation, mark these two BSTNodes as 
            // 'first' and 'middle' 
            if ( !*first ) 
            { 
                *first = *prev; 
                *middle = root; 
            } 
  
            // If this is second violation, mark this BSTNode as last 
            else
                *last = root; 
        } 
  
        // Mark this BSTNode as previous 
        *prev = root; 
  
        // Recur for the right subtree 
        correctBSTUtil( root->right, first, middle, last, prev ); 
    } 
} 
  
// A function to fix a given BST where two BSTNodes are swapped.  This 
// function uses correctBSTUtil() to find out two BSTNodes and swaps the 
// BSTNodes to fix the BST 
void correctBST( struct BSTNode* root ) 
{ 
    // Initialize pointers needed for correctBSTUtil() 
    struct BSTNode *first, *middle, *last, *prev; 
    first = middle = last = prev = NULL; 
  
    // Set the poiters to find out two BSTNodes 
    correctBSTUtil( root, &first, &middle, &last, &prev ); 
  
    // Fix (or correct) the tree 
    if( first && last ) 
        swap( &(first->data), &(last->data) ); 
    else if( first && middle ) // Adjacent BSTNodes swapped 
        swap( &(first->data), &(middle->data) ); 
  
    // else BSTNodes have not been swapped, passed tree is really BST. 
} 

void printInorder(struct BSTNode* root) 
{ 
    if (root == NULL) 
        return; 
    printInorder(root->left); 
    printf("%d ", root->data); 
    printInorder(root->right); 
} 

int main() 
{ 
    /*   6 
        /  \ 
       10    2 
      / \   / \ 
     1   3 7  12 
     10 and 2 are swapped 
    */
  
    struct BSTNode *root = newBSTNode(6); 
    root->left        = newBSTNode(10); 
    root->right       = newBSTNode(2); 
    root->left->left  = newBSTNode(1); 
    root->left->right = newBSTNode(3); 
    root->right->right = newBSTNode(12); 
    root->right->left = newBSTNode(7); 
  
    printf("Inorder Traversal of the original tree \n"); 
    printInorder(root); 
  
    correctBST(root); 
  
    printf("\nInorder Traversal of the fixed tree \n"); 
    printInorder(root); 
    printf("\n");
  
    return 0; 
} 