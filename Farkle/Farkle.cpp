//============================================================================
// Name        : Farkle.cpp
// Author      : Mark Holden
// Date        : 3/19/2022
// Course      : IT-312 Software Development with C++ .NET
// Version     : 1.0
// Description : Entry Point and Main Menu for Farkle
//============================================================================

#pragma once
#include <iostream>
#include "Input.h"
#include "Game.h"
#include "Rules.h"
using namespace std;

/// <summary>
/// Display the application menu.
/// </summary>
void DisplayMenu();

/// <summary>
/// Start a new Game.
/// </summary>
void NewGame();

int main() {
    cout << "Welcome to Farkle\n\n"
       "                                          \n"
       "                 _____                    \n"
       "                / \\'. \\                 \n"
       "               / : \\___\\                \n"
       "               \\' / .  / _____           \n"
       "    _____       \\/____/ / .  /\\         \n"
       "   / \\'. \\    _____    /____/..\\       \n"
       "  / : \\___\\  / .  /\\   \\'  '\\  /     \n"
       "  \\' / .  / /____/..\\   \\'__'\\/       \n"
       "   \\/____/  \\'  '\\  /                  \n"
       "             \\'__'\\/                    \n"
       "        _____                             \n"
       "       / .  /\\                           \n"
       "      /____/..\\    _____                 \n"
       "      \\'  '\\  /   / \\'. \\             \n"
       "       \\'__'\\/   / : \\___\\            \n"
       "                 \\' / .  /               \n"
       "                  \\/____/                \n"
        "\t\t\t\tOriginal art by valkyrie\n\n"; // https://www.asciiart.eu/miscellaneous/dice
    int choice = -1;
    while (choice != 0)     {
        DisplayMenu();
        choice = Input::ReadInt("Enter Choice: ", 0, 3);

        switch (choice) {
        case 1:
            Rules::Display();
            break;

        case 2:
            NewGame();
            break;
        default:
            break;
        }
    }
}

void NewGame() {
    auto game = Game();
    game.Play();
}

void DisplayMenu() {
    cout << "Menu:" << endl;
    cout << "  1. Display Farkle Rules" << endl;
    cout << "  2. New Farkle Game" << endl;
    cout << "  0. Exit" << endl;
}
