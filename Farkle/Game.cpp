#include "Game.h"
#include "Input.h"
#include "Player.h"
#include <vector>

using namespace std;

Game::Game()
{
    for (int i = 0; i < 6; ++i)
    {
        Die die = {};
        Dice.push_back(die);
    }
}

void Game::Play()
{
    if (Players.empty()) { AddPlayers(); }

    int choice = -1;
    while (choice != 0)
    {
        DisplayMenu();
        choice = Input::ReadInt("Enter Choice: ", 0, 2);

        switch (choice) {
        case 1:
            PlayRound();
            break;

        case 2:
            DisplayScores();
            break;

        case 0:
            string confirmation = Input::ReadString("Exiting will lose game progress. Are you sure? [Y/N] ");
            if (confirmation != "Y" && confirmation != "y")
            {
                choice = -1;
            }
        }
    }
}

void Game::DisplayMenu()
{
    cout << "Game Menu:" << endl;
    cout << "  1. Play the next Round" << endl;
    cout << "  2. View Scores" << endl;
    cout << "  0. Exit" << endl;
}

void Game::PlayRound()
{
}

void Game::DisplayScores()
{
    cout << "\tScore Card\n";
    cout << "_______________________________\n";
    for (Player p : Players)
    {
        cout << p.ToString() << endl;
    }
    cout << endl;
}

void Game::AddPlayers()
{
    const int playerCount = Input::ReadInt("Enter the number of players ", minPlayers, maxPlayers);

    for (int i = 0; i < playerCount; ++i)
    {
        Player player = { "Player " + to_string(i + 1) };
        Players.push_back(player);
    }
}
