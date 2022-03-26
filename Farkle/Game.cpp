#pragma once
#include "Game.h"
#include "Input.h"
#include "Player.h"
#include <vector>

using namespace std;

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
            if (!Input::ShouldContinue("Exiting will lose game progress. Are you sure?")) {
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
    for (Player &p : Players)
    {
        cout << endl << "Next up: " << p.GetName() << "!\n";
        p.PlayRound();
    }
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
