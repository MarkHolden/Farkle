#pragma once
#include <string>
#include <vector>
#include "Die.h"
#include "Input.h"
#include "ScoreOption.h"

class Player {
public:
    /// <summary>
    /// Default Constructor.
    /// </summary>
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
    /// If the Player has broken the 10,000 points required to enter the final round.
    /// </summary>
    bool HasBrokenTenThousand() const { return Score >= 10000; }

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
    /// Gets the counts of each face value.
    /// <para>Includes 7 elements so the index is the same as the face value (ignore index 0).</para>
    /// </summary>
    /// <param name="dice">Dice vector for which to return counts.</param>
    /// <returns>A 7 element vector of face value counts.</returns>
    void SetCounts(std::vector<Die> const& dice, int * counts) const;

    /// <summary>
    /// Output the player's score option menu.
    /// </summary>
    /// <param name="dice">Vector of dice which have been rolled.</param>
    /// <param name="canRollAgain">If the player has already saved at least one die and can roll again.</param>
    /// <param name="runningTotal">The current number of points the player has accrued this turn.</param>
    /// <param name="unrolledDiceCount">The current number of dice that have not been rolled.</param>
    void DisplayScoreOptionMenu(std::vector<ScoreOption> const& options, bool canRollAgain, int runningTotal, int unrolledDiceCount) const;

    /// <summary>
    /// Get the maximum number the user should be allowed to select.
    /// </summary>
    /// <param name="options">Vector of the options the user has available.</param>
    /// <param name="madeSelectionSinceRoll">If the user has already made a selection since the last roll (allows the user to roll again).</param>
    /// <returns>Maximum choice.</returns>
    int GetMaximumChoice(std::vector<ScoreOption> const& options, bool madeSelectionSinceRoll) const;

    /// <summary>
    /// Get the minimum number the user should be allowed to select.
    /// </summary>
    /// <param name="runningTotal">Current number of points accrued this turn.</param>
    /// <returns>0 if the user can end their turn, otherwise 1.</returns>
    int GetMinimumChoice(int const& runningTotal) const;
};