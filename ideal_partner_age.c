#include <stdio.h>

int main()
{
    int mansAge = 0;
    int partnersAge = 0;
    char name[80] = "";

    printf("Enter your name: ");
    scanf("%s", name);
    printf("Enter your age: ");
    scanf("%d", &mansAge);

    partnersAge = mansAge / 2 + 7;

    printf("%s, your ideal partners age is: %d \n", name, partnersAge);

    return 0;
}