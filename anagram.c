#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "location of anagram_5 in your pc"  // Include directory of anagram_5

int main()
{
    char first_word[80], second_word[80];  // Arrays to hold the first and second word/phrase
    char name[80];  // Array to hold user's name
    int choice;  // Variable to store the user's choice for trying again

    // INPUTS - Getting user input for name, and two words/phrases
    do{    
        printf("Welcome to Anagram Checker!\nPlease enter your name: ");
        scanf("%s", &name);  // Reading the user's name
        getchar();  // To consume the newline character left by scanf and prevent concatenation of inputs

        do{
            printf("%s, enter the first word/phrase: ", name);  // Prompting user for the first word
            fgets(first_word, sizeof(first_word), stdin);  // Reading the first word/phrase using fgets to handle spaces
            first_word[strcspn(first_word, "\n")] = '\0';  // Removing the trailing newline character added by fgets

            printf("Enter the second word/phrase: ");  // Prompting user for the second word
            fgets(second_word, sizeof(second_word), stdin);  // Reading the second word/phrase
            second_word[strcspn(second_word, "\n")] = '\0';  // Removing the trailing newline character

            // OUTPUTS - Error checking to ensure valid input (no numbers or special characters)
            if (errorHandler(first_word) || errorHandler(second_word)){  // Using errorHandler function to check input validity
                printf("Error: Words should not contain numbers or special characters.\nPlease try again.\n");  // Error message if invalid input
            }
        }while(errorHandler(first_word) || errorHandler(second_word));  // Loop if any input contains invalid characters

        // Checking if the two words/phrases are anagrams
        if (checkAnagrams(first_word, second_word)){  // Using checkAnagrams function to compare the two words
            printf("%s, the words %s and %s ARE Anagrams!\n", name, first_word, second_word);  // Output if they are anagrams
        } else {
            printf("%s, the words %s and %s ARE NOT Anagrams.\n", name, first_word, second_word);  // Output if they are not anagrams
        }

        // Try again prompt
        choice = tryAgain();  // Using tryAgain function to ask the user if they want to try again
    }while (choice == 0);  // Loop if user chooses to try again

    return 0;  // End of program
}   
