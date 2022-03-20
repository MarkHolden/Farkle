#pragma once
#include "Die.h"
#include "ScoreOption.h"
#include <string>
#include <vector>

class Player {
public:
    /// <summary>
    /// Default Constructor.
    /// </summary>
    /// <param name="name">The name of the player.</param>
    Player(std::string name) : Name(name), HasBrokenOneThousand(false), Score(0) {}

    /// <summary>
    /// Play the round.
    /// </summary>
    void PlayRound();

    /// <summary>
    /// Get the Current number of points a player has.
    /// </summary>
    /// <returns>Number of points.</returns>
    int GetScore() { return Score; }

    /// <summary>
    /// Get the Player's name.
    /// </summary>
    /// <returns>Player Name.</returns>
    std::string GetName() { return Name; }

    /// <summary>
    /// Get a string representation of the Player.
    /// </summary>
    /// <returns>String representation of the Player.</returns>
    std::string ToString() { return Name + "\t|\t" + std::to_string(Score); }

private:
    /// <summary>
    /// Internal score counter.
    /// </summary>
    int Score;

    /// <summary>
    /// Name of the player.
    /// </summary>
    std::string Name;

    /// <summary>
    /// If the Player has already broken the 1000 points required to "get on the board".
    /// </summary>
    bool HasBrokenOneThousand;

    void RollDice(std::vector<Die>& dice, bool rollAll = false);

    std::vector<ScoreOption> CalculateScoreOptions(std::vector<Die>& dice);

    bool AreAllDiceSaved(std::vector<Die>& dice);

    void DisplayScoreOptionMenu(std::vector<ScoreOption>& options, bool canRollAgain, int runningTotal);
};