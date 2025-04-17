#include <stdio.h>

int main() 
{
    int bmonth = 0;
    int bday = 0;
    
    

    printf("What MONTH are you born? (1-12 | Jan-Dec) \n");
    scanf("%d", &bmonth);
    printf("What DAY are you born? \n");
    scanf("%d", &bday);


    if (bmonth == 12 || bmonth == 1){ // Goat
        if (bday >= 22 || bday <= 19){
            printf("Goat");
       }
    } else if (bmonth == 1 || bmonth == 2){// Water Bearer
        if (bday >= 20 || bday <= 18){
            printf("Water Bearer");
        }
    } else if (bmonth == 3 || bmonth == 4){// Ram
        if (bday >= 21 || bday <= 19){
            printf("Ram");
        }
    } else if (bmonth == 4 || bmonth == 5){ // Bull
        if (bday >= 20 || bday <= 20){
            printf("Bull");
        }
    } else if (bmonth == 5 || bmonth == 6){ // Twins
        if (bday >= 21 || bday <= 21){
            printf("Twins");
        }
    } else if (bmonth == 6 || bmonth == 7) {// Crab
        if (bday >= 22 || bday <= 22){
            printf("Crab");
        }
    } else if (bmonth == 7 || bmonth == 8){ // Lion
        if (bday >= 23 || bday <= 22){
            printf("Lion");
        }
    } else if (bmonth == 8 || bmonth == 9){ // Virgin
        if (bday >= 23 || bday <= 22){
            printf("Virgin");
        }
    } else if (bmonth == 9 || bmonth == 10){ // Balance
        if (bday >= 23 || bday <= 23){
            printf("Balance");
        }
    } else if (bmonth == 10 || bmonth == 11){ // Scorpion
        if (bday >= 24 || bday <= 21){
            printf("Scorpion");
        }
    } else if (bmonth == 11 || bmonth == 12){ // Archer
        if (bday >= 22 || bday <= 21){
            printf("Archer");
        }
    } else //(bmonth >= 12 && bday >= 31);//
        printf("Invalid Input! Pls Try Again");
    

    return 0;
}