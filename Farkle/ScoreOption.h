#pragma once
class ScoreOption
{
public:
    ScoreOption();
    ScoreOption(int faceValue, int dieCount);

    int GetValue();
private:
    int DieCount;
    
    int DieFaceValue;
};

