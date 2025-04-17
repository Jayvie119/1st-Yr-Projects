#include <stdio.h>

int inputCheck(){
	int x;
	char c;
	while(1){
		printf("\nEnter an integer: ");
		if(scanf("%d", &x)==1 && x>0){
			while((c=getchar())!='\n' && c!= EOF);
			return x;
		}
		printf("Error! Enter a valid integer.\n");
		while((c=getchar())!='\n' && c!= EOF);
	}
}

int valueCheck(){
	int x;
	char c;
	while(1){
		printf("\nEnter an integer: ");
		if(scanf("%d", &x)==1){
			while((c=getchar())!='\n' && c!= EOF);
			return x;
		}
		printf("Error! Enter a valid integer.\n");
		while((c=getchar())!='\n' && c!= EOF);
	}
}

int againCheck(){
	int x;
	char c;
	while(1){
		printf("\nError! Try again? 1-Yes / 0-No: ");
		if(scanf("%d", &x)==1 && (x==0||x==1)){
			while((c=getchar())!='\n' && c!= EOF);
			return x;
		}
		printf("Error! Enter 1 for Yes or 0 for No.\n");
		while((c=getchar())!='\n' && c!= EOF);
	}
}


int main(){
	int num, value, retry;
	
	printf("Testing Input Check: ");
	num = inputCheck();
	printf("You entered %d\n\n", num);
	
	printf("Testing value Check: ");
	value = valueCheck();
	printf("You entered %d\n\n", value);	

	printf("Testing again Check: ");
	retry = againCheck();
	printf("You entered %d\n\n", retry);	
	
	
	return 0;
}
