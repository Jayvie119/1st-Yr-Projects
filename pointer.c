#include <stdio.h>

int main(){
	int x = 10;
	int *ptr = &x;// referencing to address of x
	int **j = &ptr; // referencing to address of ptr
	
	printf("Address of x: %x\n", &x);
	printf("Value of x: %d\n", x); // value from x
	
	*ptr= 13;
	printf("\n");
	printf("New value of x: %d\n", x);
	printf("Address of ptr: %x\n", &ptr); //address ni ptr
	printf("Address of x through ptr: %x\n", ptr); // address pointer to x
	printf("Value of x through ptr: %d\n", *ptr); // address pointer to x
	
	**j = 2;
	printf("\n");
	printf("New value of x: %d\n", x);
	printf("Address of j: %x\n", &j); //address ni j
	printf("Address of x through ptr pointed from j: %x\n", *j); // address pointer to ptr
	printf("Value of x through ptr pointed from j: %d\n", **j); // value pointer to ptr
	
	return 0;
}
