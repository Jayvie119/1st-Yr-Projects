#include <stdio.h>

int main()
{
    int D = 0;
    int yr= 0;
    int wk= 0;
    int d = 0;

    printf("Enter days: ");
    scanf("%d", & D);
    
    yr = D/365;
    D %= 365;
    wk = D/7;
    D %= 7;
    d = D/1;
    D %= 1;

    printf("%d days = %d year/s, %d week/s, and %d day/s", D, yr, wk, d);
}