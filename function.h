#ifndef FUNCTION_H
#define FUNCTION_H

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>
#include <sstream>
#include <iomanip>
#include <conio.h>

#include "classes.h"
#include "parameters.h"

using namespace std;

// 
string trim(string str) {
    string result = str;
    result.erase(0, result.find_first_not_of(' ')); 
    result.erase(result.find_last_not_of(' ') + 1); 
    return result;
}

string toLower(string str) {
    string temp = str;
    for (int i = 0; i < str.length(); i++) {
        temp[i] = tolower(str[i]);
    }
    return temp;
}

void pressAnyKey() {
    cout << endl;
    cout << "\nPress any key to back!";
    _getch();
    system("cls");
}

bool isValidDate(string input) {
    int day, month, year;
    char sep = '/';
    int pos1 = input.find(sep);
    int pos2 = input.find(sep, pos1 + 1);

    if (pos1 == string::npos || pos2 == string::npos) {
        return false;
    }

    day = stoi(input.substr(0, pos1));
    month = stoi(input.substr(pos1 + 1, pos2 - pos1 - 1));
    year = stoi(input.substr(pos2 + 1));

    if (year < 0 || year > 9999 || month < 1 || month > 12 || day < 1) {
        return false;
    }

    int daysInMonth = 31;
    switch (month) {
    case 2:
        daysInMonth = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) ? 29 : 28;
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        daysInMonth = 30;
        break;
    }

    return (day <= daysInMonth);
}

bool checkPhoneInput(string phone) {
    for (int i = 0; i < phone.length(); i++)
    {
        if ((int)(phone[i]) > 57 || (int)(phone[i]) < 48)
        {
            cout << "Value :" << (int)(phone[i]) << endl;
            return false;
        }
    }
    if (phone.length() < PHONE_LENGTH_SPACE)
    {
        cout << "Invalid phone length!" << endl;
        return false;
    }
    if (phone[0] != '0')
    {
        cout << "Invalid phone format!" << endl;
        return false;
    }
    return true;
}

bool confirm(string message = "Confirm?") {
    cout << message << endl;
    cout << "1. Yes" << endl;
    cout << "2. No" << endl;
    bool isConfirm = false;
    bool isChose = false;
    int select;
    cin >> select;
    while (!isChose)
    {
        switch (select)
        {
        case 1:
            isConfirm = true;
            isChose = true;
            break;
        case 2:
            isConfirm = false;
            isChose = true;
            break;
        default:
            break;
        }
    }
    return isConfirm;
}

string formatName(string name) {
    string newString = trim(name);
    int len = newString.length();
    for (int i = 0; i < len; i++)
    {
        if (i == 0)
        {
            newString[i] = toupper(newString[i]);
        }
        else
        {
            newString[i] = tolower(newString[i]);
            if (newString[i - 1] == ' ' && newString[i] != ' ')
            {
                newString[i] = toupper(newString[i]);
            }
        }
    }
    string result;
    bool space = false;
    for (int i = 0; i < len; i++)
    {
        if (newString[i] == ' ')
        {
            if (!space)
            {
                result += newString[i];
            }
            space = true;
        }
        else
        {
            result += newString[i];
            space = false;
        }
    }

    return result;
}

void printEmployee(Employee *employee) {
    cout << setw(ID_SPACE) << "Id";
    cout << setw(NAME_SPACE) << "Name";
    cout << setw(DATE_SPACE) << "Date";
    cout << setw(GENDER_SPACE) << "Gender";
    cout << setw(PHONE_SPACE) << "Phone number";
    cout << setw(POSITION_SPACE) << "Position";
    cout << setw(WORK_AT_SPACE) << "Work at";
    cout << endl;
    cout << setw(ID_SPACE) << employee->getId();
    cout << setw(NAME_SPACE) << employee->getName();
    cout << setw(DATE_SPACE) << employee->getDate();
    cout << setw(GENDER_SPACE) << employee->getGender();
    cout << setw(PHONE_SPACE) << employee->getPhone();
    cout << setw(POSITION_SPACE) << employee->getRole();
    cout << setw(WORK_AT_SPACE) << employee->getDepId();
    cout << endl;
}

