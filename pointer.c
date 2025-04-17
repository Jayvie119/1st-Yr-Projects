#include <stdio.h>

int main() {
	int x = 10;
	int *ptr = &x;   // ptr stores the address of x (single pointer)
	int **j = &ptr;  // j stores the address of ptr (double pointer)

	// Display address and value of x
	printf("Address of x: %x\n", &x);
	printf("Value of x: %d\n", x); // prints the value stored in x
	
	// Modify x using the single pointer
	*ptr = 13;
	printf("\n");
	printf("New value of x: %d\n", x); // x is updated to 13 through ptr
	printf("Address of ptr: %x\n", &ptr); // address where ptr is stored
	printf("Address of x through ptr: %x\n", ptr); // ptr points to x
	printf("Value of x through ptr: %d\n", *ptr); // dereferencing ptr gives value of x

	// Modify x again using the double pointer
	**j = 2;
	printf("\n");
	printf("New value of x: %d\n", x); // x is updated to 2 through double pointer
	printf("Address of j: %x\n", &j); // address where j (double pointer) is stored
	printf("Address of x through ptr pointed by j: %x\n", *j); // *j is ptr, which points to x
	printf("Value of x through ptr pointed by j: %d\n", **j); // **j dereferences to x

	return 0;
}
