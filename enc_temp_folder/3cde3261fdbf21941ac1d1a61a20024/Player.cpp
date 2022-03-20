#include "Player.h"
#include "Die.h"
#include "ScoreOption.h"
#include <vector>
#include <iostream>
#include "Input.h"

using namespace std;

const bool RollAll = true;

void Player::PlayRound()
{
    vector<Die> dice(6);
    vector<ScoreOption> selected(0);
    int runningTotal = 0;

    RollDice(dice);
    bool madeSelectionSinceRoll = false;

    int choice = -1;
    while (choice != 0)
    {
        vector<ScoreOption> availbleScoreOptions = CalculateScoreOptions(dice);
        if (availbleScoreOptions.empty() && madeSelectionSinceRoll == false)
        {
            cout << "A Farkle has occurred!" << endl;
            Input::PressEnter();
            return;
        }

        DisplayScoreOptionMenu(availbleScoreOptions, madeSelectionSinceRoll, runningTotal);
        
        choice = Input::ReadInt("Enter Choice: ", 0, availbleScoreOptions.size() + 1);
        if (choice > 0 && choice <= availbleScoreOptions.size())
        {
            ScoreOption selection = availbleScoreOptions.at(choice - 1);
            selected.push_back(selection);
            selection.SaveDice(dice);
            runningTotal += selection.GetValue();
            cout << "The current amount of points for this round is " << runningTotal << endl;
            cout << "Your existing points balance is " << Score << endl;
            //cout << "You could end your turn with " << Score + runningTotal << " points right now.\n";
            madeSelectionSinceRoll = true;
        } 
        else if (choice == availbleScoreOptions.size() + 1)
        {
            RollDice(dice, AreAllDiceSaved(dice));
            madeSelectionSinceRoll = false;
        }
    }
}

void Player::RollDice(vector<Die>& dice, bool rollAll)
{
    for (Die& d : dice)
    {
        if (rollAll || !d.IsSaved())
        {
            d.Roll();
            d.Display();
        }
    }
}

vector<ScoreOption> Player::CalculateScoreOptions(vector<Die>& dice)
{
    vector<ScoreOption> options(0);
    int counts[7] = { 0 }; // use 7 so the index is the same as the face value (ignore index 0).
    for (Die d : dice)
    {
        if (!d.IsSaved())
        {
            ++counts[d.GetValue()];
        }
    }

    for (int i = 1; i <= 6; ++i)
    {
        if (counts[i] >= 3)
        {
            ScoreOption a(i, 3);
            options.push_back(a);
        }

        if ((i == 1 || i == 5) && counts[i] >= 1)
        {
            ScoreOption a(i, 1);
            options.push_back(a);
        }
    }
    return options;
}

void Player::DisplayScoreOptionMenu(vector<ScoreOption>& options, bool canRollAgain, int runningTotal)
{
    cout << "Player Options Menu:" << endl;
    int i;
    for (i = 0; i < options.size(); ++i)
    {
        cout << "  " << to_string(i + 1) << ". " << options.at(i).ToString() << endl;
    }

    if (canRollAgain)
    {
        cout << "  " << to_string(i + 1) << ".Roll Dice" << endl;
        
        if (HasBrokenOneThousand || runningTotal >= 1000)
        {
            cout << "  0. End Turn";
        }
    }
}

bool Player::AreAllDiceSaved(vector<Die>& dice)
{
    for (Die d : dice)
    {
        if (!d.IsSaved())
        {
            return false;
        }
    }
}