void printDepartment(Department *department) {
    cout << setw(ID_SPACE) << "ID";
    cout << setw(NAME_SPACE) << "Name";
    cout << setw(NAME_SPACE) << "Manager ID";
    cout << setw(NAME_SPACE) << "Manager name";
    cout << endl;
    cout << setw(ID_SPACE) << department->getId();
    cout << setw(NAME_SPACE) << department->getName();
    cout << setw(NAME_SPACE) << department->getManagerId();
    cout << setw(NAME_SPACE) << department->getManagerName();
    cout << endl;
}

// Employee handle
int addNewEmployee(Company& company) {
    int n;
    cout << "Input number of new employee: ";
    cin >> n;
    while (n <= 0) {
        cout << "Invalid number!!" << endl;
        cout << "Input number of new employee: " << endl;
        cin >> n;
    }
    for (int i = 0; i < n; i++)
    {
        cout << "Employee " << i + 1 << endl;

        // Name
        cout << "Input employee name: ";
        string employeeName;
        cin.ignore();
        getline(cin, employeeName);
        employeeName = formatName(employeeName);

        // Date
        string employeeDate;
        cout << "Input employee date: ";
        getline(cin, employeeDate);
        while (!isValidDate(employeeDate)) {
            cout << "Invalid date!!" << endl;
            cout << "Input employee date: ";
            getline(cin, employeeDate);
        }

        // Gender
        cout << "Input employee gender: ";
        cout << endl;
        bool isChoseG = false;
        int selectG;
        string employeeGender;
        while (!isChoseG) {
            cout << "1. Male" << endl;
            cout << "2. Female" << endl;
            cout << "Input your select: ";
            cin >> selectG;
            switch (selectG)
            {
            case 1:
                isChoseG = true;
                employeeGender = "Male";
                break;
            case 2:
                isChoseG = true;
                employeeGender = "Female";
                break;
            default:
                cout << "Invalid selection!";
                break;
            }
        }

        // Phone number
        cout << "Input employee phone: ";
        cin.ignore();
        string employeePhone;
        getline(cin, employeePhone);
        while (!checkPhoneInput(employeePhone))
        {
            cout << "Input employee phone again: ";
            getline(cin, employeePhone);
        }

        // Position
        cout << "Chose position: " << endl;
        bool isChoseP = false;
        int selectP;
        string employeeRole;
        while (!isChoseP)
        {
            cout << "1. President" << endl;
            cout << "2. Manager" << endl;
            cout << "3. Employee" << endl;
            cout << "4. Customer" << endl;
            cout << "Input your select: ";
            cin >> selectP;
            switch (selectP)
            {
            case 1:
                isChoseP = true;
                employeeRole = "President";
                break;
            case 2:
                isChoseP = true;
                employeeRole = "Manager";
                break;
            case 3:
                isChoseP = true;
                employeeRole = "Employee";
                break;
            case 4:
                isChoseP = true;
                employeeRole = "Customer";
                break;
            default:
                cout << "Invalid selection!" << endl;
                break;
            }
        }

        // Department
        cout << "Chose department: " << endl;
        bool isChoseD = false;
        int selectD;
        int employeeDepartmentID;
        while (!isChoseD)
        {
            cout << "1. Personnel" << endl;
            cout << "2. Finance" << endl;
            cout << "Input your select: ";
            cin >> selectD;
            switch (selectD)
            {
            case 1:
                isChoseD = true;
                employeeDepartmentID = 1;
                break;
            case 2:
                isChoseD = true;
                employeeDepartmentID = 2;
                break;
            default:
                cout << "Invalid selection!" << endl;
                break;
            }
        }

        // Add
        int employeeID = company.getNumberOfEmployee() + 1;

        Employee newEmployee = Employee(employeeName, employeeDate, employeeGender, employeePhone, employeeRole, employeeID, employeeDepartmentID);

        if (!confirm("Confirm ?")) {
            cout << "Cancel !" << endl;
            return 0;
        } else {
            company.addNewEmployee(newEmployee);
            cout << "Create new employee successful!" << endl;
        }
    }
    return 1;
}

