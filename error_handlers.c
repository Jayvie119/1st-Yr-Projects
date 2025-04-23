#include <stdio.h>

#define EMPLOYEE_COUNT 2

// Struct for storing time
struct Time {
	int hour;
	int minute;
};

// Struct for storing employee records
struct EmployeeRecord {
	char name[80];
	struct Time timeIn;
	struct Time timeOut;
};

// Input validation for integers > 0
int inputCheck(const char *prompt){
	int x;
	char c;
	while(1){
		printf("%s", prompt);
		if(scanf("%d", &x)==1 && x >= 0){
			while((c=getchar())!='\n' && c!=EOF); // clear buffer
			return x;
		}
		printf("Error! Please enter a valid positive integer.\n");
		while((c=getchar())!='\n' && c!=EOF); // clear buffer
	}
}

int main(){	
	int i;
	struct EmployeeRecord employees[EMPLOYEE_COUNT];

	for ( i = 0; i < EMPLOYEE_COUNT; i++) {
		printf("\n---- Enter Details for Employee %d: \n", i + 1);

		// Requests Name
		printf("Enter employee name: ");
		fgets(employees[i].name, sizeof(employees[i].name), stdin);

		// Requests Time Check-in & Check-out
		employees[i].timeIn.hour = inputCheck("Enter Time In (Hour 0-23): ");
		employees[i].timeIn.minute = inputCheck("Enter Time In (Minute 0-59): ");

		employees[i].timeOut.hour = inputCheck("Enter Time Out (Hour 0-23): ");
		employees[i].timeOut.minute = inputCheck("Enter Time Out (Minute 0-59): ");
	}

	// Print all records
	printf("\n===== Employee Records =====\n");
	for ( i = 0; i < EMPLOYEE_COUNT; i++) {
		printf("\nEmployee %d:\n", i + 1);
		printf("Name     : %s", employees[i].name);
		printf("Time In  : %02d:%02d\n", employees[i].timeIn.hour, employees[i].timeIn.minute);
		printf("Time Out : %02d:%02d\n", employees[i].timeOut.hour, employees[i].timeOut.minute);
	}

	return 0;
}
