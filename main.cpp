#include <iostream>
#include <vector>
#include <string.h>

#include "function.h"
#include "classes.h"
#include "parameters.h"

using namespace std;

int main () {
	Company company;
	Employee newEmployee("Van Huy Du",  "20/01/2002", MALE);

	company.addNewEmployee(newEmployee);

	cout << company.getNumberOfEmployee() << endl;

	addNewEmployee();
	writeDataToFile(newEmployee, EMPLOYEE_DATE_PATH);
	return 0;
}


