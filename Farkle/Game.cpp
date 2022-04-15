#pragma once
#include <vector>
#include "Game.h"
#include "Input.h"
#include "Player.h"

using namespace std;

void Game::Play() {
    if (Players.empty()) { AddPlayers(); }

    int choice = -1;
    bool isFinalRound = false;
    while (choice != 0) {
        DisplayMenu(isFinalRound);
        choice = Input::ReadInt("Enter Choice: ", 0, 2);

        switch (choice) {
        case 1:
            if (isFinalRound) {
                PlayFinalRound();
                return;
            }
            
            PlayRound();
            break;

        case 2:
            DisplayScores();
            break;

        case 0:
            if (!Input::ShouldContinue("Exiting will lose game progress. Are you sure?")) {
                choice = -1;
            }
        default:
            break;
        }
        isFinalRound = AreAnyPlayersOverTenThousand();
    }
}

void Game::DisplayMenu(bool isFinalRound) const {
    cout << "Game Menu:" << endl;
    cout << "  1. Play the " << (isFinalRound ? "final" : "next") << " Round" << endl;
    cout << "  2. View Scores" << endl;
    cout << "  0. Exit" << endl;
}

void Game::PlayRound() {
    for (Player& p : Players) {
        cout << endl << "Next up: " << p.GetName() << "!\n";
        p.PlayRound();
        if (p.HasBrokenTenThousand()) {
            cout << p.GetName() << " has accrued more than ten thousand points!\n";
            cout << "In the final round, every player except " << p.GetName() << " will have a chance to beat the score of " << p.GetScore() << endl;
            return;
        }
    }
}

void Game::PlayFinalRound() {
    for (Player& p : Players) {
        if (!p.HasBrokenTenThousand()) { // If you are the one that broke 10k, you don't get an additional turn in the final round.
            cout << endl << "Next up: " << p.GetName() << "!\n";
            p.PlayRound();
        }
    }

    cout << "The final scores are:\n";
    DisplayScores();
    Player winner = *max_element(Players.begin(), Players.end(), [](Player const& left, Player const& right) { return left.GetScore() < right.GetScore(); });
    cout << "The winner is " << winner.GetName() << "!\n";
}

void Game::DisplayScores() const {
    cout << "\tScore Card\n";
    cout << "_______________________________\n";
    for (Player p : Players) {
        cout << p.ToString() << endl;
    }
    cout << endl;
}

void Game::AddPlayers() {
    const int playerCount = Input::ReadInt("Enter the number of players ", minPlayers, maxPlayers);

    for (int i = 0; i < playerCount; ++i) {
        cout << "Player " << i + 1 << ", ";
        Player player;
        Players.push_back(player);
    }
}
