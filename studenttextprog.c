#include <stdio.h>

int main(){
	FILE *record;
	char name[80];
	int choice, ans = 1;
	int again = 1;
	
	do{
		printf("\nMENU:\n");
		printf("1. Write to a File-Stream\n2. Read from a File-Stream\n3. Append\n4. Exit\nChoice: ");
		scanf("%d", &choice);
		
		switch(choice){
			case 1:
				record = fopen("<filepath>\\student.txt", "w");
				ans = 1;
				
				printf("WRITING TO A FILE STREAM\n");
				
				while (ans == 1){
					printf("Enter a name: ");
					scanf("%s", name);
					fprintf(record, " %s\n", name);
						
					printf("Another name? 1-Yes/0-No\nChoice: ");
					scanf("%d", &ans);
				}
			
				fclose(record);
				
				break;
			
			case 2:
				record = fopen("<filepath>\\student.txt", "r");
				
				printf("READING FROM A FILE-STREAM\n");
				
				if (record == NULL){
					printf("File Not Found!\n");
					break;
				} else {
					while(fscanf(record, " %s\n", name)!=EOF){
						printf("The name is %s\n", name);
					}
					if (feof(record)){
						printf("\nReached the end of file.\n");
					}
				}
				
				fclose(record);
				break;
			
			case 3:
				record = fopen("<filepath>\\student.txt", "a");
				ans = 1;
				
				printf("APPENDING TO A FILE-STREAM\n");
				
				while(ans==1){
					printf("Enter a name: ");
					scanf("%s", name);
					fprintf(record, " %s\n", name);
					
					printf("Another name? 1-Yes/0-No\nChoice: ");
					scanf("%d", &ans);
				}
				
				fclose(record);
				break;
				
			case 4:
				printf("Are you sure you want to exit the program?\nChoice: ");
				scanf("%d", &again);
				if (again == 1){
					printf("Thank you for using my program!\n");
					return 0;
				}
				
				break;
					
			default:
				printf("Error! Please try again\n");
		}
	} while (!(choice == 4 && again == 1));
	
	
	return 0;
}
