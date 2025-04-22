#include <stdio.h>
	
	// struct for storing time
	struct Time{
		int hour;
		int minute;
	};
	
	// struct for storing user name(employees) records
	struct EmployeeRecord{
		char name[80];
		struct Time timeIn;
		struct Time timeOut;
	};
	
int main(){	
	int i;
	
	
	// employees[n]: n = number of records you want
	struct EmployeeRecord employees[2];
	
	//Input for '5' employees
	for (i=0;i<2;i++){
		printf("\n---- Enter Details for Employee %d: \n", i+1);
		
		// Requests Name
		printf("Enter employee name: ");
		fgets(employees[i].name, sizeof(employees[i].name), stdin);
		
		// Requests Time Check in & out (00 00)
		printf("Enter Time In (HH MM): ");
		scanf("%d %d", &employees[i].timeIn.hour,  &employees[i].timeIn.minute);		
		while(getchar()!='\n');
		
		printf("Enter Time Out (HH MM): ");
		scanf("%d %d", &employees[i].timeOut.hour,  &employees[i].timeOut.minute);
		while(getchar()!='\n');
	}	
	
	// prints all record after finishing number of records to fill
	printf("\n===== Employee Records =====\n");
	for(i = 0; i<2;i++){
		printf("\nEmployee %d:\n", i+1);
		printf("Name     : %s", employees[i].name);
		printf("Time In  : %02d:%02d\n", employees[i].timeIn.hour, employees[i].timeIn.minute);
        printf("Time Out : %02d:%02d\n", employees[i].timeOut.hour, employees[i].timeOut.minute);
    }
	
	
	return 0;
}
