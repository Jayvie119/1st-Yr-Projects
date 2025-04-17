#include <stdio.h>

int main() 
{
    int bmonth = 0;
    int bday = 0;
    
    printf("What MONTH are you born? (1-12 | Jan-Dec) \n");
    scanf("%d", &bmonth);
    printf("What DAY are you born? \n");
    scanf("%d", &bday);

    // Determine Zodiac Sign based on month and day
    if (bmonth == 12 || bmonth == 1) {  // Capricorn (Goat)
        if ((bmonth == 12 && bday >= 22) || (bmonth == 1 && bday <= 19)) {
            printf("Capricorn (Goat)\n");
        }
    } else if (bmonth == 1 || bmonth == 2) { // Aquarius (Water Bearer)
        if ((bmonth == 1 && bday >= 20) || (bmonth == 2 && bday <= 18)) {
            printf("Aquarius (Water Bearer)\n");
        }
    } else if (bmonth == 3 || bmonth == 4) { // Aries (Ram)
        if ((bmonth == 3 && bday >= 21) || (bmonth == 4 && bday <= 19)) {
            printf("Aries (Ram)\n");
        }
    } else if (bmonth == 4 || bmonth == 5) { // Taurus (Bull)
        if ((bmonth == 4 && bday >= 20) || (bmonth == 5 && bday <= 20)) {
            printf("Taurus (Bull)\n");
        }
    } else if (bmonth == 5 || bmonth == 6) { // Gemini (Twins)
        if ((bmonth == 5 && bday >= 21) || (bmonth == 6 && bday <= 20)) {
            printf("Gemini (Twins)\n");
        }
    } else if (bmonth == 6 || bmonth == 7) { // Cancer (Crab)
        if ((bmonth == 6 && bday >= 21) || (bmonth == 7 && bday <= 22)) {
            printf("Cancer (Crab)\n");
        }
    } else if (bmonth == 7 || bmonth == 8) { // Leo (Lion)
        if ((bmonth == 7 && bday >= 23) || (bmonth == 8 && bday <= 22)) {
            printf("Leo (Lion)\n");
        }
    } else if (bmonth == 8 || bmonth == 9) { // Virgo (Virgin)
        if ((bmonth == 8 && bday >= 23) || (bmonth == 9 && bday <= 22)) {
            printf("Virgo (Virgin)\n");
        }
    } else if (bmonth == 9 || bmonth == 10) { // Libra (Balance)
        if ((bmonth == 9 && bday >= 23) || (bmonth == 10 && bday <= 22)) {
            printf("Libra (Balance)\n");
        }
    } else if (bmonth == 10 || bmonth == 11) { // Scorpio (Scorpion)
        if ((bmonth == 10 && bday >= 23) || (bmonth == 11 && bday <= 21)) {
            printf("Scorpio (Scorpion)\n");
        }
    } else if (bmonth == 11 || bmonth == 12) { // Sagittarius (Archer)
        if ((bmonth == 11 && bday >= 22) || (bmonth == 12 && bday <= 21)) {
            printf("Sagittarius (Archer)\n");
        }
    } else {
        printf("Invalid Input! Please try again.\n");
    }

    return 0;
}
