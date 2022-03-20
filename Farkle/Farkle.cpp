//============================================================================
// Name        : Farkle.cpp
// Author      : Mark Holden
// Date        : 3/19/2022
// Course      : IT-312 Software Development with C++ .NET
// Version     : 1.0
// Description : Entry Point and Main Menu for Farkle
//============================================================================

#include <iostream>
#include "input.h"
#include "Game.h"
#include "Rules.h"
using namespace std;

/// <summary>
/// Display the application menu.
/// </summary>
/// <param name="gameIsInProgress">If there is already a game in progress.</param>
void DisplayMenu(bool gameIsInProgress);

/// <summary>
/// Start a new Game.
/// </summary>
/// <param name="game"></param>
void StartNew(Game* game);

/// <summary>
/// Continue an in progress game.
/// </summary>
/// <param name="game">The game that is in progress.</param>
void Continue(Game* game);

int main()
{
    cout << "Welcome to Farkle\n\n";
    Game* game = nullptr;
    int choice = -1;
    while (choice != 0)
    {
        DisplayMenu(game != nullptr);
        choice = Input::ReadInt("Enter Choice: ", 0, 3);

        switch (choice) {
        case 1:
            Rules::Display();
            break;

        case 2:
            StartNew(game);
            break;

        case 3:
            Continue(game);
            break;
        }
    }

    
    
}

void Continue(Game* game)
{
    if (game != nullptr)
    {
        game->Play();
    }
    else
    {
        cout << "No game to Continue. Start a New Game.";
    }
}

void StartNew(Game* game)
{
    if (game != nullptr)
    {
        delete game;
    }

    game = new Game();
    game->Play();
}

void DisplayMenu(bool gameIsInProgress)
{
    cout << "Menu:" << endl;
    cout << "  1. Display Farkle Rules" << endl;
    cout << "  2. New Farkle Game" << endl;
    if (gameIsInProgress)
    {
        cout << "  3. Continue Farkle Game" << endl;
    }
    cout << "  0. Exit" << endl;
}
