#include <stdio.h>

int main()
{
    int Sec = 0;
    int Min = 0;
    int Hour = 0;
    char name[80]="";

    printf("Enter your name: ");
    scanf("%s", name);
    printf("Enter seconds: ");
    scanf("%d", &Sec);

    Hour = Sec/3600;
    Sec %= 3600; // need %=
    Min = Sec/60;
    Sec %+60;
    

    printf("Seconds: %d\n", Sec);
    printf("Minutes: %d\n", Min);
    printf("Hours: %d\n", Hour);

    printf("%s, the time is %.2d:%.2d:%.2d", name, Hour, Min, Sec);



    



}