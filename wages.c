#include <stdio.h>

int main () 
{
    int hours;
    int rWage;
    int tWage;
    int oTime;
    char name[80];

    printf("Please enter your name: ");
    scanf("%s", name);

    printf("How many hours have you worked in a week: ");
    scanf("%d", &hours);

    if (hours >= 0) {
        if (hours <= 40) {
            // Regular wage for up to 40 hours
            rWage = hours * 10;
            printf("%s, your weekly wage for %d hours is %d.\n", name, hours, rWage);
        } else {
            // Regular wage for the first 40 hours
            rWage = 40 * 10;
            // Overtime calculation for hours beyond 40
            oTime = hours - 40;
            tWage = rWage + (oTime * 15);  // Overtime wage at 1.5x the regular rate
            printf("%s, you're an overtimer! Your total wage for %d hours is %d.\n", name, hours, tWage);
        }
    } else {
        printf("Invalid Input! Please try again.\n");
    }

    return 0;
}
