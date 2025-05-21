#include <stdio.h>
#include <ctype.h>
#include <string.h>

//STRUCT
struct seat{
	int row;
	char col;
	int booked;
}	splan[20] = {
		{1, 'A'}, {1, 'B'}, {1, 'C'}, {1, 'D'}, 
		{2, 'A'}, {2, 'B'}, {2, 'C'}, {2, 'D'},
		{3, 'A'}, {3, 'B'}, {3, 'C'}, {3, 'D'},
		{4, 'A'}, {4, 'B'}, {4, 'C'}, {4, 'D'},	
		{5, 'A'}, {5, 'B'}, {5, 'C'}, {5, 'D'}
	}, *sptr;

// Array Struct to Function
	/*This Function Displays Whether a seat chosen has been booked or available*/
void displayOneSeat(struct seat s){
    printf("Seat: %d%c - %s\n", s.row, s.col, s.booked ? "Booked" : "Available");
}

// Pointer Struct to Function
	/*This Function Displays the Seats Row and Column, replaces taken seat with X*/
void displayAvlSeat(struct seat *sptr) {
	int row;
	char col;
    printf("\nAvailable Seats:\n");
    for ( row = 1; row <= 5; row++) {
        printf("%d\t", row);
        for ( col = 'A'; col <= 'D'; col++) {
            int index = (row - 1) * 4 + (col - 'A');
            if (sptr[index].booked) {
                printf("X\t");
            } else {
                printf("%c\t", col);
            }
        }
        printf("\n");
    }
}

// Members to Function
 /*This function converts a seat row and column (like 2C) into a flat array index so it can be used in the 1D array splan[20]*/
int seatIndex(int row, char col) {
	// Row is 1-5, col is A-D
	return (row - 1) * 4 + (col - 'A');
}

// Pointer struct and Members to Function
	/*This function takes the index from the function 'seatIndex', and checks if the seat is booked or available, if available
	the function will call another function 'displayOneSeat'.*/
int booked(struct seat *sptr, int row, char col) {
	int index = seatIndex(row, col);
	if (sptr[index].booked) {
		printf("Seat %d%c is already occupied. Please choose another.\n", row, col);
		return 0;
	} else {
		sptr[index].booked = 1; // becomes true (booked)
		displayOneSeat(sptr[index]);
		return 1;
	}
}

// Pointer Struct to Function
	/*This function will return true if all seats are booked*/
int allSeatsBooked(struct seat *sptr) {
	int i;
	for ( i = 0; i < 20; i++) {
		if (!sptr[i].booked) {
			return 0;
		}
	}
	return 1;
}

// Pointer Struct to Function
 /*Main Process of the Program, utilizes multiple function and prompting the user for input*/
void airplane(struct seat *sptr){
	char input[10];
	char confirm[10];
	int rChoice;
	char cChoice;
	int sure;

	
	do{
		displayAvlSeat(sptr);
	
		if(allSeatsBooked(sptr)){
			printf("All seats occupied, plane is now fully booked.\nThank you for using my program!\n");
			break;
		}
		
		printf("Enter seat (e.g., 1D), or 'q' to quit: ");
		fgets(input, sizeof(input), stdin);
		
		input[strcspn(input, "\n")] = '\0';         // Replaces newline to remove buffers

    // Errorhandler to only accept choices given
		if (strlen(input)==1 && (input[0]=='q' || input[0]=='Q')){ 
			printf("Are you sure to quit the program? 1-Yes/0-No: ");
			fgets(confirm, sizeof(confirm),stdin);   // Used fgets to avoid new line
			sure = atoi(confirm);                    // Converts Numeric String to integer
			if(sure == 1){
				printf("Thank you for using the program.\n");
				break;
			} else {
				continue;
			}
		}

    // Errorhandler to only accept the choices given
		if (strlen(input) == 2 && input[0] >='1' && input[0] <= '5' && 
		(isalpha(input[1]) && (toupper(input[1]) >= 'A' && toupper(input[1]) <= 'D'))){
			rChoice = input[0] - '0';                  // Converts Numeric Character to Integer (ASCII Value of Row - ASCII Value of 0) = Actual value!!!
			cChoice= toupper(input[1]);
			
			booked(sptr, rChoice, cChoice);
		} else {
			printf("Invalid Input, Please enter seat like '2D' or 'q' to quit.\n");
			continue;
		}
		
	}while(1);
}

int main(){
	sptr = splan; 
	
	airplane(sptr);
	
	return 0;
}
