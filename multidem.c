#include <stdio.h> 

int main() {
    int r = 2;
    int c = 3;
    int X[r][c];
    int found = 0;

    printf("Please Input 6 Values.\n");

    // Get inputs for the 2d array
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf("X[%d][%d]: ", i, j);
            if (scanf("%d", &X[i][j]) != 1) {
                printf("Invalid Input!\n");
                return 1;
            }
        }
    }

    int key;
    printf("Enter Desired Value: ");
    if (scanf("%d", &key) != 1) {
        printf("Invalid Input\n");
        return 1;
    }

    for (int i = 0; i < r; i++) { // loop through rows
        for (int j = 0; j < c; j++) { // loop through columns
            if (X[i][j] == key) {
                printf("Existing Value!\nIndex: X[%d][%d]\n", i, j);
                found = 1;
                break;
            }
        }
        if (found) break; // Break outer loop if value is found
    }

    if (found == 0) {
        printf("Value Not Found!\n");
    }

    return 0;
}
