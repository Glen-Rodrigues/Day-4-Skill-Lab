#include <stdio.h>
struct Employee_t
{
	int id;
	char name[250], department[50];
	float salary;
};
typedef struct Employee_t Employee;
void readEmployees (Employee emp[], int n)
{
	printf ("Enter details (ID, Name, Salary, Department):\n");
	for (int i=0; i<n; i++)
		scanf ("%d %s %f %s", &emp[i].id, emp[i].name, &emp[i].salary, emp[i].department);
}
void displayEmployees (Employee emp[], int n)
{
	printf ("Employees:\n");
	for (int i=0; i<n; i++)
		printf ("%d-%s-%.2f-%s\n", emp[i].id, emp[i].name, emp[i].salary, emp[i].department);
}
Employee findHighestSalaried (Employee emp[], int n)
{
	Employee maxEmployee = emp[0];
	for (int i=0; i<n; i++)
	{
		if (emp[i].salary > maxEmployee.salary)
			maxEmployee = emp[i];
	}
	return maxEmployee;
}
int main()
{
	int employeeCount;
	printf ("Enter number of Employees:");
	scanf ("%d", &employeeCount);
	Employee employees[1000];
	readEmployees (employees, employeeCount);
	displayEmployees (employees, employeeCount);
	Employee highestSalaried = findHighestSalaried (employees, employeeCount);
	printf ("Employee with highest salary: %s, %.2f (%s)\n", highestSalaried.name, highestSalaried.salary, highestSalaried.department);
	return 0;
}
