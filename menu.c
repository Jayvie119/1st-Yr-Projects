#include <stdio.h>

int main() 
{
    // Variable initialization
    int prog; // Variable to store the user's menu selection
    int smiley = 1; // Constant for the "Smiley" option
    int plato = 2; // Constant for the "Plato" option
    int seconds = 3; // Constant for the "Seconds" option
    int exit = 4; // Constant for the "Exit" option
    int again; // Variable to determine whether the user wants to continue or exit

    // Start the program's menu loop
    do {
        // Display the menu options to the user
        printf("Menu Program:\n1. Smiley\n2. Plato\n3. Seconds\n4. Exit\n");
        scanf("%d", &prog); // Get the user's choice for the menu option
        
        // Handle the "Smiley" option
        if (prog == smiley) {
            do {
                // Declare variables for storing numbers and name
                int n1 = 0, n2 = 0, n3 = 0;
                int Sum = 0, Smiley = 0;
                char name[80] = "";

                printf("Welcome to Smiley!\n");
                // Get the user's name and three numbers
                printf("Please enter your name: ");
                scanf("%s", name);
                printf("Please enter the 1st number: ");
                scanf("%d", &n1);
                printf("Please enter the 2nd number: ");
                scanf("%d", &n2);
                printf("Please enter the 3rd number: ");
                scanf("%d", &n3);

                // Calculate the sum and then the "Smiley" value (double the sum)
                Sum = n1 + n2 + n3;
                Smiley = Sum * 2;

                // Output the result
                printf("Twice the sum of %s's numbers %d, %d, %d is %d :) :) :)\n", name, n1, n2, n3, Smiley);
                // Ask if the user wants to try again
                printf("Do you want to try again? (y=1/n=0)\n");
                scanf("%d", &again);
            } while (again == 1); // Repeat if the user chooses '1' (yes)
        }
        // Handle the "Plato" option
        else if (prog == plato) {
            do {
                // Declare variables for the user's age, ideal partner's age, and gender
                int age = 0, partnersAge = 0, gender;
                char name[80] = "";

                printf("Welcome to Plato!\n");
                // Get the user's name, gender (1 for male, 2 for female), and age
                printf("Enter your name: ");
                scanf("%s", name);
                printf("Enter your gender (M=1/F=2): ");
                scanf("%d", &gender);
                printf("Enter your age: ");
                scanf("%d", &age);

                // Calculate the ideal partner's age based on Plato's rule
                if (gender == 1) { // Male
                    partnersAge = age / 2 + 7; // Plato's rule for males
                    printf("%s, your ideal partner's age (based on Plato's rule) is: %d \n", name, partnersAge);
                } else if (gender == 2) { // Female
                    partnersAge = (age - 7) * 2; // Plato's rule for females
                    printf("%s, your ideal partner's age (based on Plato's rule) is: %d \n", name, partnersAge);
                } else { // Invalid gender input
                    printf("Invalid input! Please enter M=1 for Male or F=2 for Female.\n");
                }
                // Ask if the user wants to try again
                printf("Do you want to try again? (y=1/n=0)\n");
                scanf("%d", &again);
            } while (again == 1); // Repeat if the user chooses '1' (yes)
        }
        // Handle the "Seconds" option
        else if (prog == seconds) {
            do {
                // Declare variables for time calculation
                int Sec = 0, Min = 0, Hour = 0;
                char name[80] = "";

                printf("Welcome to Seconds!\n");
                // Get the user's name and the number of seconds
                printf("Enter your name: ");
                scanf("%s", name);
                printf("Enter seconds: ");
                scanf("%d", &Sec);

                // Convert seconds to hours, minutes, and seconds
                Hour = Sec / 3600; // Calculate hours
                Sec %= 3600; // Remaining seconds
                Min = Sec / 60; // Calculate minutes
                Sec %= 60; // Remaining seconds

                // Output the converted time
                printf("Seconds: %d\n", Sec);
                printf("Minutes: %d\n", Min);
                printf("Hours: %d\n", Hour);

                // Display the time in HH:MM:SS format
                printf("%s, the time is %.2d:%.2d:%.2d \n", name, Hour, Min, Sec);
                // Ask if the user wants to try again
                printf("Do you want to try again? (y=1/n=0)\n");
                scanf("%d", &again);
            } while (again == 1); // Repeat if the user chooses '1' (yes)
        }
        // Handle the "Exit" option
        else if (prog == exit) {
            // Ask if the user wants to exit the program
            printf("Do you want to exit the program? (y=1/n=0)\n");
            scanf("%d", &again);
            if (again == 1) // Exit if the user chooses '1' (yes)
                printf("Thank you for using our program!");
        }
        // Error handling if the user inputs an invalid menu option
        else {
            printf("Invalid Input! Please Try again!\n");
        }

    } while (again == 0); // Repeat the menu until the user chooses to exit (when again != 0)

    return 0; // Return 0 to indicate successful program execution
}
