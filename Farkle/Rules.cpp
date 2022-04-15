#pragma once
#include "Rules.h"
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

void Rules::Display() {
    string line;
    ifstream rulesFile;
    rulesFile.open("..\\FarkleRules.txt");
    if (rulesFile.is_open()) {
        while (getline(rulesFile, line)) {
            cout << line << endl;
        }
        rulesFile.close();
    }
}
