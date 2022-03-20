#pragma once
#include <string>

class Die
{
private:
    bool Saved = false;

    int Value = 0;

public:
    Die();

    bool IsSaved() { return Saved; }

    void Save() { Saved = true; }

    void Roll() { Saved = false; Value = (rand() % 6) + 1; }

    int GetValue() { return Value; }

    std::string ToString();

    void Display();
};