int deleteEmployee(Company& company) {
    
    int employeeId;
    cout << "Enter employee ID you want to delete: ";
    cin >> employeeId;

    bool isFound = false;

    for (int i = 0; i <  company.getNumberOfEmployee(); i++) {
        if (company.getEmployee(i)->getId() == employeeId) {
            isFound = true;
        }
    }

    if (isFound) {
        if (!confirm("Confirm ?")) {
            cout << "Cancel !" << endl;
            return 0;
        } else {
            company.deleteEmployee(employeeId);
            cout << "Delete employee successful!" << endl;
        }
    } else {
        cout << "Haven't employee with this ID !!" << endl;
        return 0;
    }

    return 1;
}

// Department handle
int addNewDepartment(Company& company) {
    // Name
    string departmentName;
    cout << "Input department name: ";
    cin.ignore();
    getline(cin, departmentName);

    departmentName = formatName(departmentName);

    // Manager
    int managerId;
    cout << "Input ID of manager: ";
    cin >> managerId;

    while (!company.hasEmployeeWithId(managerId)) {
        cout << "Can't find this manager ID!" << endl;
        cout << "Input manager ID again: ";
        cin >> managerId;
    }

    company.updateEmployeeRole(managerId, "Manager");
    Employee *manager = company.getEmployeeByID(managerId);

    Department newDepartment = Department(company.getNumberOfDepartment() + 1, departmentName, manager->getId(), manager->getName());

    company.addNewDepartment(newDepartment);

    cout << "Create new department successful!!" << endl;

    return 1;
}

int deleteDepartment(Company& company) {

    int departmentId;
    cout << "Enter department ID you want to delete: ";
    cin >> departmentId;

    bool isFound = false;

    for (int i = 0; i <  company.getNumberOfDepartment(); i++) {
        if (company.getDepartment(i)->getId() == departmentId) {
            isFound = true;
        }
    }

    if (isFound) {
        if (!confirm("Confirm ?")) {
            cout << "Cancel !" << endl;
            return 0;
        } else {
            company.deleteDepartment(departmentId);
            cout << "Delete department successful!" << endl;
        }
    } else {
        cout << "Haven't department with this ID !!" << endl;
    }

    return 1;
}

// Search
int searchEmployee(Company& company) {

    bool isChose = false;
    bool isSelect = false;
    int select;
    while (!isChose) {
        cout << "Do you want search by ?" << endl;
        cout << "1. ID" << endl;
        cout << "2. Name" << endl;
        cout << "3. Back" << endl;
        cout << "Input your select: ";
        cin >> select;
        switch (select) {
            case 1: {
                int employeeId;
                cout << "Enter employee ID you want to search: ";
                cin >> employeeId;

                while (employeeId <= 0) {
                    cout << "Invalid employee ID !" << endl;
                    cout << "Enter employee ID you want to search again: ";
                    cin >> employeeId;
                }

                bool isFound = false;

                for (int i = 0; i <  company.getNumberOfEmployee(); i++) {
                    if (company.getEmployee(i)->getId() == employeeId) {
                        printEmployee(company.getEmployee(i));
                        isFound = true;
                    }
                }

                if (!isFound) {
                    cout << "Haven't employee with this ID !!" << endl;
                    return 0;
                }
                isChose = true;
                break;
            } 
            case 2: {
                vector<Employee*> result;
                string name;
                cout << "Input employee name: ";
                cin.ignore();
                getline(cin, name);

                name = toLower(name);

                int count = 0;
                for (int i = 0; i < company.getNumberOfEmployee(); i++) {
                    string str = toLower(company.getEmployee(i)->getName());
                    if (str.find(name) != string::npos) {
                        result.push_back(company.getEmployee(i));
                        count++;
                    }
                }
                if (result.size() == 0) {
                    cout << "Haven't employee with this name !!" << endl;
                } else {
                    cout << "Find " << count << " results" << endl;
                    cout << setw(ID_SPACE) << "ID";
                    cout << setw(NAME_SPACE) << "Name";
                    cout << setw(DATE_SPACE) << "Date";
                    cout << setw(GENDER_SPACE) << "Gender";
                    cout << setw(PHONE_SPACE) << "Phone number";
                    cout << setw(POSITION_SPACE) << "Position";
                    cout << setw(WORK_AT_SPACE) << "Work at";
                    cout << endl;
                    for (int i = 0; i < result.size(); i++) {
                        cout << setw(ID_SPACE) << result[i]->getId();
                        cout << setw(NAME_SPACE) << result[i]->getName();
                        cout << setw(DATE_SPACE) << result[i]->getDate();
                        cout << setw(GENDER_SPACE) << result[i]->getGender();
                        cout << setw(PHONE_SPACE) << result[i]->getPhone();
                        cout << setw(POSITION_SPACE) << result[i]->getRole();
                        cout << setw(WORK_AT_SPACE) << company.getDepartmentById(result[i]->getDepId())->getName();
                        cout << endl;
                    }
                }

                isChose = true;
                break;
            }
                
            case 3:
                isChose = true;
                break;
            case 4:
                isChose = true;
                break;
            default:
                cout << "Invalid selection!" << endl;
                break;
        }
    }

    return 1;
}

