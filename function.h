#ifndef FUNCTION_H
#define FUNCTION_H

#include <iostream>
#include <fstream>

#include "classes.h"
#include "parameters.h"

using namespace std;

void app(Company &company) {

};

void addNewEmployee() {
    cout << "Add new employee !" << endl;
};

template <class Type>

void writeDataToFile(Type value, string filePath) {

    ifstream isHasFile(filePath);

    if (!isHasFile) {
        ofstream createFile(filePath);

        cout << "File does not exist !!" << endl;

        if (!createFile) {
            cout << "Error !!!" << endl;
            return;
        }

        createFile.close();
        cout << "Created file successful." << endl;
    }

    // Open file and write data in the end of file
    ofstream file(filePath, ios::app);

    if (file.is_open()) {
        cout << "Exporting data to " << filePath << "..." << endl;

        file << value << endl;
    }

}

void importDataFromFile() {

};

#endif