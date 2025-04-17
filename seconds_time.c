#include <stdio.h>

int main()
{
    int Sec = 0;
    int Min = 0;
    int Hour = 0;
    char name[80] = "";

    printf("Enter your name: ");
    scanf("%s", name);
    printf("Enter seconds: ");
    scanf("%d", &Sec);

    Hour = Sec / 3600;          // Calculate hours
    Sec %= 3600;                // Get remaining seconds after hours calculation
    Min = Sec / 60;             // Calculate minutes
    Sec %= 60;                  // Get remaining seconds after minutes calculation

    // Display the converted time
    printf("Seconds: %d\n", Sec);
    printf("Minutes: %d\n", Min);
    printf("Hours: %d\n", Hour);

    printf("%s, the time is %.2d:%.2d:%.2d\n", name, Hour, Min, Sec);

    return 0;
}
