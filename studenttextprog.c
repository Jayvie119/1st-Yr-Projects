#include <stdio.h>

// Program in File Handling in C: Write, Read, Append
int main(){
    FILE *record;           // File pointer for handling file operations
    char name[80];          // for storing name input
    int choice, ans = 1;    // Menu and loop control variables
    int again = 1;

    do {
        // Display menu options
        printf("\nMENU:\n");
        printf("1. Write to a File-Stream\n2. Read from a File-Stream\n3. Append\n4. Exit\nChoice: ");
        scanf("%d", &choice);

        switch(choice) {
            // Case 1: Write mode - Overwrites the file
            case 1:
                record = fopen("<filepath>\\student.txt", "w");  // Change <filepath> to your actual directory
                ans = 1;

                printf("WRITING TO A FILE STREAM\n");

                while (ans == 1) {
                    printf("Enter a name: ");
                    scanf("%s", name);
                    fprintf(record, "%s\n", name);  // Write name to file

                    printf("Another name? 1-Yes / 0-No\nChoice: ");
                    scanf("%d", &ans);
                }

                fclose(record);  // Always close the file after writing
                break;

            // Case 2: Read mode - Reads file content
            case 2:
                record = fopen("<filepath>\\student.txt", "r");

                printf("READING FROM A FILE-STREAM\n");

                if (record == NULL) {
                    // Handle missing file
                    printf("File Not Found!\n");
                    break;
                } else {
                    // Read and display each name until end of file
                    while (fscanf(record, "%s", name) != EOF) {
                        printf("The name is %s\n", name);
                    }
                    if (feof(record)) {
                        printf("\nReached the end of file.\n");
                    }
                }

                fclose(record);  // Close after reading
                break;

            // Case 3: Append mode - Adds new entries to the file
            case 3:
                record = fopen("<filepath>\\student.txt", "a");
                ans = 1;

                printf("APPENDING TO A FILE-STREAM\n");

                while(ans == 1) {
                    printf("Enter a name: ");
                    scanf("%s", name);
                    fprintf(record, "%s\n", name);  // Append new name

                    printf("Another name? 1-Yes / 0-No\nChoice: ");
                    scanf("%d", &ans);
                }

                fclose(record);
                break;

            // Case 4: Exit the program
            case 4:
                printf("Are you sure you want to exit the program?\nChoice: ");
                scanf("%d", &again);
                if (again == 1) {
                    printf("Thank you for using my program!\n");
                    return 0;
                }
                break;

            // Default case: Invalid choice handling
            default:
                printf("Error! Please try again\n");
        }

    } while (!(choice == 4 && again == 1));  // Keep looping unless confirmed exit

    return 0;
}
