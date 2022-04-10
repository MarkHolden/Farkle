//============================================================================
// Name        : Die.h
// Author      : Mark Holden
// Date        : 3/26/2022
// Course      : IT-312 Software Development with C++ .NET
// Version     : 1.0
// Description : Represents a Die object.
//============================================================================

#pragma once
#include <string>
#include <vector>
#include <iostream>

class Die
{
private:
    /// <summary>
    /// Value representing if this die is saved or not.
    /// </summary>
    bool Saved = false;

    /// <summary>
    /// Face value of the die.
    /// </summary>
    int Value = 0;

    /// <summary>
    /// Output a row component for ASCII art dice.
    /// <para>This allows Dice to be rendered beside each other.</para>
    /// </summary>
    /// <param name="row">Row to output.</param>
    void Display(int row);

public:
    /// <summary>
    /// Default Constructor.
    /// </summary>
    Die();

    /// <summary>
    /// Value representing if this die is saved or not.
    /// </summary>
    /// <returns>A value representing if this die is saved or not.</returns>
    bool IsSaved() { return Saved; }

    /// <summary>
    /// Set the die's saved value to true.
    /// </summary>
    void Save() { Saved = true; }

    /// <summary>
    /// Assign a new random integer to the Die value.
    /// </summary>
    void Roll() { Saved = false; Value = (rand() % 6) + 1; }

    /// <summary>
    /// Get the current value.
    /// </summary>
    /// <returns>Current value.</returns>
    int GetValue() { return Value; }

    /// <summary>
    /// Display ASCII art of the current values of all dice in a vector.
    /// </summary>
    /// <param name="dice">Dice to display.</param>
    static void Display(std::vector<Die> dice) {
        for (int i = 0; i < 4; ++i) { // For each of the 4 rows in the ASCII art dice.
            for (Die die : dice) {
                if (!die.IsSaved()) {
                    die.Display(i); // Display the ith row.
                }
            }

            std::cout << std::endl;
        }
    }
};
