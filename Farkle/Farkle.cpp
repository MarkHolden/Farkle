//============================================================================
// Name        : Farkle.cpp
// Author      : Mark Holden
// Date        : 3/19/2022
// Course      : IT-312 Software Development with C++ .NET
// Version     : 1.0
// Description : Entry Point and Main Menu for Farkle
//============================================================================

#include <iostream>
#include "Input.h"
#include "Game.h"
#include "Rules.h"
using namespace std;

/// <summary>
/// Display the application menu.
/// </summary>
/// <param name="gameIsInProgress">If there is already a game in progress.</param>
void DisplayMenu();

/// <summary>
/// Start a new Game.
/// </summary>
/// <param name="game"></param>
void Play();

int main()
{
    cout << "Welcome to Farkle\n\n";
    int choice = -1;
    while (choice != 0)
    {
        DisplayMenu();
        choice = Input::ReadInt("Enter Choice: ", 0, 3);

        switch (choice) {
        case 1:
            Rules::Display();
            break;

        case 2:
            Play();
            break;
        }
    }
}

void Play()
{
    Game* game = new Game();
    game->Play();
}

void DisplayMenu()
{
    cout << "Menu:" << endl;
    cout << "  1. Display Farkle Rules" << endl;
    cout << "  2. New Farkle Game" << endl;
    cout << "  0. Exit" << endl;
}
