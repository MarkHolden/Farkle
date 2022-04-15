#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include "Rules.h"

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
