#include<stdio.h>

int main()
{
    // Variable declaration
    int hR = 0;           // Hourly rate
    int hW = 0;           // Hours worked
    char name[80] = "";   // Character array to store the user's name

    // Prompt user to enter their name
    printf("Enter your name: ");
    scanf("%s", &name);  // Read name (note: only reads one word)

    // Prompt user to enter hours worked
    printf("Enter your hour worked: ");
    scanf("%d", &hW);  // Read hours worked

    // Prompt user to enter hourly rate
    printf("Enter your hourly rate: ");
    scanf("%d", &hR);  // Read hourly rate

    // Compute gross pay, withholding tax, and net pay
    float gR = hR * hW;     // Gross pay = hourly rate * hours worked
    float wT = gR * 0.32;   // Withholding tax = 32% of gross pay
    float nP = gR - wT;     // Net pay = gross pay - withholding tax

    // Display the results
    printf("%s, here are your: \n", name);         // Display user's name
    printf("Hourly rate: %d \n", hR);              // Show hourly rate
    printf("Hour worked: %d \n", hW);              // Show hours worked
    printf("Gross pay: %.2f \n", gR);              // Show gross pay
    printf("Withholding tax: %.2f \n", wT);        // Show withholding tax
    printf("Net pay: %.2f \n", nP);                // Show net pay


return 0;
}