int searchDepartment(Company& company) {

    int departmentId;

    cout << "Enter department ID you want to search: ";
    cin >> departmentId;

    while (departmentId <= 0) {
        cout << "Invalid department ID !" << endl;
        cout << "Enter department ID you want to search again: ";
        cin >> departmentId;
    }

    bool isFound = false;

    for (int i = 0; i <  company.getNumberOfDepartment(); i++) {
        if (company.getDepartment(i)->getId() == departmentId) {
            printDepartment(company.getDepartment(i));
            isFound = true;
        }
    }

    if (!isFound) {
        cout << "Haven't department with this ID !!" << endl;
    }

    return 1;
}

// Update
int updateEmployee(Company &company) {

    int employeeId;
    cout << "Enter employee ID you want to update: ";
    cin >> employeeId;

    bool isFound = false;

    for (int i = 0; i <  company.getNumberOfEmployee(); i++) {
        if (company.getEmployee(i)->getId() == employeeId) {
            isFound = true;
        }
    }

    if (!isFound) {
        cout << "Haven't employee with this ID !!" << endl;
        return 0;
    }

    bool isSelect = false;

    while(!isSelect) {
        int select;

        cout << "What do you want to edit?" << endl;
        cout << "1. Name" << endl;
        cout << "2. Date" << endl;
        cout << "3. Gender" << endl;
        cout << "4. Phone" << endl;
        cout << "5. Role" << endl;
        cout << "6. Department" << endl;

        cin >> select;

        switch (select) {
            case 1: {
                string newName; 
                cout << "Input new employee name: ";
                cin.ignore();
                getline(cin, newName);

                if (!confirm())
                    break;
                
                company.getEmployeeByID(employeeId)->setName(formatName(newName));

                cout << "Update successful!!" << endl;

                isSelect = true;
                break;
            }

            case 2: {
                string newDate; 
                cout << "Input new employee date: ";
                cin.ignore();
                getline(cin, newDate);

                if(!isValidDate(newDate)) {
                    cout << "Invalid date input!!" << endl;
                    break;
                }

                if (!confirm())
                    break;
                
                company.getEmployeeByID(employeeId)->setDate(newDate);

                cout << "Update successful!!" << endl;
                
                isSelect = true;
                break;
            }

            case 3: {
                int newGender; 
                cout << "Select new employee gender: " << endl;
                cout << "1. Male" << endl;
                cout << "2. Female" << endl;
                cout << "3. Back" << endl;
                cin >> newGender;

                switch (newGender) {
                    case 1: {
                        if (!confirm())
                            break;

                        company.getEmployeeByID(employeeId)->setGender("Male");
                        break;
                    }

                    case 2: {
                        if (!confirm())
                            break;

                        company.getEmployeeByID(employeeId)->setGender("Female");
                        break;
                    }
                    case 3: {
                        break;
                    }
                        
                    default:
                        cout << "Invalid input!!" << endl;
                        break;
                }
                
                cout << "Update successful!!" << endl;
                
                isSelect = true;
                break;
            }

            case 4: {
                string newPhone; 
                cout << "Input new employee phone: ";
                cin.ignore();
                getline(cin, newPhone);

                if(!checkPhoneInput(newPhone)) {
                    cout << "Invalid phone input!!" << endl;
                    break;
                }

                if (!confirm())
                    break;
                
                company.getEmployeeByID(employeeId)->setPhone(newPhone);

                cout << "Update successful!!" << endl;
                
                isSelect = true;
                break;
            }

            case 5: {
                int newRole; 
                cout << "Select new employee role: " << endl;
                cout << "1. Employee" << endl;
                cout << "2. Manager" << endl;
                cout << "3. Customer" << endl;
                cout << "4. President" << endl;
                cout << "5. Back" << endl;
                cin >> newRole;

                switch (newRole) {
                    case 1: {
                        if (!confirm())
                            break;

                        company.getEmployeeByID(employeeId)->setRole("Employee");
                        break;
                    }
                    case 2: {
                        if (!confirm())
                            break;

                        company.getEmployeeByID(employeeId)->setRole("Manager");
                        break;
                    }
                    case 3: {
                        if (!confirm())
                            break;

                        company.getEmployeeByID(employeeId)->setRole("Customer");
                        break;
                    }
                    case 4: {
                        if (!confirm())
                            break;

                        company.getEmployeeByID(employeeId)->setRole("President");
                        break;
                    }
                    case 5: {
                        break;
                    }
                    default:
                        cout << "Invalid input!!" << endl;
                        break;
                }
                
                cout << "Update successful!!" << endl;
                
                isSelect = true;
                break;
            }

            case 6: {
                int newDep; 
                cout << "Select new employee department: " << endl;
                cout << "1. Personnel" << endl;
                cout << "2. Finance" << endl;
                cout << "3. Back" << endl;
                cin >> newDep;

                switch (newDep) {
                    case 1: {
                        if (!confirm())
                            break;

                        company.getEmployeeByID(employeeId)->setDepId(1);
                        break;
                    }
                    case 2: {
                        if (!confirm())
                            break;

                        company.getEmployeeByID(employeeId)->setDepId(2);
                        break;
                    }
                    case 3: {
                        break;
                    }
                    default:
                        cout << "Invalid input!!" << endl;
                        break;
                }
                
                cout << "Update successful!!" << endl;
                
                isSelect = true;
                break;
            }

            default: {
                cout << "Invalid selection!" << endl;
                break;
            }
        }
    }

    return 1;
}

