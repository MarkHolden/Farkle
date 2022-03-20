#include "ScoreOption.h"

ScoreOption::ScoreOption(int faceValue, int dieCount) : DieCount(dieCount), DieFaceValue(faceValue) {}
ScoreOption::ScoreOption() : DieCount(0), DieFaceValue(0) {}

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
