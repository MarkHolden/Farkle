#pragma once
#include "ScoreOption.h"

using namespace std;

ScoreOption::ScoreOption(int faceValue, int dieCount) : DieCount(dieCount), DieFaceValue(faceValue) {}

ScoreOption::ScoreOption() : DieCount(0), DieFaceValue(0) {}

string ScoreOption::ToString()
{
    return to_string(DieCount) + (DieCount > 1 ? " dice" : " die") + " with a face value of " + to_string(DieFaceValue) + " for a score of " + to_string(GetValue());
}

int ScoreOption::GetValue()
{
    if (DieCount == 1)
    {
        if (DieFaceValue == 5)
        {
            return 50;
        }
        return 100;
    }

    if (DieCount == 3)
    {
        if (DieFaceValue == 1)
        {
            return 1000;
        }
        return DieFaceValue * 100;
    }
    return 0;
}

void ScoreOption::SaveDice(std::vector<Die>& dice)
{
    int saved = 0;
    for (Die& d : dice)
    {
        if (!d.IsSaved() && d.GetValue() == DieFaceValue)
        {
            ++saved;
            d.Save();
        }

        if (DieCount == saved)
        {
            return;
        }
    }
}