int updateDepartment(Company &company) {
    int departmentId;
    cout << "Enter department ID you want to update: ";
    cin >> departmentId;

    bool isFound = false;

    for (int i = 0; i < company.getNumberOfDepartment(); i++) {
        if (company.getDepartment(i)->getId() == departmentId) {
            isFound = true;
        }
    }

    if (!isFound) {
        cout << "Haven't department with this ID !!" << endl;
        return 0;
    }

    bool isSelect = false;

    while(!isSelect) {
        int select;

        cout << "What do you want to edit?" << endl;
        cout << "1. Manager" << endl;
        cout << "2. Back" << endl;

        cin >> select;

        switch (select) {
            case 1: {
                int newManager; 
                cout << "Input manager ID: ";
                cin >> newManager;

                if (!confirm())
                    break;
                
                bool isHasEmployee = false;

                for (int i = 0; i <  company.getNumberOfEmployee(); i++) {
                    if (company.getEmployee(i)->getId() == newManager) {
                        isHasEmployee = true;
                    }
                }

                if (!isHasEmployee) {
                    cout << "Cannot find employee with this ID!!" << endl;
                    break;
                } else {
                    company.getDepartmentById(departmentId)->setManagerId(newManager);
                    company.getDepartmentById(departmentId)->setManagerName(company.getEmployeeByID(newManager)->getName());

                    cout << "Update successful!!" << endl;
                }

                isSelect = true;
                break;
            }

            case 2: {
                isSelect = true;
                break;
            }

            default: {
                cout << "Invalid selection!" << endl;
                break;
            }
        }
    }
    return 1;
}

int update(Company &company) {

    bool isSelect = false;

    while (!isSelect) {
        cout << "Update information" << endl;
        cout << "1. Department" << endl;
        cout << "2. Employee" << endl;
        cout << "3. Back" << endl;

        int select;
        
        cout << "Input your select: ";
        cin >> select;

        switch (select) {
            case 1: {
                updateDepartment(company);
                isSelect = true;
                break;
            }

            case 2: {
                updateEmployee(company);
                isSelect = true;
                break;
            }

            case 3: {
                isSelect = true;
                break;
            }

            default: {
                cout << "Invalid selection!" << endl;
                break;
            }
        }
    }


}
// Arrange
int arrange(Company& company) {

    company.arrangeEmployees();
    company.arrangeDepartments();

    cout << "Arrange successful !" << endl;

    return 1;
}

