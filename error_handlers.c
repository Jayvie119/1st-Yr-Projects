#include <stdio.h>

// Function: inputCheck
// Purpose: Prompt the user until they enter a positive integer (>0)
int inputCheck(){
	int x;
	char c;
	while(1){
		printf("\nEnter an integer: ");
		// Check if input is an integer and greater than 0
		if(scanf("%d", &x)==1 && x>0){
			// Clear input buffer
			while((c=getchar())!='\n' && c!= EOF);
			return x;
		}
		// If input is invalid
		printf("Error! Enter a valid integer.\n");
		// Clear invalid input
		while((c=getchar())!='\n' && c!= EOF);
	}
}

// Function: valueCheck
// Purpose: Prompt the user until they enter a valid integer (any value)
int valueCheck(){
	int x;
	char c;
	while(1){
		printf("\nEnter an integer: ");
		// Check if input is a valid integer
		if(scanf("%d", &x)==1){
			// Clear input buffer
			while((c=getchar())!='\n' && c!= EOF);
			return x;
		}
		// If input is invalid
		printf("Error! Enter a valid integer.\n");
		// Clear invalid input
		while((c=getchar())!='\n' && c!= EOF);
	}
}

// Function: againCheck
// Purpose: Ask the user if they want to retry (1 for Yes, 0 for No)
// Only accepts 0 or 1 as valid input
int againCheck(){
	int x;
	char c;
	while(1){
		printf("\nError! Try again? 1-Yes / 0-No: ");
		// Check if input is either 0 or 1
		if(scanf("%d", &x)==1 && (x==0||x==1)){
			// Clear input buffer
			while((c=getchar())!='\n' && c!= EOF);
			return x;
		}
		// If input is not 0 or 1
		printf("Error! Enter 1 for Yes or 0 for No.\n");
		// Clear invalid input
		while((c=getchar())!='\n' && c!= EOF);
	}
}

int main(){
	int num, value, retry;
	
	// Test for inputCheck (positive integer)
	printf("Testing Input Check: ");
	num = inputCheck();
	printf("You entered %d\n\n", num);
	
	// Test for valueCheck (any integer)
	printf("Testing value Check: ");
	value = valueCheck();
	printf("You entered %d\n\n", value);	

	// Test for againCheck (1 or 0 only)
	printf("Testing again Check: ");
	retry = againCheck();
	printf("You entered %d\n\n", retry);	
	
	return 0;
}
