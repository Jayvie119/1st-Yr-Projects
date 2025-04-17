#include <stdio.h>
#include <string.h>
#include <ctype.h>

int errorHandler (char word[]){
    int i;
    for (i = 0; word[i] != '\0';i++ ){
        if(isdigit(word[i])) { // checks for numbers present in the input of the user
            return 1; // return true 
        }
        if(!isalnum(word[i]) && word[i] != ' '){ // checks for special characters except whitespace
            return 1; // return true
        }
    }
    return 0; // user input doesn't have errors.
}

int error(char first_word[], char second_word[]){ // checks if there are error in user input, will raise an error message if true.
    if (errorHandler(first_word) || errorHandler(second_word)){ 
        printf("Error: Words should not contain numbers or special characters.\nPlease try again.\n");
    }
}

int checkAnagrams(char first_word[], char second_word[]){
    int i;
    int fwCount[26] = {0}; //array to count occurences of the each letters in the first words
    int swCount[26] = {0}; //it corresponds to the 26 letters of the alphabet(a=0, b=1, c=3...)
    int fwLen = 0, swLen = 0; // to track the numbers of each alphabet characters in word 1 and 2. ()

    // counts the occurences of letters in the  first word
    for(i = 0; first_word[i] != '\0'; i++) {
        if (isalpha(first_word[i])){
            fwCount[tolower(first_word[i]) - 'a']++; //increments the count for letters (case insensitive)
            fwLen++; // increments the letter count
        } 
    }
    for(i = 0; second_word[i] != '\0'; i++) {
        if (isalpha(second_word[i])) {
            swCount[tolower(second_word[i]) - 'a']++; //to lower capitalized letter from input of user
            swLen++;
        }
    }

    if (fwLen != swLen) { // compares the length of word 1 and 2 of user
        return 0;  // return false = not anagrams.
    }

    for (i=0; i<26; i++) { 
        if (fwCount[i] != swCount[i]) { // compares the occurence of letters of first word to second word
            return 0; // return false = not anagrams.
        }
    }

    return 1; // words are anagrams
}

int tryAgain(){ //try again program
    int sure;
    int choice;

    do{
        printf("Would you like to try again?\n(0 - yes / 1 - no): ");
        if(scanf("%d", &choice) != 1){
            printf("\nInvalid input! Please Try Again!.\n");
            while (getchar() != '\n');
            continue;
    }
    if (choice == 1){
        do{
            printf("Do you want to exit the program?\n(0 - yes / 1 - no): ");
            if(scanf("%d", &sure) !=1){
                printf("\nInvalid input! Please Try Again!.\n");
                while (getchar() != '\n');
                continue;
            }
            if(sure == 0){
                printf("Thank you for using our program!");
                return 1;
            } else if (sure ==1){
                return 0;
            } else {
                printf("\nInvalid Input, try again.\n");
            }
        } while (sure != 1 || sure != 0);
    } else if (choice == 0){
        choice =0;
        return choice;
    } else {
        printf("\nInvalid Input, try again.\n");
    }
    }while(choice != 0 && choice != 1);

    return choice;
}

char verifyAnagram(char name[], char first_word[], char second_word[]){
    if (checkAnagrams(first_word, second_word)){
        printf("%s, the words %s and %s ARE Anagrams!\n", name, first_word, second_word);
    } else {
        printf("%s, the words %s and %s ARE NOT Anagrams.\n", name, first_word, second_word);
    }
}

int main()
{
    char first_word[80], second_word[80];
    char name[80];
    int choice;

    //INPUTS
    do{    
        printf("Welcome to Anagram Checker!\nPlease enter your name: ");
        scanf("%s", &name);
        getchar();// so printf wont concatinate.

        do{
            printf("%s, enter the first word/phrase: ", name);
            fgets(first_word, sizeof(first_word), stdin); //fgets to get the whole input of user for first word
            first_word  [strcspn(first_word, "\n")] = '\0'; // finds \n input and replaces with in fgets if there are any. nothing happens if theres none.

            printf("Enter the second word/phrase: ");
            fgets(second_word, sizeof(second_word), stdin); //fgets to get the whole input of user for first word
            second_word[strcspn(second_word, "\n")] = '\0';
            
            //OUTPUTS
            error(first_word, second_word); //checks error using errorHandler function, raises an error if there are.
        }while(errorHandler(first_word) || errorHandler(second_word));

            verifyAnagram(name, first_word, second_word); //using anagramChecker, it outputs whether the 2 inputs are anagram or not.
        // Try again
        choice = tryAgain();// try again prompt.
    }while (choice == 0);

    return 0;   
}