void writeDataToFile(Company &company) {

    // Employee write data
    char fileEmployees[30] = EMPLOYEE_DATA_PATH;

    // Open file and write data in the end of file
    cout << "Exporting data to " << fileEmployees << "..." << endl;

    ofstream fileEmployeesData(fileEmployees);

    // ADD number of employee
    fileEmployeesData << company.getNumberOfEmployee();
    fileEmployeesData << endl;

    // ADD labels
    fileEmployeesData << setw(ID_SPACE) << "ID";
    fileEmployeesData << setw(NAME_SPACE) << "Name";
    fileEmployeesData << setw(DATE_SPACE) << "Date";
    fileEmployeesData << setw(GENDER_SPACE) << "Gender";
    fileEmployeesData << setw(PHONE_SPACE) << "Phone number";
    fileEmployeesData << setw(POSITION_SPACE) << "Position";
    fileEmployeesData << setw(WORK_AT_SPACE) << "Work at";
    fileEmployeesData << endl;

    for (int i = 0; i < company.getNumberOfEmployee(); i++ ){
        Employee *employee = company.getEmployee(i);

        fileEmployeesData << setw(ID_SPACE) << employee->getId();
        fileEmployeesData << setw(NAME_SPACE) << employee->getName();
        fileEmployeesData << setw(DATE_SPACE) << employee->getDate();
        fileEmployeesData << setw(GENDER_SPACE) << employee->getGender();
        fileEmployeesData << setw(PHONE_SPACE) << employee->getPhone();
        fileEmployeesData << setw(POSITION_SPACE) << employee->getRole();
        fileEmployeesData << setw(WORK_AT_SPACE) << employee->getDepId();
        fileEmployeesData << endl;
    }

    cout << "Exported to " << fileEmployees << " successful." << endl;

    // Department write data
    char fileDepartments[30] = DEPARTMENT_DATA_PATH;

    // Open file and write data in the end of file
    cout << "Exporting data to " << fileDepartments << "..." << endl;

    ofstream fileDepartmentsData(fileDepartments);

    // ADD number of employee
    fileDepartmentsData << company.getNumberOfDepartment();
    fileDepartmentsData << endl;

    // ADD labels
    fileDepartmentsData << setw(ID_SPACE) << "ID";
    fileDepartmentsData << setw(NAME_SPACE) << "Name";
    fileDepartmentsData << setw(NAME_SPACE) << "Manager ID";
    fileDepartmentsData << setw(NAME_SPACE) << "Manager name";
    fileDepartmentsData << endl;

    for (int i = 0; i < company.getNumberOfDepartment(); i++ ){
        Department *department = company.getDepartment(i);

        fileDepartmentsData << setw(ID_SPACE) << department->getId();
        fileDepartmentsData << setw(NAME_SPACE) << department->getName();
        fileDepartmentsData << setw(NAME_SPACE) << department->getManagerId();
        fileDepartmentsData << setw(NAME_SPACE) << department->getManagerName();
        fileDepartmentsData << endl;
    }

    cout << "Exported to " << fileDepartments << " successful." << endl;
}

Employee handleDataEmployeeFromLine(string data) {

    // Get ID from file
    int id = stoi(trim(data.substr(0, ID_SPACE)));

    // Get name from file
    string name = trim(data.substr(ID_SPACE, NAME_SPACE));

    // Get date from file
    string date = trim(data.substr(ID_SPACE + NAME_SPACE, DATE_SPACE));

    // Get gender from file
    string gender = trim(data.substr(ID_SPACE + NAME_SPACE + DATE_SPACE, GENDER_SPACE));

    // Get phone from file
    string phone = trim(data.substr(ID_SPACE + NAME_SPACE + DATE_SPACE + GENDER_SPACE, PHONE_SPACE));

    // Get role from file
    string role = trim(data.substr(ID_SPACE + NAME_SPACE + DATE_SPACE + GENDER_SPACE + PHONE_SPACE, POSITION_SPACE));

    // Get department from file
    int depId = stoi(trim(data.substr(ID_SPACE + NAME_SPACE + DATE_SPACE + GENDER_SPACE + PHONE_SPACE + POSITION_SPACE, WORK_AT_SPACE)));
    
    return Employee(name, date, gender, phone, role, id, depId);

}

