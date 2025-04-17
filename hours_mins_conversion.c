#include <stdio.h>

int main()
{
    int hour = 0;         // user input in hours
    int minutes = 0;      // converted minutes
    int seconds = 0;      // converted seconds
    char name[80] = "";   // user's name

    // Ask for the user's name
    printf("Enter your name: ");
    scanf("%s", name);

    // Ask how many hours the user wants to convert
    printf("%s, enter how many hour/s you want to be converted to minute/s & second/s: ", name);
    scanf("%d", &hour);

    // Perform conversions
    minutes = hour * 60;       // 1 hour = 60 minutes
    seconds = minutes * 60;    // 1 minute = 60 seconds, so 1 hour = 3600 seconds

    // Display the result
    printf("%s, %d hour/s is equal to:\n", name, hour);
    printf("Minutes: %d\n", minutes);
    printf("Seconds: %d\n", seconds);

    return 0;
}
