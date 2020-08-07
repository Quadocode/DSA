#include <stdio.h>

int main(){

    int rows = 3;
    int columns = 3;
    int arr[rows][columns];
        //then take the input of the first matrix
    for (int i=0;i<rows;i++){
        for (int j=0;j<columns;j++){
            printf("Enter element arr1[%d][%d]",i,j);
            scanf("%d",&arr[i][j]);
        
        }
    }
    int sum = 0;
    for(int i=0 ; i<rows ; i++)
    {
        if (i==0 || i==rows-1) //if that row is either first row or last row, then add all the ellements
        {
            for(int j=0 ; j< columns ; j++)
            {
                sum += arr[i][j];
            }
        }
        else{ // if inbetween rows add only the first and last elements
            sum += arr[i][0] + arr[i][columns-1];
        }
    }

    printf("sum of the border elements is %d\n",sum);
}
    