Department handleDataDepartmentFromLine(string data) {
    // Get ID from file
    int id = stoi(trim(data.substr(0, ID_SPACE)));

    // Get name from file
    string name = trim(data.substr(ID_SPACE, NAME_SPACE));

    // Get manager id from file
    int manager_id = stoi(trim(data.substr(ID_SPACE + NAME_SPACE, NAME_SPACE)));
    
    // Get manager name from file
    string manager_name = trim(data.substr(ID_SPACE + NAME_SPACE + NAME_SPACE, NAME_SPACE));

    return Department(id, name, manager_id, manager_name);
}

void importDataFromFile(Company &company) {
    // Read employee data from file
    char fileEmployee[30] = EMPLOYEE_DATA_PATH;
    cout << "Importing data from " << fileEmployee << "..." << endl;

    ifstream fileEmployeeIn(fileEmployee);

    // Get number of employee at first line
    int numOfEmployees;
    fileEmployeeIn >> numOfEmployees;

    string dataEmployee;
    // Skip first and second line in file
    getline(fileEmployeeIn, dataEmployee);
    getline(fileEmployeeIn, dataEmployee);

    // Get data from file
    for (int i = 0; i < numOfEmployees; i++)
    {
        getline(fileEmployeeIn, dataEmployee);
        Employee employee = handleDataEmployeeFromLine(dataEmployee);
        company.addNewEmployee(employee);
    }

    cout << "Importing data from " << fileEmployee << " successful." << endl;
    fileEmployeeIn.close();

    // Read department data from file
    char fileDepartment[30] = DEPARTMENT_DATA_PATH;
    cout << "Importing data from " << fileDepartment << "..." << endl;

    ifstream fileDepartmentIn(fileDepartment);

    // Get number of department at first line
    int numOfDepartment;
    fileDepartmentIn >> numOfDepartment;

    string dataDepartment;
    // Skip first and second line in file
    getline(fileDepartmentIn, dataDepartment);
    getline(fileDepartmentIn, dataDepartment);

    // Get data from file
    for (int i = 0; i < numOfDepartment; i++)
    {
        getline(fileDepartmentIn, dataDepartment);
        Department department = handleDataDepartmentFromLine(dataDepartment);
        company.addNewDepartment(department);
    }

    cout << "Importing data from " << fileDepartment << " successful." << endl;
    fileDepartmentIn.close();
};

void App(Company& company, bool& isRunning) {
    cout << "==========HUMAN RESOURCE MANAGEMENT======" << endl;
    cout << "=================MENU====================" << endl;
    cout << "*   1. Add new employee                 *" << endl; // done
    cout << "*   2. Delete employee                  *" << endl; // done
    cout << "*   3. Search employee                  *" << endl; // done
    cout << "*   4. Add new department               *" << endl; // done
    cout << "*   5. Delete department                *" << endl; // done
    cout << "*   6. Search department                *" << endl; // done
    cout << "*   7. Update                           *" << endl; // done
    cout << "*   8. Arrange                          *" << endl; // done
    cout << "*   9  Display                          *" << endl; // done
    cout << "*   10. Export data to file             *" << endl; // done
    cout << "*   0. Exit                             *" << endl; // 
    cout << "=========================================" << endl;
    cout << "Input your select: ";
    int key;
    cin >> key;
    switch (key)
    {
    case 1:
        addNewEmployee(company);
        pressAnyKey();
        break;
    case 2:
        deleteEmployee(company);
        pressAnyKey();
        break;
    case 3:
        searchEmployee(company);
        pressAnyKey();
        break;
    case 4:
        addNewDepartment(company);
        pressAnyKey();
        break;
    case 5:
        deleteDepartment(company);
        pressAnyKey();
        break;
    case 6:
        searchDepartment(company);
        pressAnyKey();
        break;
    case 7:
        update(company);
        pressAnyKey();
        break;
    case 8:
        arrange(company);
        pressAnyKey();
        break;
    case 9:
        company.displayAllEmployee();
        cout << endl;
        company.displayAllDepartment();
        pressAnyKey();
        break;
    case 10:
        writeDataToFile(company);
        pressAnyKey();
        break;
    case 0:
        isRunning = false;
        cout << "Shutdown the program!";
        pressAnyKey();
        break;
    default:
        cout << "Without this function !!" << endl;
        pressAnyKey();
        break;
    }
}

#endif
