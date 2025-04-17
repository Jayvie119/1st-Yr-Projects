#include <stdio.h>

// Ensures user input is a number greater than 1 (for row and column size)
int inputCheck(){
    int x, test;
    do{
        test = scanf("%d", &x);
        if(test != 1 || x <= 1){
            printf("Invalid Input! Enter a number greater than 1: ");
            while(getchar() != '\n'); // clear input buffer
        }
    } while(test != 1 || x <= 1);
    return x;
}

// Ensures input is an integer (used for array values)
int valueCheck(){
    int x, test;
    do{
        test = scanf("%d", &x);
        if(test != 1){
            printf("Invalid Input! Enter an integer value: ");
            while(getchar() != '\n'); // clear input buffer
        }
    } while(test != 1);
    return x;
}

// Ensures user input is either 1 or 0 (used for yes/no prompts)
int againCheck(){
    int x;
    do{
        scanf("%d", &x);
        if(x != 1 && x != 0){
            printf("Invalid Choice! Try Again? (1-Yes/0-No): ");
            while(getchar() != '\n'); // clear input buffer
        }
    } while(x != 1 && x != 0);
    return x;
}

// Selection Sort algorithm to sort 1D array
void selectionSort(int arr[], int size){
    int i, j;
    for(i = 0; i < size - 1; i++){
        int min_pos = i;
        for(j = i + 1; j < size; j++)
            if(arr[j] < arr[min_pos]) min_pos = j;

        // Swap elements if needed
        if(min_pos != i){
            int temp = arr[i];
            arr[i] = arr[min_pos];
            arr[min_pos] = temp;
        }
    }
}

int main(){
    int row, column;
    int again, again1;
    int i, j;

    printf("Welcome to my program!\n");

    do{
        // Input number of rows and columns
        printf("Enter a number of rows (greater than 1): ");
        row = inputCheck();
        printf("Enter a number of columns (greater than 1): ");
        column = inputCheck();

        int X[row][column];

        // Input array values
        for(i = 0; i < row; i++){
            for(j = 0; j < column; j++){
                printf("Enter a Value: ");
                X[i][j] = valueCheck();
            }
        }

        // Display unsorted array
        printf("\nUNSORTED ARRAY:\n");
        for(i = 0; i < row; i++){
            for(j = 0; j < column; j++){
                printf("%d\t", X[i][j]);
            }
            printf("\n");
        }

        // Flatten 2D array to 1D array
        int flat[row * column];
        int index = 0;
        for(i = 0; i < row; i++){
            for(j = 0; j < column; j++){
                flat[index++] = X[i][j];
            }
        }

        // Sort the flattened array
        selectionSort(flat, row * column);

        // Reassign sorted values back to 2D array
        index = 0;
        for(i = 0; i < row; i++){
            for(j = 0; j < column; j++){
                X[i][j] = flat[index++];
            }
        }

        // Display sorted array
        printf("\nSORTED ARRAY:\n");
        for(i = 0; i < row; i++){
            for(j = 0; j < column; j++){
                printf("%d\t", X[i][j]);
            }
            printf("\n");
        }

        // Ask user to run the program again
        printf("\nWould you like to try again? (1-Yes / 0-No): ");
        again = againCheck();
        if(again == 0){
            printf("Do you want to exit the program? (1-Yes / 0-No): ");
            again1 = againCheck();
            if(again1 == 1){
                printf("Thank you for using my program!\n");
                break;
            } else {
                again = 1; // continue program
            }
        }

    } while(again == 1);

    return 0;
}
