#include "Player.h"
#include "Die.h"
#include <vector>
#include "ScoreOption.h"

using namespace std;

void Player::PlayRound()
{
    vector<Die> activeDice(6);
    vector<Die> savedDice(0);
    vector<ScoreOption> availbleScoreOptions(0);
    vector<ScoreOption> selected(0);

    for (Die d : activeDice)
    {
        d.Roll();
    }

    // Calculate Score Options
    int counts[7] = { 0 }; // use 7 so the index is the same as the face value (ignore index 0).
    for (Die d : activeDice)
    {
        ++counts[d.GetValue()];
    }

    for (int i = 1; i <= 6; ++i)
    {
        if (counts[i] == 6)
        {
            ScoreOption a(i, 3);
            availbleScoreOptions.push_back(a);

            ScoreOption b(i, 3);
            availbleScoreOptions.push_back(b);
        }
        else if (counts[i] >= 3)
        {
            ScoreOption a(i, 3);
            availbleScoreOptions.push_back(a);
        }

        if (i == 1 || i == 5)
        {
            for (int j = 0; j < counts[i]; ++j)
            {
                ScoreOption a(i, 3);
                availbleScoreOptions.push_back(a);
            }
        }
    }

}
