//============================================================================
// Name        : Die.cpp
// Author      : Mark Holden
// Date        : 3/26/2022
// Course      : IT-312 Software Development with C++ .NET
// Version     : 1.0
// Description : Represents a Die object.
//============================================================================

#pragma once
#include "Die.h"
#include <iostream>

using namespace std;

Die::Die() {
    srand((int)time(nullptr)); // Initialize random number generator.
}

void Die::Display(int row) const {
    if (row == 0) {
        cout << " ___ \t";
    }
    else {
        switch (Value) {
        case 1:
            switch (row) {
            case 1: cout << "|   |\t";
                break;
            case 2: cout << "| o |\t";
                break;
            case 3: cout << "|___|\t";
                break;
            default:
                break;
            }
            break;
        case 2:
            switch (row) {
            case 1: cout << "|  o|\t";
                break;
            case 2: cout << "|   |\t";
                break;
            case 3: cout << "|o__|\t";
                break;
            default:
                break;
            }
            break;
        case 3:
            switch (row) {
            case 1: cout << "|  o|\t";
                break;
            case 2: cout << "| o |\t";
                break;
            case 3: cout << "|o__|\t";
                break;
            default:
                break;
            }
            break;
        case 4:
            switch (row) {
            case 1: cout << "|o o|\t";
                break;
            case 2: cout << "|   |\t";
                break;
            case 3: cout << "|o_o|\t";
                break;
            default:
                break;
            }
            break;
        case 5:
            switch (row) {
            case 1: cout << "|o o|\t";
                break;
            case 2: cout << "| o |\t";
                break;
            case 3: cout << "|o_o|\t";
                break;
            default:
                break;
            }
            break;
        case 6:
            switch (row) {
            case 1:
            case 2: cout << "|o o|\t";
                break;
            case 3: cout << "|o_o| \t";
                break;
            default:
                break;
            }
            break;
        default:
            break;
        }
    }
}
