#include "Die.h"
#include "Player.h"
#include <vector>

class Game
{
public:
    /// <summary>
    /// Play the Game.
    /// </summary>
    void Play();
private:
    /// <summary>
    /// The Game Dice.
    /// </summary>
    std::vector<Die> Dice;

    /// <summary>
    /// Vector of the Game's players.
    /// </summary>
    std::vector<Player> players;

    /// <summary>
    /// Anywhere between 2 and 86 players may play in one game. Any more
    /// than that, and it’s just way too long before you get to roll the
    /// dice again, let alone the size of the room you’d need.
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
    void DisplayMenu();

    /// <summary>
    /// Add players. Only called when the game starts the first time.
    /// </summary>
    void AddPlayers();
};