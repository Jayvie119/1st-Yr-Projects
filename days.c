#include <stdio.h>

int main()
{
    int D = 0;  // Total days
    int yr = 0; // Number of years
    int wk = 0; // Number of weeks
    int d = 0;  // Remaining days
    int originalD; // To store the original value of days for output

    printf("Enter days: ");
    scanf("%d", &D);

    originalD = D;  // Save the original value of days

    // Calculate years
    yr = D / 365;
    D %= 365;

    // Calculate weeks
    wk = D / 7;
    D %= 7;

    // Remaining days
    d = D;

    // Display the result
    printf("%d days = %d year/s, %d week/s, and %d day/s\n", originalD, yr, wk, d);

    return 0;
}
