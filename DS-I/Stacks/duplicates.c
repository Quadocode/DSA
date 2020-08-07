// Given a string S of lowercase letters, a duplicate removal consists of choosing two adjacent and equal letters, and removing them.

// We repeatedly make duplicate removals on S until we no longer can.

// Return the final string after all such duplicate removals have been made.  It is guaranteed the answer is unique.

 

// Example 1:

// Input: "abbaca"
// Output: "ca"
// Explanation: 
// For example, in "abbaca" we could remove "bb" since the letters are adjacent and equal, and this is the only possible move.  
// The result of this move is that the string is "aaca", of which only "aa" is possible, so the final string is "ca".



#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char * removeDuplicates(char * S){
    char *stack = (char*)malloc(10*sizeof(char));
    int top = -1;
    for(int i=0;i<strlen(S);i++)
    {
        if(S[i]==stack[top])
            stack[top--] = '\0';
        else
            stack[++top] = S[i];
            
        printf("Now top is %d\n",top);
        printf("top of stack is : %c\n",stack[top]);
        printf("---------------------------\n");
    }
    return stack;
}

int main(){
    printf("%s\n",removeDuplicates("abbaca"));
    return 0;
}