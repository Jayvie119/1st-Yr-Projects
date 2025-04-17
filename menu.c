#include <stdio.h>

int main() 
{
    int prog;
    int smiley = 1;
    int plato = 2;
    int seconds = 3;
    int exit = 4;
    int again;
    
    do {
        printf("Menu Program:\n1. Smiley\n2. Plato\n3. Seconds\n4. Exit\n");
        scanf("%d", &prog);
        
        if (prog == smiley) {
            do {
                int n1 = 0, n2 = 0, n3 = 0;
                int Sum = 0, Smiley = 0;
                char name[80] = "";

                printf("Welcome to Smiley!\n");
                printf("Please enter your name: ");
                scanf("%s", name);
                printf("Please enter the 1st number: ");
                scanf("%d", &n1);
                printf("Please enter the 2nd number: ");
                scanf("%d", &n2);
                printf("Please enter the 3rd number: ");
                scanf("%d", &n3);

                Sum = n1 + n2 + n3;
                Smiley = Sum * 2;

                printf("Twice the sum of %s's numbers %d, %d, %d is %d :) :) :)\n", name, n1, n2, n3, Smiley);
                printf("Do you want to try again? (y=1/n=0)\n");
                scanf("%d", &again);
            } while (again == 1);
        } else if (prog == plato) {
            do {
                int age = 0, partnersAge = 0, gender;
                char name[80] = "";

                printf("Welcome to Plato!\n");
                printf("Enter your name: ");
                scanf("%s", name);
                printf("Enter your gender (M=1/F=2): ");
                scanf("%d", &gender);
                printf("Enter your age: ");
                scanf("%d", &age);

                // Checking gender and calculating the ideal partner's age
                if (gender == 1) { // Male
                    partnersAge = age / 2 + 7;
                    printf("%s, your ideal partner's age (based on Plato's rule) is: %d \n", name, partnersAge);
                    printf("Since you are male, Plato's rule suggests that your partner should be at least %d years old.\n", partnersAge);
                } else if (gender == 2) { // Female
                    partnersAge = (age - 7) * 2;
                    printf("%s, your ideal partner's age (based on Plato's rule) is: %d \n", name, partnersAge);
                } else { // Invalid input
                    printf("Invalid input! Please enter M=1 for Male or F=2 for Female.\n");
                }
                printf("Do you want to try again? (y=1/n=0)\n");
                scanf("%d", &again);
            } while (again == 1);
        } else if (prog == seconds) {
            do {
                int Sec = 0, Min = 0, Hour = 0;
                char name[80] = "";

                printf("Welcome to Seconds!\n");
                printf("Enter your name: ");
                scanf("%s", name);
                printf("Enter seconds: ");
                scanf("%d", &Sec);

                Hour = Sec / 3600;
                Sec %= 3600;
                Min = Sec / 60;
                Sec %= 60;
                
                printf("Seconds: %d\n", Sec);
                printf("Minutes: %d\n", Min);
                printf("Hours: %d\n", Hour);

                printf("%s, the time is %.2d:%.2d:%.2d \n", name, Hour, Min, Sec);
                printf("Do you want to try again? (y=1/n=0)\n");
                scanf("%d", &again);
            } while (again == 1);
        } else if (prog == exit) {
            printf("Do you want to exit the program? (y=1/n=0)\n");
            scanf("%d", &again);
            if (again == 1)
                printf("Thank you for using our program!");
        } else {
            printf("Invalid Input! Please Try again!\n"); // Error Handler!!!
        }

    } while (again == 0);
    
    return 0;
}
