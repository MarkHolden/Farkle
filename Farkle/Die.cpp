#include "Die.h"
#include <iostream>

using namespace std;

Die::Die()
{
    srand(time(0));  // Initialize random number generator.
}

string Die::ToString()
{
    return std::string();
}

void Die::Display()
{
    switch (Value) {
    case 1:
        cout << " ___\n"
            "|   |\n"
            "| o |\n"
            "|___|\n";
        break;
    case 2:
        cout << " ___\n"
            "|  o|\n"
            "|   |\n"
            "|o__|\n";
        break;
    case 3:
        cout << " ___\n"
            "|  o|\n"
            "| o |\n"
            "|o__|\n";
        break;
    case 4:
        cout << " ___\n"
            "|o o|\n"
            "|   |\n"
            "|o_o|\n";
        break;
    case 5:
        cout << " ___\n"
            "|o o|\n"
            "| o |\n"
            "|o_o|\n";
        break;
    case 6:
        cout << " ___\n"
            "|o o|\n"
            "|o o|\n"
            "|o_o|\n";
        break;
    }

}
