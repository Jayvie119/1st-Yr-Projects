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
            rWage = hours * 10;
            printf("%s, your hourly wage is %d", name, rWage);
        } else if (hours >= 41) {
            rWage = hours * 10;
            oTime = hours - 40;
            tWage = rWage + (oTime * 1.5);
            printf("%s, you're an overtimer! Your wage is %d", name, tWage);
        }
    } else {
        printf("Invalid Input! Please try again.");
    }

    return 0;
}   