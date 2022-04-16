#pragma once
#include "Die.h"
#include "Input.h"
#include "Player.h"
#include "ScoreOption.h"

using namespace std;

const bool RollAll = true;

void Player::PlayRound() {
    InitializeRound();

    int choice = -1;
    while (choice != 0) {
        vector<ScoreOption> availableScoreOptions = CalculateScoreOptions();
        if (FarkleOccurred(availableScoreOptions)) { return; }

        auto availableOptionsCount = (int)availableScoreOptions.size();
        DisplayScoreOptionMenu(availableScoreOptions);
        choice = Input::ReadInt("Enter Choice: ", GetMinimumChoice(), GetMaximumChoice(availableOptionsCount));
        if (choice > 0 && choice <= availableOptionsCount) {
            HandleSaveDiceOptionSelected(availableScoreOptions, choice);
        } 
        else if (choice == availableOptionsCount + 1) {
            RollDice();
        }
    }

    EndTurn();
}

void Player::RollDice(bool rollAll) {
    bool rollAllValue = rollAll || Die::AreAllDiceSaved(Dice);
    for (Die& d : Dice) {
        if (rollAllValue || !d.IsSaved()) {
            d.Roll();
        }
    }
    
    SavedDiceSinceRoll = false;
    Die::Display(Dice);
}

void Player::SetCounts(int* counts) const {
    for (Die d : Dice) {
        if (!d.IsSaved()) {
            ++counts[d.GetValue()];
        }
    }
}

vector<ScoreOption> Player::CalculateScoreOptions() const {
    int counts[7]{};
    SetCounts(counts);
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

void Player::DisplayScoreOptionMenu(vector<ScoreOption> const& options) const {
    cout << "\nPlayer Options Menu:" << endl;
    int i;
    for (i = 0; i < options.size(); ++i) {
        cout << "  " << to_string(i + 1) << ". " << options.at(i).ToString() << endl;
    }

    if (SavedDiceSinceRoll) {
        int unrolledDiceCount = Die::CountUnsavedDice(Dice);
        cout << "  " << to_string(i + 1) << ". Roll " << (unrolledDiceCount == 0 ? "all" : to_string(unrolledDiceCount)) << " Dice" << endl;
        
        if (HasBrokenOneThousand || RunningTotal >= 1000) {
            cout << "  0. End Turn" << endl;
        }
    }
}

int Player::GetMaximumChoice(int const& optionsCount) const {
    return optionsCount + (SavedDiceSinceRoll ? 1 : 0);
}

int Player::GetMinimumChoice() const {
    return (HasBrokenOneThousand || RunningTotal >= 1000) ? 0 : 1;
}

void Player::HandleSaveDiceOptionSelected(vector<ScoreOption> const& availableScoreOptions, int const& choice) {
    ScoreOption selection = availableScoreOptions.at(static_cast<vector<ScoreOption, allocator<ScoreOption>>::size_type>(choice) - 1);
    selection.SaveDice(Dice);
    RunningTotal += selection.GetValue();
    cout << "The current amount of points for this round is " << RunningTotal << endl;
    cout << "Your existing points balance is " << Score << endl;
    SavedDiceSinceRoll = true;
}

bool Player::FarkleOccurred(vector<ScoreOption> const& options) const {
    if (options.empty() && SavedDiceSinceRoll == false) {
        cout << "A Farkle has occurred!" << endl;
        Input::PressEnter();
        return true;
    }
    return false;
}

void Player::InitializeRound() {
    cout << endl << "Next up: " << Name << "!\n";
    RunningTotal = 0;
    RollDice(RollAll);
    SavedDiceSinceRoll = false;
}

void Player::EndTurn() {
    Score += RunningTotal;
    HasBrokenOneThousand = true;
}
