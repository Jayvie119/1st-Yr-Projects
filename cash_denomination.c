#include <stdio.h>

int main ()
{
    int cashOH = 0;  // cash on hand
    // Variables to store the count of each denomination
    int den_1, den_2, den_3, den_4, den_5, den_6, den_7, den_8 = 0;
    char name[80] = "";  // to store user's name

    // Prompt for user's name
    printf("Enter your name: ");
    scanf("%s", name);

    // Prompt for amount of money the user has
    printf("Enter the amount of cash on hand: ");
    scanf("%d", &cashOH);

    // Calculate number of 1000 peso bills
    den_1 = cashOH / 1000;
    cashOH %= 1000;  // update remaining cash

    // Calculate number of 500 peso bills
    den_2 = cashOH / 500;
    cashOH %= 500;

    // Calculate number of 100 peso bills
    den_3 = cashOH / 100;
    cashOH %= 100;

    // Calculate number of 50 peso bills
    den_4 = cashOH / 50;
    cashOH %= 50;

    // Calculate number of 20 peso bills
    den_5 = cashOH / 20;
    cashOH %= 20;

    // Calculate number of 10 peso coins
    den_6 = cashOH / 10;
    cashOH %= 10;

    // Calculate number of 5 peso coins
    den_7 = cashOH / 5;
    cashOH %= 5;

    // Calculate number of 1 peso coins
    den_8 = cashOH / 1;
    cashOH %= 1;

    // Print out the results
    printf("%s, here are your cash denominations:\n", name);
    printf("1000 - %d\n", den_1);
    printf(" 500 - %d\n", den_2);
    printf(" 100 - %d\n", den_3);
    printf("  50 - %d\n", den_4);
    printf("  20 - %d\n", den_5);
    printf("  10 - %d\n", den_6);
    printf("   5 - %d\n", den_7);
    printf("   1 - %d\n", den_8);

    return 0;
}
