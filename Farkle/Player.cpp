#pragma once
#include "Die.h"
#include "Input.h"
#include "Player.h"
#include "ScoreOption.h"

using namespace std;

const bool RollAll = true;

void Player::PlayRound() {
    vector<Die> dice(6);
    vector<ScoreOption> selected(0);
    int runningTotal = 0;

    RollDice(dice);
    bool madeSelectionSinceRoll = false;

    int choice = -1;
    while (choice != 0) {
        vector<ScoreOption> availbleScoreOptions = CalculateScoreOptions(dice);
        if (availbleScoreOptions.empty() && madeSelectionSinceRoll == false) {
            cout << "A Farkle has occurred!" << endl;
            Input::PressEnter();
            return;
        }

        DisplayScoreOptionMenu(availbleScoreOptions, madeSelectionSinceRoll, runningTotal, Die::CountUnsavedDice(dice));
        
        choice = Input::ReadInt("Enter Choice: ", GetMinimumChoice(runningTotal), GetMaximumChoice(availbleScoreOptions, madeSelectionSinceRoll));
        if (choice > 0 && choice <= availbleScoreOptions.size()) {
            ScoreOption selection = availbleScoreOptions.at(static_cast<vector<ScoreOption, allocator<ScoreOption>>::size_type>(choice) - 1);
            selected.push_back(selection);
            selection.SaveDice(dice);
            runningTotal += selection.GetValue();
            cout << "The current amount of points for this round is " << runningTotal << endl;
            cout << "Your existing points balance is " << Score << endl;
            madeSelectionSinceRoll = true;
        } 
        else if (choice == availbleScoreOptions.size() + 1) {
            RollDice(dice, Die::AreAllDiceSaved(dice));
            madeSelectionSinceRoll = false;
        }
    }

    Score += runningTotal;
    HasBrokenOneThousand = true;
}

void Player::RollDice(vector<Die>& dice, bool rollAll) const {
    for (Die& d : dice) {
        if (rollAll || !d.IsSaved()) {
            d.Roll();
        }
    }
    
    Die::Display(dice);
}

void Player::SetCounts(vector<Die> const& dice, int* counts) const {
    for (Die d : dice) {
        if (!d.IsSaved()) {
            ++counts[d.GetValue()];
        }
    }
}

vector<ScoreOption> Player::CalculateScoreOptions(vector<Die> const& dice) const {
    int counts[7]{};
    SetCounts(dice, counts);
    vector<ScoreOption> options(0);

    for (int i = 1; i <= 6; ++i) {
        if (counts[i] >= 3) {
            ScoreOption a(i, 3);
            options.push_back(a);
        }

        if ((i == 1 || i == 5) && counts[i] >= 1) {
            ScoreOption a(i, 1);
            options.push_back(a);
        }
    }
    return options;
}

void Player::DisplayScoreOptionMenu(vector<ScoreOption> const& options, bool canRollAgain, int runningTotal, int unrolledDiceCount) const {
    cout << "\nPlayer Options Menu:" << endl;
    int i;
    for (i = 0; i < options.size(); ++i) {
        cout << "  " << to_string(i + 1) << ". " << options.at(i).ToString() << endl;
    }

    if (canRollAgain) {
        cout << "  " << to_string(i + 1) << ". Roll " << (unrolledDiceCount == 0 ? "all" : to_string(unrolledDiceCount)) << " Dice" << endl;
        
        if (HasBrokenOneThousand || runningTotal >= 1000) {
            cout << "  0. End Turn" << endl;
        }
    }
}

int Player::GetMaximumChoice(vector<ScoreOption> const& options, bool madeSelectionSinceRoll) const
{
    return (int)options.size() + (madeSelectionSinceRoll ? 1 : 0);
}

int Player::GetMinimumChoice(int const& runningTotal) const
{
    return (HasBrokenOneThousand || runningTotal >= 1000) ? 0 : 1; // Whether to allow input of 0 to end turn.
}
