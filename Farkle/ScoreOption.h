#pragma once
#include <string>
#include <vector>
#include "Die.h"

class ScoreOption {
public:
    /// <summary>
    /// Default constructor.
    /// </summary>
    ScoreOption() = default;

    /// <summary>
    /// ScoreOption constructor.
    /// </summary>
    /// <param name="faceValue">Face value of the dice for this score option.</param>
    /// <param name="dieCount">Count of the dice for this score option.</param>
    ScoreOption(int faceValue, int dieCount);

    /// <summary>
    /// Gets a string Representation of the ScoreOption.
    /// </summary>
    /// <returns>String representation of the score option.</returns>
    std::string ToString() const;

    /// <summary>
    /// Get the total score value of this ScoreOption.
    /// </summary>
    /// <returns>SCore value.</returns>
    int GetValue() const;

    /// <summary>
    /// Save the dice specific to this ScoreOption.
    /// </summary>
    /// <param name="dice">Vector of dice from which to chose.</param>
    void SaveDice(std::vector<Die>& dice) const;
private:
    /// <summary>
    /// Number of dice in this ScoreOption.
    /// </summary>
    int DieCount = 0;
    
    /// <summary>
    /// Face value of the dice in this ScoreOption.
    /// </summary>
    int DieFaceValue = 0;
};

