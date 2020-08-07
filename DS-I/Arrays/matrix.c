#include <stdio.h>

int main()
{
    int r1,c1,r2,c2; //define the rows and columns of the matrices
    
    printf("Enter r1,c1,r2,c2\n");
    scanf("%d %d %d %d",&r1,&c1,&r2,&c2); //scan the input roows and columns

    //till the columns of first matrix are not equal to the rows of the second , keep scanning for a fresh input
    while(c1!=r2){
        printf("Rows of first matrix should match the columns of the second matirx\nEnter r1,c1,r2,c2");
        scanf("%d %d %d %d",&r1,&c1,&r2,&c2);
    }

    int arr1[r1][c1],arr2[r2][c2],product[r1][c2]; //declare the result and the arrays
    
    //then take the input of the first matrix
    for (int i=0;i<r1;i++){
        for (int j=0;j<c1;j++){
            printf("Enter element arr1[%d][%d]",i,j);
            scanf("%d",&arr1[i][j]);
        
        }
    }

    //then take the input of the second matrix
    for (int i=0;i<r2;i++){
        for (int j=0;j<c2;j++){
            printf("Enter element arr2[%d][%d]",i,j);
            scanf("%d",&arr2[i][j]);
        
        }
    }

    //then initialize the product matrix with zeros
    for (int i=0;i<r1;i++){
        for (int j=0;j<c2;j++){
            product[i][j] = 0;
        }
    }
    
    for (int i=0;i<r1;i++){ //for each row of first matrix multiply the
        for (int j=0;j<c2;j++){ //each column of second matrix
            for (int k=0 ; k<c1 ; k++){ // for each element in the row which ranges from 0 -> c1
                product[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }


    //print in a matrix form
    for (int i=0;i<r1;i++){
        for (int j=0;j<c2;j++){
            printf("%d  ",product[i][j]);
        }
        printf("\n");
    }
    
    
    

    return 0;
}



// #include <stdio.h>
// void enterData(int first[][10], int second[][10], int r1, int c1, int r2, int c2);
// void multiplyMatrices(int first[][10], int second[][10], int multResult[][10], int r1, int c1, int r2, int c2);
// void display(int mult[][10], int r1, int c2);

// int main() {
//     int first[10][10], second[10][10], mult[10][10], r1, c1, r2, c2;
//     printf("Enter rows and column for the first matrix: ");
//     scanf("%d %d", &r1, &c1);
//     printf("Enter rows and column for the second matrix: ");
//     scanf("%d %d", &r2, &c2);

//     // Taking input until columns of the first matrix is equal to the rows of the second matrix
//     while (c1 != r2) {
//         printf("Error! Enter rows and columns again.\n");
//         printf("Enter rows and columns for the first matrix: ");
//         scanf("%d%d", &r1, &c1);
//         printf("Enter rows and columns for the second matrix: ");
//         scanf("%d%d", &r2, &c2);
//     }

//     // Function to take matrices data
//     enterData(first, second, r1, c1, r2, c2);

//     // Function to multiply two matrices.
//     multiplyMatrices(first, second, mult, r1, c1, r2, c2);

//     // Function to display resultant matrix after multiplication.
//     display(mult, r1, c2);

//     return 0;
// }

// void enterData(int first[][10], int second[][10], int r1, int c1, int r2, int c2) {
//     printf("\nEnter elements of matrix 1:\n");

//     for (int i = 0; i < r1; ++i) {
//         for (int j = 0; j < c1; ++j) {
//             printf("Enter a%d%d: ", i + 1, j + 1);
//             scanf("%d", &first[i][j]);
//         }
//     }
//     printf("\nEnter elements of matrix 2:\n");

//     for (int i = 0; i < r2; ++i) {
//         for (int j = 0; j < c2; ++j) {
//             printf("Enter b%d%d: ", i + 1, j + 1);
//             scanf("%d", &second[i][j]);
//         }
//     }
// }

// void multiplyMatrices(int first[][10], int second[][10], int mult[][10], int r1, int c1, int r2, int c2) {

//     // Initializing elements of matrix mult to 0.
//     for (int i = 0; i < r1; ++i) {
//         for (int j = 0; j < c2; ++j) {
//             mult[i][j] = 0;
//         }
//     }

//     // Multiplying first and second matrices and storing in mult.
//     for (int i = 0; i < r1; ++i) {
//         for (int j = 0; j < c2; ++j) {
//             for (int k = 0; k < c1; ++k) {
//                 mult[i][j] += first[i][k] * second[k][j];
//             }
//         }
//     }
// }

// void display(int mult[][10], int r1, int c2) {

//     printf("\nOutput Matrix:\n");
//     for (int i = 0; i < r1; ++i) {
//         for (int j = 0; j < c2; ++j) {
//             printf("%d  ", mult[i][j]);
//         }
//         printf("\n");
//     }
// }
