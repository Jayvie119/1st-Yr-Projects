#include <stdio.h>

int main () 
{
    int n1 = 0;
    int n2 = 0;
    int n3 = 0;
    int Sum = 0;
    int Smiley = 0;
    char name[80] = "";

    printf("Please enter your name: ");
    scanf("%s", name);
    printf("Please enter the 1st number: ");
    scanf("%d", &n1);
    printf("Please enter the 2nd number: ");
    scanf("%d", &n2);
    printf("Please enter the 3rd number: ");
    scanf("%d", &n3);

    Sum = n1 + n2 + n3;
    Smiley = Sum * 2;

    printf("Twice the sum of %s's numbers %d, %d, %d is %d :) :) :)", name, n1, n2, n3, Smiley);

}