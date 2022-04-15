//============================================================================
// Name        : Input.h
// Author      : Mark Holden
// Date        : 3/26/2022
// Course      : IT-312 Software Development with C++ .NET
// Version     : 1.0
// Description : Partly based on https://github.com/MarkHolden/produce-rearrangement-analyzer/blob/master/ProduceRearrangementAnalyzer/Menu.cpp
//                  and https://github.com/splttingatms/EasyConsole/blob/master/EasyConsole/Input.cs
//============================================================================

#pragma once
#include <string>
#include <iostream>

class Input {
public:
    /// <summary>
    /// Displays a prompt and reads an integer from the console, verifying it is between min and max (inclusive).
    /// </summary>
    /// <param name="prompt">Prompt text to display.</param>
    /// <param name="min">Minimum allowed value (inclusive).</param>
    /// <param name="max">Maximum allowed value (inclusive).</param>
    /// <returns>Parsed integer.</returns>
    static int ReadInt(std::string const& prompt, int min, int max) {
        int result;
        std::string input;
        while (true) {
            input = ReadString(prompt);
            try {
                result = stoi(input);
                if (result >= min && result <= max) {
                    return result;
                }
                std::cout << "Input must be between " << min << " and " << max << std::endl;
            }
            catch (std::invalid_argument) {
                std::cout << "Input could not be parsed. Please try again.\n";
            }
            catch (std::out_of_range) {
                std::cout << "Input was out of range. Please try again.\n";
            }
        }
    }

    /// <summary>
    /// Reads an integer from the console, verifying it is between min and max (inclusive).
    /// </summary>
    /// <param name="min">Minimum allowed value (inclusive).</param>
    /// <param name="max">Maximum allowed value (inclusive).</param>
    /// <returns>Parsed integer.</returns>
    static int ReadInt(int min, int max) {
        return ReadInt("", min, max);
    }

    /// <summary>
    /// Reads and returns an integer from the console.
    /// </summary>
    /// <returns>Parsed integer.</returns>
    static int ReadInt() {
        return ReadInt(INT_MIN, INT_MAX);
    }

    /// <summary>
    /// Displays a prompt and gets input from the console.
    /// </summary>
    /// <param name="prompt">Prompt text to display.</param>
    /// <returns>Input string.</returns>
    static std::string ReadString(std::string const& prompt) {
        std::cout << prompt;
        return ReadString();
    }

    /// <summary>
    /// Get input from the console.
    /// </summary>
    /// <returns>Input string.</returns>
    static std::string ReadString() {
        std::string input;
        std::cin >> input;
        return input;
    }

    /// <summary>
    /// Waits for the [Enter] key to be pressed.
    /// </summary>
    static void PressEnter() {
        std::cout << "Press [Enter] to continue.";
        std::cin.ignore(std::numeric_limits <std::streamsize> ::max(), '\n');
        std::cin.ignore(std::numeric_limits <std::streamsize> ::max(), '\n');
    }

    /// <summary>
    /// Prompts the user for if they would like to continue.
    /// </summary>
    /// <param name="prompt">Prompt to display.</param>
    /// <returns>Bool of if the user would like to continue.</returns>
    static bool ShouldContinue(std::string const& prompt) {
        while (true) {
            std::cout << prompt << " [Y/N] ";
            char input;
            std::cin >> input;
            switch (input) {
            case 'y':
            case 'Y':
                return true;
            case 'n':
            case 'N':
                return false;
            default:
                break;
            }

            std::cin.ignore(std::numeric_limits <std::streamsize> ::max(), '\n');
            std::cout << "Input must be either Y or N." << std::endl;
        }
    }

    /// <summary>
    /// Prompts the user for if they would like to continue.
    /// </summary>
    /// <returns>Bool of if the user would like to continue.</returns>
    static bool ShouldContinue() {
        return ShouldContinue("Would you like to continue?");
    }
};
