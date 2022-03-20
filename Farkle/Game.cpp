#include "Game.h"
#include "Input.h"
#include "Player.h"
#include <vector>

void Game::Play()
{
    if (players.empty()) { AddPlayers(); }
}

void Game::DisplayMenu()
{
    cout << "Menu:" << endl;
    cout << "  1. Display Farkle Rules" << endl;
    cout << "  2. Play Farkle" << endl;
    cout << "  0. Exit" << endl;
}

void Game::AddPlayers()
{
    const int playerCount = Input::ReadInt("Enter the number of players ", minPlayers, maxPlayers);

    for (int i = 0; i < playerCount; ++i)
    {
        Player player = {};
        players.push_back(player);
    }
}
