#include <stdio.h>

int main ()
{
    int cashOH = 0;
    int den_1, den_2, den_3, den_4, den_5, den_6, den_7, den_8 = 0;
    char name[80] = "";

    printf("Enter your name: ");
    scanf("%s", name);
    printf("Enter the amount of cash on hand: ");
    scanf("%d", &cashOH);

    den_1 = cashOH / 1000;
    cashOH % 1000;
    den_2 = cashOH / 500;
    cashOH %= 500;
    den_3 = cashOH / 100;
    cashOH %= 100;
    den_4 = cashOH / 50;
    cashOH %= 50;
    den_5 = cashOH / 20;
    cashOH %= 20;
    den_6 = cashOH / 10;
    cashOH %= 10;
    den_7 = cashOH / 5;
    cashOH %= 5;
    den_8 = cashOH / 1;
    cashOH %= 1;

    printf("%s, here are your cash denominations: \n", name);
    printf("1000 - %d\n 500 - %d\n 100 - %d\n 50 - %d\n 20 - %d\n 10 - %d\n 5 - %d\n 1- %d\n", 
    den_1, den_2, den_3, den_4, den_5, den_6, den_7, den_8);

    return 0;
}