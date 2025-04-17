#include <stdio.h>

int errorCheck() {
    int x, test;
    do {
        test = scanf("%d", &x);

        // Check for valid input
        if (test != 1) {
            printf("Invalid Input! Try Again\n");
            while (getchar() != '\n');  // Flush the buffer
        } else if (x < 1) {  // Ensuring x is a positive number
            printf("Invalid Input! Please enter a positive integer.\n");
            while (getchar() != '\n');
        }
    } while (test != 1 || x < 1);
    return x;
}

int valueCheck() {
    int x, test;
    do {
        test = scanf("%d", &x);

        // Check for valid input
        if (test != 1) {
            printf("Invalid Input! Try Again: ");
            while (getchar() != '\n');
        }
    } while (test != 1);
    return x;
}

int againCheck() {
    int x;
    do {
        printf("Enter 1 for Yes or 0 for No: ");
        scanf("%d", &x);

        // Check for valid choice
        if (x != 1 && x != 0) {
            printf("Invalid Choice! Try Again!\n");
            while (getchar() != '\n');  // Flush buffer
        }
    } while (x != 1 && x != 0);
    return x;
}

void bubbleSort(int arr[], int size) {
    int i, j;
    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap the values
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int row, column;
    int again, again1;
    int i, j;

    do {
        printf("Enter number of rows: ");
        row = errorCheck();
        printf("Enter number of columns: ");
        column = errorCheck();

        int X[row][column];  // Declare 2D array dynamically

        // Getting the elements of the array
        for (i = 0; i < row; i++) {
            for (j = 0; j < column; j++) {
                printf("X[%d][%d]: ", i, j);
                X[i][j] = valueCheck();
            }
        }

        // Print the unsorted 2D array
        printf("UNSORTED 2D ARRAY:\n");
        for (i = 0; i < row; i++) {
            for (j = 0; j < column; j++) {
                printf("%d\t", X[i][j]);
            }
            printf("\n");
        }

        // Flatten the 2D array for sorting
        int flat[row * column];
        int index = 0;
        for (i = 0; i < row; i++) {
            for (j = 0; j < column; j++) {
                flat[index++] = X[i][j];
            }
        }

        // Sort the flattened array
        bubbleSort(flat, row * column);

        // Fill the sorted values back into the 2D array
        index = 0;
        for (i = 0; i < row; i++) {
            for (j = 0; j < column; j++) {
                X[i][j] = flat[index++];
            }
        }

        // Print the sorted 2D array
        printf("SORTED 2D ARRAY:\n");
        for (i = 0; i < row; i++) {
            for (j = 0; j < column; j++) {
                printf("%d\t", X[i][j]);
            }
            printf("\n");
        }

        // Check if the user wants to try again
        printf("\nDo you want to try again? (1-Yes/0-No)\n");
        again = againCheck();
        if (again == 0) {
            // If user selects No, confirm their choice to exit
            printf("Are you sure you want to exit the program? (1-Yes/0-No)\n");
            again1 = againCheck();
            if (again1 == 1) {
                printf("Thank you for using my program!\n");
                break;
            } else {
                again = 1;
            }
        }
    } while (again == 1);
    
    return 0;
}
