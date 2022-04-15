#pragma once
#include "Die.h"
#include "ScoreOption.h"
#include "Input.h"
#include <string>
#include <vector>

class Player {
public:
    /// <summary>
    /// Default Constructor.
    /// </summary>
    /// <param name="name">The name of the player.</param>
    Player() {
        Name = Input::ReadString("Enter your name: ");
    }

    /// <summary>
    /// Play the round.
    /// </summary>
    void PlayRound();

    /// <summary>
    /// Get the Current number of points a player has.
    /// </summary>
    /// <returns>Number of points.</returns>
    int GetScore() const { return Score; }

    /// <summary>
    /// Get the Player's name.
    /// </summary>
    /// <returns>Player Name.</returns>
    std::string GetName() const { return Name; }

    /// <summary>
    /// Get a string representation of the Player.
    /// </summary>
    /// <returns>String representation of the Player.</returns>
    std::string ToString() const { return Name + "\t|\t" + std::to_string(Score); }

private:
    /// <summary>
    /// Internal score counter.
    /// </summary>
    int Score = 0;

    /// <summary>
    /// Name of the player.
    /// </summary>
    std::string Name;

    /// <summary>
    /// If the Player has already broken the 1000 points required to "get on the board".
    /// </summary>
    bool HasBrokenOneThousand = false;

    /// <summary>
    /// Rolls Dice in the vector if they have not been saved.
    /// </summary>
    /// <param name="dice">Vector of dice to roll.</param>
    /// <param name="rollAll">If this is true, all dice are rolled whether they are saved or not.</param>
    void RollDice(std::vector<Die>& dice, bool rollAll = false) const;

    /// <summary>
    /// Based on the current roll, not including saved dice, create a vector of the score options.
    /// </summary>
    /// <param name="dice">Vector of dice which have been rolled.</param>
    /// <returns>A vector of ScoreOptions.</returns>
    std::vector<ScoreOption> CalculateScoreOptions(std::vector<Die> const& dice) const;

    /// <summary>
    /// Are all the dice saved?
    /// </summary>
    /// <param name="dice">Vector of dice which have been rolled.</param>
    /// <returns>Bool of if all dice are saved or not.</returns>
    bool AreAllDiceSaved(std::vector<Die> const& dice) const;

    /// <summary>
    /// Output the player's score option menu.
    /// </summary>
    /// <param name="dice">Vector of dice which have been rolled.</param>
    /// <param name="canRollAgain">If the player has already saved at least one die and can roll again.</param>
    /// <param name="runningTotal">The current number of points the player has accrued this turn.</param>
    void DisplayScoreOptionMenu(std::vector<ScoreOption> const& options, bool canRollAgain, int runningTotal) const;
};