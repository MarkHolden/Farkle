#pragma once
#include <algorithm>
#include <vector>
#include "Player.h"

class Game {
public:
    /// <summary>
    /// Play the Game.
    /// </summary>
    void Play();

    /// <summary>
    /// Are any players over ten thousand?
    /// </summary>
    /// <returns>Bool of if any players have broken 10,000 or not.</returns>
    bool AreAnyPlayersOverTenThousand() {
        return any_of(Players.begin(), Players.end(), [](Player p) { return p.HasBrokenTenThousand(); });
    }

private:
    /// <summary>
    /// Vector of the Game's players.
    /// </summary>
    std::vector<Player> Players;

    /// <summary>
    /// Anywhere between 2 and 86 players may play in one game. Any more
    /// than that, and it's just way too long before you get to roll the
    /// dice again, let alone the size of the room you'd need.
    /// Source: https://officialfarklerules.com/rules-of-the-game/
    /// </summary>
    const int maxPlayers = 86;

    /// <summary>
    /// Can't play by yourself.
    /// </summary>
    const int minPlayers = 2;

    /// <summary>
    /// Display the Game play menu.
    /// </summary>
    void DisplayMenu(bool isFinalRound) const;

    /// <summary>
    /// Play the next round of the Game.
    /// </summary>
    void PlayRound();

    /// <summary>
    /// Play the final round of the Game.
    /// </summary>
    void PlayFinalRound();

    /// <summary>
    /// Display the Current score card.
    /// </summary>
    void DisplayScores() const;

    /// <summary>
    /// Add players. Only called when the game starts the first time.
    /// </summary>
    void AddPlayers();
};