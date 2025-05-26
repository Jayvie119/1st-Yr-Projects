#include <stdio.h>

struct employee{
	int id;
	char name[50];
	float hourlyRate;
	int hoursWorked;
};

int main(){
	float salary, maxSalary = 0;
	int i, maxIndex = 0;
	struct employee e[3] = {
	{1001, "Chad Smith", 250.50, 80},
	{1002, "Jad Smith", 220.50, 60},
	{1003, "Madz Smith", 350.50, 47}	
	};
	
	for(i=0;i<3;i++){
		salary = e[i].hourlyRate * e[i].hoursWorked;
		printf("ID: %d | Name: %s | Hours: %d | Rate: %.2f | Salary: %.2f\n", e[i].id, e[i].name, e[i].hoursWorked, e[i].hourlyRate, salary);

		
		if(salary>maxSalary){
			maxSalary = salary;
			maxIndex = i;
		}
	}
	
	printf("Highest Salary: %s (%.2f)\n", e[i].name, maxSalary);
	
	
	
	return 0;
}
