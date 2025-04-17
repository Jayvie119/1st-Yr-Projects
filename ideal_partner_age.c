#include <stdio.h>

// Function to check if the gender input is valid (1 for Male, 2 for Female)
int inputCheck(){
    int x;
    char c;
    do{ 
        // If input is not a valid integer, prompt user to enter a valid number
        if (scanf("%d", &x) != 1){
            printf("Error! Enter a number: ");
            while((c = getchar()) != '\n' && c != EOF);  // Clear the input buffer
        } 
        // If input is neither 1 nor 2, prompt user to select 1 for Male or 2 for Female
        else if(x != 1 && x != 2){
            printf("Error! 1 = MALE / 2 = FEMALE: ");
            while(getchar() != '\n');  // Clear the input buffer
        }            
    } while (x != 1 && x != 2);  // Continue prompting until valid input (1 or 2) is provided
    
    return x;  // Return the valid gender input (1 or 2)
}

// Function to check if the age input is valid (positive integer)
int ageCheck(){
    int age;
    char c;
    while (1) {
        // If input is a valid integer and positive, return the age
        if (scanf("%d", &age) == 1 && age > 0) {
            while ((c = getchar()) != '\n' && c != EOF);  // Clear the input buffer
            return age;
        }
        // If input is invalid (non-integer or negative), prompt user to enter a valid positive age
        printf("Error! Enter a valid positive age: ");
        while ((c = getchar()) != '\n' && c != EOF);  // Clear the input buffer
    }
}

// Main function where the program starts execution
int main()
{
    int age = 0;              // User's age
    int partnersAge = 0;      // Calculated ideal partner's age
    int gender;               // Gender of the user (1 for male, 2 for female)
    char name[80] = "";       // User's name

    // Display welcome message
    printf("Welcome to Plato!\n");

    // Ask for the user's name
    printf("Enter your name: ");
    scanf("%s", name);  // Read the name from user input (note: only first word will be captured)

    // Ask for the user's gender (1 for Male, 2 for Female)
    printf("Enter your gender (M=1 / F=2): ");
    gender = inputCheck();  // Call inputCheck function to validate gender input

    // Ask for the user's age
    printf("Enter your age: ");
    age = ageCheck();  // Call ageCheck function to validate age input

    // Calculate ideal partner's age based on Plato’s formula
    if (gender == 1) {
        // For male: age / 2 + 7
        partnersAge = age / 2 + 7;
        printf("%s, your ideal partner's age is: %d\n", name, partnersAge);
    } else if (gender == 2) {
        // For female: (age - 7) * 2
        partnersAge = (age - 7) * 2;
        printf("%s, your ideal partner's age is: %d\n", name, partnersAge);
    }

    return 0;  // End the program successfully
}
