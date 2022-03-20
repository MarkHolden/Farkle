#pragma once
#include <string>
#include <vector>
#include "Die.h"

class ScoreOption
{
public:
    ScoreOption();
    ScoreOption(int faceValue, int dieCount);

    std::string ToString();

    int GetValue();

    void SaveDice(std::vector<Die>& dice);
private:
    int DieCount;
    
    int DieFaceValue;
};

