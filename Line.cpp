#include <iostream>
using namespace std;

#include "Line.h"
using namespace std;

// initializes row/line/column to blanks
Line::Line()
{
    for (int i = 0; i < 3; i++)
        {
            moves[i] = ' ';
        }
}

// places a player's move into the container
void Line::setMove( int place, char player )
    {
        moves[place] = player;
    }

// tells us if a player has won
bool Line::isWinner()
    {
        if ( (moves[0] == moves[1]) && (moves[1] == moves[2]) && (moves[0] != ' '))
            return true;

        else
            return false;
    }

void Line::printLine()
    {
        for (int i = 0; i < 3; i++)
            {
                cout << "|" << moves[i];
            }


    }
