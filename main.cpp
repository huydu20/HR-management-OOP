#include <iostream>
#include <vector>
#include <string.h>

#include "function.h"
#include "classes.h"
#include "parameters.h"

using namespace std;

int main () {
	Company company;
    importDataFromFile(company);

    bool isRunning = true;

    while (isRunning) {
        App(company, isRunning);
        system("cls");
    }
    
	return 0;
}


