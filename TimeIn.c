#include <stdio.h>
#include <string.h>

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

// Input validation for integers within a range
int rangeCheck(const char *prompt, int min, int max){
	int x;
	char c;
	while (1){
		printf("%s", prompt);
		if (scanf("%d", &x) == 1 && x >= min && x <= max){
			while ((c = getchar()) != '\n' && c != EOF); // Clear buffer
			return x;
		}
		printf("Error! Please enter a value between %d and %d.\n", min, max);
		while ((c = getchar()) != '\n' && c != EOF); // Clear buffer
	}
}

int main(){	
	int i;
	struct EmployeeRecord employees[EMPLOYEE_COUNT];

	for (i = 0; i < EMPLOYEE_COUNT; i++) {
		printf("\n---- Enter Details for Employee %d ----\n", i + 1);

		// Requests Name
		printf("Enter employee name: ");
		fgets(employees[i].name, sizeof(employees[i].name), stdin);
		// Strip newline left by fgets
		employees[i].name[strcspn(employees[i].name, "\n")] = '\0';

		// Requests Time Check-in & Check-out
		employees[i].timeIn.hour = rangeCheck("Enter Time In (Hour 0 - 23): ", 0, 23);
		employees[i].timeIn.minute = rangeCheck("Enter Time In (Minute 0 - 59): ", 0, 59);

		employees[i].timeOut.hour = rangeCheck("Enter Time Out (Hour 0 - 23): ", 0, 23);
		employees[i].timeOut.minute = rangeCheck("Enter Time Out (Minute 0 - 59): ", 0, 59);
	}

	// Print all records
	printf("\n===== Employee Records =====\n");
	for (i = 0; i < EMPLOYEE_COUNT; i++) {
		printf("\nEmployee %d:\n", i + 1);
		printf("Name     : %-20s\n", employees[i].name);
		printf("Time In  : %02d:%02d\n", employees[i].timeIn.hour, employees[i].timeIn.minute);
		printf("Time Out : %02d:%02d\n", employees[i].timeOut.hour, employees[i].timeOut.minute);
	}

	return 0;
}
