#pragma once
#include <string>
#include <vector>
#include "Die.h"

class ScoreOption
{
public:
    /// <summary>
    /// Default Constructor.
    /// </summary>
    ScoreOption();

    /// <summary>
    /// SCoreOption constructor.
    /// </summary>
    /// <param name="faceValue">Face value of the dice for this score option.</param>
    /// <param name="dieCount">Count of the dice for this score option.</param>
    ScoreOption(int faceValue, int dieCount);

    /// <summary>
    /// Gets a string Representation of the ScoreOption.
    /// </summary>
    /// <returns>String representation of the score option.</returns>
    std::string ToString();

    /// <summary>
    /// Get the total score value of this ScoreOption.
    /// </summary>
    /// <returns>SCore value.</returns>
    int GetValue();

    /// <summary>
    /// Save the dice specific to this ScoreOption.
    /// </summary>
    /// <param name="dice">Vector of dice from which to chose.</param>
    void SaveDice(std::vector<Die>& dice);
private:
    /// <summary>
    /// Number of dice in this ScoreOption.
    /// </summary>
    int DieCount;
    
    /// <summary>
    /// Face value of the dice in this ScoreOption.
    /// </summary>
    int DieFaceValue;
};

