#pragma once

class Rules
{
public:
    static void Display()
    {
        std::cout << "\n\tPoints\n\n"
            "- Points are acquired one of three different ways.\n"
            "\t* A roll of a 1 is worth 100 points.\n"
            "\t* A roll of a 5 is worth 50 points.\n"
            "\t* Three(3) dice rolled at the same time with the same value is worth 100 times the face value."
            "\n \t\t- For example: three 2's rolled is 200 points and three 5's rolled is 500 points.\n\n"
            "- One exception to this rule is that three 1's rolled is 1,000 points rather than 100 points.\n\n";
        std::cout << "\tThe Play\n\n"
            "- The first player rolls all six dice at the same time and sets aside \"point dice\" (1's, 5's, or\n"
            "three of a kind) that appear as desired. At this point, the player has the option to continue to roll the\n"
            "remaining dice to collect even more points, or stop and keep any points acquired. At least one scoring die\n"
            "must be set aside in order to roll again.\n\n"
            "- A Farkle occurs when the dice are rolled and no point dice appear. At this point the player loses\n"
            "all the point dice he/she has collected during that turn, and the play passes to the next player.\n"
            "No points are recorded for that player's turn.\n\n"
            "- If a player decides not to risk rolling a Farkle then he/she can stop rolling and the play passes\n"
            "to the next player. Any points collected during that turn are then recorded.\n\n"
            "- If, in the course of one turn, all six dice become point dice and are set aside, the player must roll\n"
            "all six dice at least one more time before they can stop and keep any points collected.\n\n";
        Input::PressEnter(); 
        std::cout << "\n\tWinning\n\n"
            "- In order to win, a player must get 10,000 points recorded.\n\n"
            "- After a player gets over 10,000, each of the other players get one turn to try to beat the first player who\n"
            "goes out. If none of them beat his/her score, then he/she is declared the winner. If someone beats\n"
            "his/her score then that new player wins the game.\n\n";
        std::cout << "\tEntering the Game\n\n"
            "- In order for a player to \"Get on the Board\" and record points, he/she must continue to roll\n"
            "until at least 1,000 points are collected during one turn. Once the player officially gets on the\n"
            "board, the points are recorded and that player may stop rolling at any time during future turns.\n"
            "Sometimes it takes many turns before a player can get started.\n\n"
            "- Secret Strategy: All point dice do not have to be set aside. If you roll a 1 and a 5, sometimes it\n"
            "may be strategic to keep the 1 and roll the 5 again with the rest of the non-point dice. This may\n"
            "give you a better chance of rolling a three of a kind, but at least one point die must be set aside\n"
            "after each roll.\n\n";
    }
};