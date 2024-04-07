#ifndef CLASSES_H
#define CLASSES_H

#include <iostream>
#include <vector>
#include <string.h>

#include "function.h"
#include "parameters.h"

using namespace std;

class Person {
	string name;
	string date;
	Gender gender;

	public:
		Person (string name, string date, Gender gender) 
			: name(name), date(date), gender(gender) {}


		string getName() {
			return name;
		}
};

class Department {

};

class Employee : public Person {

	public:
		Employee (string name, string date, Gender gender) 
			: Person(name, date, gender){}
};

class Company {
	private:
		vector<Employee> employee;
		vector<Department> department;

	public:
		void addNewEmployee(Employee value) {
			employee.push_back(value);
		}

		int getNumberOfEmployee() {
			return employee.size();
		}
};

#endif
