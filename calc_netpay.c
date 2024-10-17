#include<stdio.h>

int main()
{
    int hR = 281;
    int hW = 0;
    char name[80] ="";

    printf("Enter your name: ");
    scanf("%s", &name);
    printf("Enter your hour worked: ");
    scanf("%d", &hW);

    float gR = hR * hW;
    float wT = gR * .32;
    float nP = gR - wT;

    printf("%s" ",here are your: \n", name);
    printf("Hourly rate: " "%d \n", hR);
    printf("Hour worked: ""%d \n", hW);
    printf("Gross pay: " "%.2f \n", gR);
    printf("Withholding tax: " "%.2f \n", wT);
    printf("Net pay: " "%.2f \n", nP);


return 0;
}