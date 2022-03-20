//============================================================================
// Name        : Input.h
// Author      : Mark Holden
// Date        : 3/19/2022
// Course      : IT-312 Software Development with C++ .NET
// Version     : 1.0
// Description : Based on https://github.com/MarkHolden/produce-rearrangement-analyzer/blob/master/ProduceRearrangementAnalyzer/Menu.cpp
//                  and https://github.com/splttingatms/EasyConsole/blob/master/EasyConsole/Input.cs
//============================================================================

#pragma once
#include <string>
#include <iostream>

using namespace std;

class Input
{
public:
    /// <summary>
    /// Displays a prompt and reads an integer from the console, verifying it is between min and max (inclusive).
    /// </summary>
    /// <param name="prompt">Prompt text to display.</param>
    /// <param name="min">Minimum allowed value (inclusive).</param>
    /// <param name="max">Maximum allowed value (inclusive).</param>
    /// <returns>Parsed integer.</returns>
    static int ReadInt(string prompt, int min, int max)
    {
        while (true) {
            cout << prompt;
            string input;
            int result;
            cin >> input;
            try {
                result = stoi(input);
                if (result >= min && result <= max) {
                    return result;
                }
                cout << "Input must be between " << min << " and " << max << endl;
            }
            catch (exception) {
                cout << "Input could not be parsed. Try Again.\n";
            }
        }
    }

    /// <summary>
    /// Reads an integer from the console, verifying it is between min and max (inclusive).
    /// </summary>
    /// <param name="min">Minimum allowed value (inclusive).</param>
    /// <param name="max">Maximum allowed value (inclusive).</param>
    /// <returns>Parsed integer.</returns>
    static int ReadInt(int min, int max)
    {
        return ReadInt("", min, max);
    }

    /// <summary>
    /// Reads and returns an integer from the console.
    /// </summary>
    /// <returns>Parsed integer.</returns>
    static int ReadInt()
    {
        return ReadInt(INT_MIN, INT_MAX);
    }
};
