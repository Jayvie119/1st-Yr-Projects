#include <stdio.h>

// Function to validate user input for integers greater than or equal to 1
int inputCheck(){
    int x, test; 
    do{
        test = scanf("%d", &x);

        // If input is not a valid integer, ask the user to re-enter
        if(test != 1){
            printf("Invalid Input! Enter a number: ");
            while(getchar() != '\n'); // Flush the input buffer
        } 
        // If the number is less than 1, prompt again
        else if(x < 1){
            printf("Invalid Input! Please Try Again: ");
            while(getchar() != '\n'); // Flush the input buffer
        }
    } while(test != 1); // Continue prompting until valid input
    return x;
}

// Function to validate user input for any integer value
int valueCheck(){
    int x, test;
    do{
        test = scanf("%d", &x);

        // If input is not a valid integer, ask the user to re-enter
        if(test != 1){
            printf("Invalid Input! Please Try Again: ");
            while(getchar() != '\n'); // Flush the input buffer
        }
    } while(test != 1); // Continue prompting until valid input
    return x; // Return the valid integer input
}

// Function to validate user input for 1 (Yes) or 0 (No)
int againCheck(){
    int x;
    do{
        if(scanf("%d", &x) != 1){ // Check if input is a valid integer
            printf("Invalid input! Please enter 1 or 0: ");
            while(getchar() != '\n'); // Flush the input buffer
        } else if(x != 1 && x != 0){ // Check if input is either 1 or 0
            printf("Invalid Choice! (1-Yes/0-No): ");
        }
    } while(x != 1 && x != 0); // Keep asking until valid input (1 or 0)
    return x; // Return the valid choice (1 or 0)
}

// Function to perform insertion sort on a 1D array
void insertionSort(int arr[], int size){
    int i;
    for(i = 1; i < size; i++){
        int key = arr[i];
        int j = i - 1;

        // Move elements of arr[0..i-1] that are greater than key
        while(j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key; // Insert the key at the correct position
    }
}

int main(){
    int row, column;
    int again, again1;
    int i, j;

    printf("Welcome to my program!\n");

    do{
        printf("Enter number of rows: ");
        row = inputCheck(); // Get number of rows
        printf("Enter number of column: ");
        column = inputCheck(); // Get number of columns

        int X[row][column]; // Declare a 2D array with user-defined dimensions

        // Get values for the 2D array from the user
        for(i = 0; i < row; i++){
            for(j = 0; j < column; j++){
                printf("Enter a Value: ");
                X[i][j] = inputCheck(); // Get a value for each cell in the 2D array
            }
        }

        // Print the unsorted 2D array
        printf("\nUNSORTED ARRAY:\n");
        for(i = 0; i < row; i++){
            for(j = 0; j < column; j++){
                printf("%d\t", X[i][j]);
            }
            printf("\n");
        }

        // Flatten the 2D array into a 1D array
        int flat[row * column];
        int index = 0;

        for(i = 0; i < row; i++){
            for(j = 0; j < column; j++){
                flat[index++] = X[i][j]; // Assign values from 2D array to 1D array
            }
        }

        // Sort the 1D array using insertion sort
        insertionSort(flat, row * column);

        // Flattened, sorted 1D array to 2D array conversion
        index = 0;
        for(i = 0; i < row; i++){
            for(j = 0; j < column; j++){
                X[i][j] = flat[index++]; // Assign sorted values back to the 2D array
            }
        }

        // Print the sorted 2D array
        printf("\nSORTED ARRAY:\n");
        for(i = 0; i < row; i++){
            for(j = 0; j < column; j++){
                printf("%d\t", X[i][j]); // Print each element of the sorted 2D array
            }
            printf("\n");
        }

        // Ask the user if they want to try again
        printf("Would you like to try again?\n(1-Yes/0-No): ");
        again = againCheck(); // Validate Yes/No choice
        if(again == 0){
            // If they don't want to try again, ask for confirmation
            printf("Are you sure you want to exit my program?\n(1-Yes/0-No): ");
            again1 = againCheck(); // Validate exit confirmation
            if(again1 == 1){
                printf("Thank you for using my program!\n");
                break; // Exit the program
            } else {
                again = 1; // Reset the choice to try again
            }
        }

    } while(again == 1); // Keep repeating the process if user chooses to try again
    return 0;
}
