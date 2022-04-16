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
    /// The running total of the player's score for this round only.
    /// </summary>
    int RunningTotal = 0;

    /// <summary>
    /// Whether the player has saved dice since the previous roll.
    /// </summary>
    bool SavedDiceSinceRoll = false;

    /// <summary>
    /// The Player's Dice to roll.
    /// </summary>
    std::vector<Die> Dice = std::vector<Die>(6);

    /// <summary>
    /// Rolls Dice in the vector if they have not been saved.
    /// </summary>
    /// <param name="rollAll">Overrides saved dice and rolls them all anyway.</param>
    void RollDice(bool rollAll = false);

    /// <summary>
    /// Based on the current roll, not including saved dice, create a vector of the score options.
    /// </summary>
    /// <returns>A vector of ScoreOptions.</returns>
    std::vector<ScoreOption> CalculateScoreOptions() const;

    /// <summary>
    /// Gets the counts of each face value.
    /// <para>Includes 7 elements so the index is the same as the face value (ignore index 0).</para>
    /// </summary>
    /// <returns>A 7 element vector of face value counts.</returns>
    void SetCounts(int * counts) const;

    /// <summary>
    /// Output the player's score option menu.
    /// </summary>
    /// <param name="options">Vector ScoreOptions available to the player.</param>
    void DisplayScoreOptionMenu(std::vector<ScoreOption> const& options) const;

    /// <summary>
    /// Get the maximum number the user should be allowed to select.
    /// </summary>
    /// <param name="optionsCount">The number of options the user has available.</param>
    /// <returns>Maximum choice.</returns>
    int GetMaximumChoice(int const& optionsCount) const;

    /// <summary>
    /// Get the minimum number the user should be allowed to select.
    /// </summary>
    /// <returns>0 if the user can end their turn, otherwise 1.</returns>
    int GetMinimumChoice() const;

    /// <summary>
    /// Handles the user selection of a score option to save dice.
    /// </summary>
    /// <param name="availableScoreOptions">ScoreOptions available.</param>
    /// <param name="choice">The user's choice.</param>
    void HandleSaveDiceOptionSelected(std::vector<ScoreOption> const& availableScoreOptions, int const& choice);

    /// <summary>
    /// Checks if a Farkle has Occurred.
    /// </summary>
    /// <param name="options">Score options from which to determine if a Farkle has occurred.</param>
    /// <returns>True if a Farkle has occurred, else false.</returns>
    bool FarkleOccurred(std::vector<ScoreOption> const& options) const;

    /// <summary>
    /// Resets variables for the beginning of a round and rolls the dice.
    /// </summary>
    void InitializeRound();

    /// <summary>
    /// Handles the end of turn actions.
    /// </summary>
    void EndTurn();
};