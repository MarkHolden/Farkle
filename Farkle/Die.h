#pragma once
#include <string>

class Die
{
private:
    bool Saved;

    int Value;

public:
    bool IsSaved() { return Saved; }

    void Save() { Saved = true; }

    void Roll() { Value = 1; }

    int GetValue() { return Value; }

    std::string ToString();

    void Display();
};
