#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to check if a word contains numbers or special characters
int errorHandler (char word[]){
    int i;
    for (i = 0; word[i] != '\0';i++ ){
        if(isdigit(word[i])) {  // checks for numbers in the word
            return 1;  // returns 1 (true) if a number is found
        }
        if(!isalnum(word[i]) && word[i] != ' '){  // checks for special characters (excluding spaces)
            return 1;  // returns 1 (true) if a special character is found
        }
    }
    return 0;  // returns 0 (false) if no errors are found in the word
}

// Function to check both words for errors and print an error message if any are found
int error(char first_word[], char second_word[]){
    if (errorHandler(first_word) || errorHandler(second_word)){  // checks if either word has an error
        printf("Error: Words should not contain numbers or special characters.\nPlease try again.\n");  // prints an error message
    }
}

// Function to check if the two input words are anagrams
int checkAnagrams(char first_word[], char second_word[]){
    int i;
    int fwCount[26] = {0};  // array to count occurrences of each letter in the first word
    int swCount[26] = {0};  // array to count occurrences of each letter in the second word
    int fwLen = 0, swLen = 0;  // variables to track the number of alphabet characters in each word

    // Counts occurrences of letters in the first word
    for(i = 0; first_word[i] != '\0'; i++) {
        if (isalpha(first_word[i])){  // only consider alphabetic characters
            fwCount[tolower(first_word[i]) - 'a']++;  // increment the count for the corresponding letter
            fwLen++;  // increment the total letter count
        } 
    }

    // Counts occurrences of letters in the second word
    for(i = 0; second_word[i] != '\0'; i++) {
        if (isalpha(second_word[i])) {
            swCount[tolower(second_word[i]) - 'a']++;  // increment the count for the corresponding letter
            swLen++;  // increment the total letter count
        }
    }

    // If the lengths of the words don't match, they cannot be anagrams
    if (fwLen != swLen) {
        return 0;  // return false if lengths are different
    }

    // Compare the letter counts of both words
    for (i = 0; i < 26; i++) { 
        if (fwCount[i] != swCount[i]) {  // if counts for any letter don't match
            return 0;  // return false
        }
    }

    return 1;  // return true if all checks pass, meaning the words are anagrams
}

// Function to prompt the user if they want to try again
int tryAgain(){
    int sure;
    int choice;

    do{
        printf("Would you like to try again?\n(0 - yes / 1 - no): ");
        if(scanf("%d", &choice) != 1){  // checks if input is valid
            printf("\nInvalid input! Please Try Again!.\n");
            while (getchar() != '\n');  // clears the buffer
            continue;
        }
        if (choice == 1){  // if user chooses not to try again
            do{
                printf("Do you want to exit the program?\n(0 - yes / 1 - no): ");
                if(scanf("%d", &sure) != 1){  // checks if input is valid
                    printf("\nInvalid input! Please Try Again!.\n");
                    while (getchar() != '\n');  // clears the buffer
                    continue;
                }
                if(sure == 0){  // if user chooses to exit the program
                    printf("Thank you for using our program!");
                    return 1;  // return 1 to exit
                } else if (sure == 1){  // if user chooses to continue
                    return 0;  // return 0 to continue
                } else {
                    printf("\nInvalid Input, try again.\n");
                }
            } while (sure != 1 || sure != 0);
        } else if (choice == 0){  // if user chooses to try again
            choice = 0;
            return choice;
        } else {
            printf("\nInvalid Input, try again.\n");
        }
    }while(choice != 0 && choice != 1);

    return choice;  // returns the user's choice
}

// Function to verify if two words are anagrams and display the result
char verifyAnagram(char name[], char first_word[], char second_word[]){
    if (checkAnagrams(first_word, second_word)){  // checks if the words are anagrams
        printf("%s, the words %s and %s ARE Anagrams!\n", name, first_word, second_word);  // displays success message
    } else {
        printf("%s, the words %s and %s ARE NOT Anagrams.\n", name, first_word, second_word);  // displays failure message
    }
}

// Main function of the program
int main()
{
    char first_word[80], second_word[80];  // arrays to hold the two words/phrases
    char name[80];  // array to hold the user's name
    int choice;  // variable to store the user's choice to try again

    // INPUTS - Getting user input for name, and two words/phrases
    do{    
        printf("Welcome to Anagram Checker!\nPlease enter your name: ");
        scanf("%s", &name);  // reads the user's name
        getchar();  // consumes the newline character left by scanf

        do{
            printf("%s, enter the first word/phrase: ", name);  // prompt user for first word
            fgets(first_word, sizeof(first_word), stdin);  // reads the first word
            first_word[strcspn(first_word, "\n")] = '\0';  // removes the newline character from the input

            printf("Enter the second word/phrase: ");  // prompt user for second word
            fgets(second_word, sizeof(second_word), stdin);  // reads the second word
            second_word[strcspn(second_word, "\n")] = '\0';  // removes the newline character

            // OUTPUTS - Checking for errors in the user input
            error(first_word, second_word);  // checks if the words have errors (invalid characters)
        }while(errorHandler(first_word) || errorHandler(second_word));  // repeat if there's an error in the input

        verifyAnagram(name, first_word, second_word);  // checks if the two words are anagrams and prints the result

        // Try again prompt
        choice = tryAgain();  // asks if the user wants to try again
    }while (choice == 0);  // repeat if user chooses to try again

    return 0;  // end of program
}
