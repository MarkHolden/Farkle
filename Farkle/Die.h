#pragma once
#include <string>

class Die
{
public:
    bool Saved;

    int Roll();

    std::string ToString();

    void Display();
};
