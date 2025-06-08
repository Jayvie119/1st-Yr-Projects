#include <stdio.h>

// Program for binary file handling: write, read, append names as byte data
int main(){
    FILE *record;           // File pointer
    char name[80];          // Buffer for storing user input
    int choice, ans = 1;    // User control variables
    int again = 1;

    do {
        // Main menu display
        printf("\nMENU:\n");
        printf("1. Write to a File-Stream\n2. Read from a File-Stream\n3. Append\n4. Exit\nChoice: ");
        scanf("%d", &choice);

        switch(choice){
            // Case 1: Write (overwrite) to binary file
            case 1:
                record = fopen("<filepath>\\studentbinary.dat", "wb");    // Change <filepath> to your actual directory
                ans = 1;

                printf("WRITING TO A FILE STREAM\n");

                while (ans == 1){
                    printf("Enter a name: ");
                    scanf("%s", name);
                    fwrite(name, sizeof(name), 1, record);  // Write the entire buffer

                    printf("Another name? 1-Yes / 0-No\nChoice: ");
                    scanf("%d", &ans);
                }

                fclose(record);  // Close file after writing
                break;

            // Case 2: Read from binary file
            case 2:
                record = fopen("<filepath>\\studentbinary.dat", "rb");    // Change <filepath> to your actual directory

                printf("READING FROM A FILE-STREAM\n");

                if (record == NULL){
                    printf("File Not Found!\n");
                    break;
                } else {
                    // Read records until end of file
                    while(fread(name, sizeof(name), 1, record) == 1){
                        printf("The name is %s\n", name);
                    }

                    if (feof(record)){
                        printf("\nReached the end of file.\n");
                    }
                }

                fclose(record);  // Close file after reading
                break;

            // Case 3: Append to binary file
            case 3:
                record = fopen("<filepath>\\studentbinary.dat", "ab");    // Change <filepath> to your actual directory
                ans = 1;

                printf("APPENDING TO A FILE-STREAM\n");

                while(ans == 1){
                    printf("Enter a name: ");
                    scanf("%s", name);
                    fwrite(name, sizeof(name), 1, record);  // Append record to file

                    printf("Another name? 1-Yes / 0-No\nChoice: ");
                    scanf("%d", &ans);
                }

                fclose(record);  // Close file after appending
                break;

            // Case 4: Exit program
            case 4:
                printf("Are you sure you want to exit the program?\nChoice: ");
                scanf("%d", &again);
                if (again == 1){
                    printf("Thank you for using my program!\n");
                    return 0;
                }
                break;

            // Default: Invalid input handler
            default:
                printf("Error! Please try again\n");
        }

    } while (!(choice == 4 && again == 1));  // Loop until confirmed exit

    return 0;
}
