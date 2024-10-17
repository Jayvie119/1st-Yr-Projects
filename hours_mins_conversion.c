#include <stdio.h>

int main()
{
    int hour = 0;
    int minutes = 0;
    int seconds = 0;
    char name[80] = "";

    printf("Enter your name: ");
    scanf("%s", name);
    printf("%s, enter how many hour/s you want to be converted to minute/s & second/s: ", name);
    scanf("%d", &hour);

    minutes = hour * 60;
    seconds = minutes * 60;

    printf("%s, %d Hours is equal to: \n", name, hour);
    printf("Minutes: %d \nSeconds: %d \n", minutes, seconds);


    return 0;
}