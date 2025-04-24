#include <stdio.h>

// Function to ensure the user enters a positive integer
int inputCheck(){
    int x;
    char c;
    while(1){
        // Prompt the user to enter an integer
        printf("\nEnter an integer: ");
        // Check if the input is an integer and is greater than zero
        if(scanf("%d", &x)==1 && x>0){
            // Clear the input buffer (remove any remaining characters)
            while((c=getchar())!='\n' && c!= EOF);
            return x; // Return the valid integer input
        }
        // If invalid, display an error message
        printf("Error! Enter a valid integer.\n");
        // Clear the input buffer
        while((c=getchar())!='\n' && c!= EOF);
    }
}

// Function to ensure the user enters an integer
int valueCheck(){
    int x;
    char c;
    while(1){
        // Prompt the user to enter an integer
        printf("\nEnter an integer: ");
        // Check if the input is an integer (no additional conditions)
        if(scanf("%d", &x)==1){
            // Clear the input buffer
            while((c=getchar())!='\n' && c!= EOF);
            return x; // Return the valid integer input
        }
        // If invalid, display an error message
        printf("Error! Enter a valid integer.\n");
        // Clear the input buffer
        while((c=getchar())!='\n' && c!= EOF);
    }
}

// Function to ask the user if they want to retry (1 for Yes, 0 for No)
int againCheck(){
    int x;
    char c;
    while(1){
        // Ask if the user wants to try again
        printf("\nError! Try again? 1-Yes / 0-No: ");
        // Check if the input is either 1 or 0
        if(scanf("%d", &x)==1 && (x==0||x==1)){
            // Clear the input buffer
            while((c=getchar())!='\n' && c!= EOF);
            return x; // Return the user's choice (1 or 0)
        }
        // If invalid, display an error message
        printf("Error! Enter 1 for Yes or 0 for No.\n");
        // Clear the input buffer
        while((c=getchar())!='\n' && c!= EOF);
    }
}

// Main function to test the input-checking functions
int main(){
    int num, value, retry;

    // Testing inputCheck function
    printf("Testing Input Check: ");
    num = inputCheck();
    printf("You entered %d\n\n", num);

    // Testing valueCheck function
    printf("Testing value Check: ");
    value = valueCheck();
    printf("You entered %d\n\n", value);    

    // Testing againCheck function
    printf("Testing again Check: ");
    retry = againCheck();
    printf("You entered %d\n\n", retry);    

    return 0; // End of the program
}
