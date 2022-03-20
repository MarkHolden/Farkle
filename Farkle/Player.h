#pragma once
#include <string>

class Player {
public:
    /// <summary>
    /// Default Constructor.
    /// </summary>
    /// <param name="name">The name of the player.</param>
    Player(std::string name) : Name(name) {}

    /// <summary>
    /// Add points for the round to a player's score.
    /// </summary>
    /// <param name="points">Count of the points to add.</param>
    void AddPoints(int points);

    /// <summary>
    /// Get the Current number of points a player has.
    /// </summary>
    /// <returns>Number of points.</returns>
    int GetScore() { return Score; }

    /// <summary>
    /// Get a string representation of the Player.
    /// </summary>
    /// <returns>String representation of the Player.</returns>
    std::string ToString() { return Name + "\t|\t" + std::to_string(Score); }

private:
    /// <summary>
    /// Internal score counter.
    /// </summary>
    int Score = 0;

    /// <summary>
    /// Name of the player.
    /// </summary>
    std::string Name;
};