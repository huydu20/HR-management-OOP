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
	string gender;

	public:
		Person (string name, string date, string gender) 
			: name(name), date(date), gender(gender) {}


		string getName() {
			return name;
		}

		string getDate() {
			return date;
		}

		string getGender() {
			return gender;
		}

		void setName(string value) {
			this->name = value;
		}

		void setDate(string value) {
			this->date = value;
		}

		void setGender(string value) {
			this->gender = value;
		}
};

class Department {

	int id;
	string name;
	int manager_id = 0;
	string manager_name;

	public: 
		Department (int id, string name, int manager_id, string manager_name) 
			: id(id), name(name), manager_id(manager_id), manager_name(manager_name) {}

		int getId() {
			return id;
		}

		string getName() {
			return name;
		}

		int getManagerId() {
			return manager_id;
		}

		string getManagerName() {
			return manager_name;
		}

		void setName(string value) {
			this->name = value;
		}

		void setManagerId(int value) {
			this->manager_id = value;
		}

		void setManagerName(string value) {
			this->manager_name = value;
		}
};

class Employee : public Person {

	string phone;
	string role;
	int id; 
	int depId; 

	public:
		Employee (
			string name, 
			string date, 
			string gender, 
			string phone,
			string role,
			int id = 0, 
			int depId = 0) 
			: Person(name, date, gender), 
				phone(phone),
				role(role),
				id(id),
				depId(depId){}

		int getId() {
			return id;
		}

		string getPhone() {
			return phone;
		}

		string getRole() {
			return role;
		}

		int getDepId() {
			return depId;
		}

		void setPhone(string value) {
			this->phone = value;
		}

		void setRole(string value) {
			this->role = value;
		}

		void setDepId(int value) {
			this->depId = value;		
		}
};

class Company {
	private:
		vector<Employee> employees;
		vector<Department> departments;

	public:
		// Department
		void addNewDepartment(Department value) {
			departments.push_back(value);
		}

		Department* getDepartment(int pos) {
			return &departments[pos];
		}

		Department* getDepartmentById(int id) {
			for (int i = 0; i < departments.size(); i++) {
				if(departments[i].getId() == id) {
					return &departments[i];
					break;
				}
			}
		}

		int getNumberOfDepartment() {
			return departments.size();
		}

		void deleteDepartment(int id) {
			for (int i = 0; i < departments.size(); i++) {
				if (departments[i].getId() == id) {
					departments.erase(departments.begin() + i);
					break;
				}
			}
		}

		void arrangeDepartments() {
			for (int i = 1; i < departments.size(); i++) {
				if (departments[i].getId() < departments[i - 1].getId()) {
					Department temp = departments[i];
					departments[i] = departments[i - 1];
					departments[i - 1] = temp;
				}
			}
		}

		// Employee
		void addNewEmployee(Employee value) {
			employees.push_back(value);
		}

		int getNumberOfEmployee() {
			return employees.size();
		}

		Employee *getEmployee(int pos) {
			return &employees[pos];
		}

		Employee* getEmployeeByID(int id) {
			for (int i = 0; i < employees.size(); i++) {
				if(employees[i].getId() == id) {
					return &employees[i];
				}
			}
		}

		void updateEmployeeRole(int id, string newRole) {
			for (int i = 0; i < employees.size(); i++) {
				if(employees[i].getId() == id) {
					employees[i].setRole(newRole);
					break;
				}
			}
		}

		bool hasEmployeeWithId(int id) {
			for (int i = 0; i < employees.size(); i++) {
				if(employees[i].getId() == id) {
					return true;
				}
			}

			return false;
		}

		void deleteEmployee(int id) {
			for (int i = 0; i < employees.size(); i++) {
				if (employees[i].getId() == id) {
					employees.erase(employees.begin() + i);
					break;
				}
			}
		}

		void arrangeEmployees() {
			for (int i = 1; i < employees.size(); i++) {
				if (employees[i].getId() < employees[i - 1].getId()) {
					Employee temp = employees[i];
					employees[i] = employees[i - 1];
					employees[i - 1] = temp;
				}
			}
		}

		// Display

		void displayAllEmployee() {

			if (employees.size() == 0) {
				cout << "Empty list !";
				return;
			}

			cout << setw(ID_SPACE) << "ID";
			cout << setw(NAME_SPACE) << "Name";
			cout << setw(DATE_SPACE) << "Date";
			cout << setw(GENDER_SPACE) << "Gender";
			cout << setw(PHONE_SPACE) << "Phone number";
			cout << setw(POSITION_SPACE) << "Position";
			cout << setw(WORK_AT_SPACE) << "Work at";
			cout << endl;

			for (int i = 0; i < employees.size(); i++) {
				cout << setw(ID_SPACE) << employees[i].getId();
				cout << setw(NAME_SPACE) << employees[i].getName();
				cout << setw(DATE_SPACE) << employees[i].getDate();
				cout << setw(GENDER_SPACE) << employees[i].getGender();
				cout << setw(PHONE_SPACE) << employees[i].getPhone();
				cout << setw(POSITION_SPACE) << employees[i].getRole();
				cout << setw(WORK_AT_SPACE) << getDepartmentById(employees[i].getDepId())->getName();
				cout << endl;
			}
		}

		void displayAllDepartment() {
			
			if (departments.size() == 0)
			{
				cout << "Empty list !";
				return;
			}

			cout << setw(ID_SPACE) << "ID";
			cout << setw(NAME_SPACE) << "Name";
			cout << setw(NAME_SPACE) << "Manager ID";
			cout << setw(NAME_SPACE) << "Manager name";
			cout << endl;

			for (int i = 0; i < departments.size(); i++)
			{
				cout << setw(ID_SPACE) << departments[i].getId();
				cout << setw(NAME_SPACE) << departments[i].getName();
				cout << setw(NAME_SPACE) << departments[i].getManagerId();
				cout << setw(NAME_SPACE) << departments[i].getManagerName();
				cout << endl;
			}
		}
};

#endif
