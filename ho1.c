#include <stdio.h>

// Validates input and ensures the user enters a number
int valueCheck(){
    int x, test;
    do {
        test = scanf("%d", &x);
        if (test != 1) {
            printf("Error! Enter a Number: ");
            while (getchar() != '\n'); // Clear input buffer
        }
    } while (test != 1);
    return x;
}

// Asks the user if they want to try again; only accepts 1 (yes) or 0 (no)
int againCheck(){
    int x;
    char c;
    do {
        if (scanf("%d", &x) != 1) {
            printf("Error! Try again? 1-Yes/0-No: ");
            while ((c = getchar()) != '\n' && c != EOF); // Clear input buffer
        } else if (x != 1 && x != 0) {
            printf("Error! Try again? 1-Yes/0-No: ");
            while (getchar() != '\n');
        }
    } while (x != 1 && x != 0);
    return x;
}

// Searches for a value in the primary diagonal (top-left to bottom-right)
void diagonalSearch(int array[3][3], int dv){
    int i, j = 0;
    for (i = 0; i < 3; i++) {
        if (array[i][i] == dv) {
            printf("Value %d found at row %d column %d.\n", dv, i, i);
            j++;
        }
    }
    if (j == 0) {
        printf("num not in diagonal.\n");
    }
}

// Searches for a value in the secondary diagonal (top-right to bottom-left)
void diagSecSearch(int array[3][3], int key){
    int i, j = 0;
    int row = 3;

    for (i = 0; i < 3; i++) {
        if (array[i][row - 1 - i] == key) {
            printf("Value %d found at row %d column %d.\n", key, i, row - 1 - i);
            j++;
        }
    }
    if (j == 0) {
        printf("num not in diagonal.\n");
    }
}

// Finds the maximum element in the 3x3 array
void maximumSearch(int array[3][3]){
    int i, j;
    int max = array[0][0];
    int maxRow = 0, maxCol = 0;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (array[i][j] > max) {
                max = array[i][j];
                maxRow = i;
                maxCol = j;
            }
        }
    }
    printf("Maximum element at Row: %d, Column: %d - %d.\n", maxRow, maxCol, max);
}

// Finds and displays all values divisible by 3
void div3Search(int array[3][3]){
    int i, j;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (array[i][j] % 3 == 0) {
                printf("Value: %d, Row: %d, Column: %d\n", array[i][j], i, j);
            }
        }
    }
}

// Finds and displays all even values
void evenSearch(int array[3][3]){
    int i, j;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (array[i][j] % 2 == 0) {
                printf("Value: %d, Row: %d, Column: %d\n", array[i][j], i, j);
            }
        }
    }
}

// Calculates the sum of all values located on the border of the 3x3 array
void borderSum(int array[3][3]){
    int sumtotal = 0;
    int i, j;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (i == 0 || i == 2 || j == 0 || j == 2) {
                sumtotal += array[i][j];
            }
        }
    }
    printf("Total Border Sum: %d\n", sumtotal);
}

// Calculates the sum of the corner values
void cornerSum(int array[3][3]){
    int cornersum = 0;
    int low = 0, high = 2;
    int i, j;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if ((i == low || i == high) && (j == low || j == high)) {
                cornersum += array[i][j];
            }
        }
    }
    printf("The sum of the corners is %d.\n", cornersum);
}

// Main program driver
int main(){
    int arr[3][3];
    int again, again1;
    int i, j;
    int key;
    int choice;

    printf("Welcome to my program!\n");

    do {
        // Input array values
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                printf("Enter value for Row: %d Column: %d : ", i, j);
                arr[i][j] = valueCheck();
            }
        }

        // Display array
        printf("\nARRAY:\n");
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                printf("%d\t", arr[i][j]);
            }
            printf("\n");
        }

        do {
            // Menu of operations
            printf("\nWhat would you like to do?\n");
            printf("1. Search value in primary diagonal\n");
            printf("2. Search value in secondary diagonal\n");
            printf("3. Find maximum value\n");
            printf("4. Show all values divisible by 3\n");
            printf("5. Show all even values\n");
            printf("6. Sum of border values\n");
            printf("7. Sum of corner values\n");
            printf("Enter your choice (1-7): ");
            choice = valueCheck();

            // Perform operation
            switch (choice) {
                case 1:
                    printf("Enter value to be searched in primary diagonal: ");
                    key = valueCheck();
                    diagonalSearch(arr, key);
                    break;
                case 2:
                    printf("Enter value to be searched in secondary diagonal: ");
                    key = valueCheck();
                    diagSecSearch(arr, key);
                    break;
                case 3:
                    maximumSearch(arr);
                    break;
                case 4:
                    div3Search(arr);
                    break;
                case 5:
                    evenSearch(arr);
                    break;
                case 6:
                    borderSum(arr);
                    break;
                case 7:
                    cornerSum(arr);
                    break;
                default:
                    printf("Invalid choice. Please enter a number between 1 and 7.\n");
                    break;
            }

            // Ask if the user wants to do another operation on the same array
            printf("\nWould you like to perform another operation on the same array? 1-Yes/0-No: ");
            again = againCheck();

        } while (again == 1);

        // Ask if the user wants to input a new array
        printf("Do you want to enter a new array? 1-Yes/0-No: ");
        again1 = againCheck();

        if (again1 == 0) {
            printf("Thank you for using my program!\n");
            break;
        }

    } while (1);

    return 0;
}
