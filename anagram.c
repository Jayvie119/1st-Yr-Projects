#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "D:\ANAGRAM Comprog\anagram_func.c"

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
            if (errorHandler(first_word) || errorHandler(second_word)){  //checks error using errorHandler function, raises an error if there are.
                printf("Error: Words should not contain numbers or special characters.\nPlease try again.\n");
            }
        }while(errorHandler(first_word) || errorHandler(second_word));

        if (checkAnagrams(first_word, second_word)){ //outputs whether the 2 inputs are anagram or not
            printf("%s, the words %s and %s ARE Anagrams!\n", name, first_word, second_word);
        } else {
            printf("%s, the words %s and %s ARE NOT Anagrams.\n", name, first_word, second_word);
        }
        // Try again
        choice = tryAgain();// try again prompt.
    }while (choice == 0);

    return 0;   
}