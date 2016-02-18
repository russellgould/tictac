#include <iostream>
#include <cstring>
#include "Board.h"
#include "Line.h"

using namespace std;

// constructor initializes a grid to all blanks at the beginning of a game

Board::Board()
{
    for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)

                {
                    grid[i][j] = ' ';
                }
        }

    Line R1, R2, R3, C1, C2, C3, D1, D2;
}

// fcn formats/prints the contents of the board
void Board::printGrid()
    {
        cout << "* 1 2 3\n";
        cout << "A " << grid[0][0] << "|" << grid[0][1] << "|" << grid[0][2] << endl;
        cout << "  -----\n";
        cout << "B " << grid[1][0] << "|" << grid[1][1] << "|" << grid[1][2] << endl;
        cout << "  -----\n";
        cout << "C " << grid[2][0] << "|" << grid[2][1] << "|" << grid[2][2] << endl;
        cout << endl;
    }

void Board::printLines()
    {
        cout << "R1: ";
        R1.printLine();
        cout << endl;

        cout << "R2: ";
        R2.printLine();
        cout << endl;

        cout << "R3: ";
        R3.printLine();
        cout << endl;

        cout << "C1: ";
        C1.printLine();
        cout << endl;

        cout << "C2: ";
        C2.printLine();
        cout << endl;

        cout << "C3: ";
        C3.printLine();
        cout << endl;

        cout << "D1: ";
        D1.printLine();
        cout << endl;

        cout << "D2: ";
        D2.printLine();
        cout << endl;
    }

bool Board::makeMove(char mov[2], char player)
    {
        int i = ( mov[0] - 65);
        int j = (mov[1] - 49);

        grid[i][j] = player;

        if ( updateLines() )
            {
                return true;
            }

        else
            {
                return false;
            }
    }

//todo: take input from the grid and insert it into the lines
bool Board::updateLines()
    {
        for (int i = 0; i < 3; i++)
            {
                R1.setMove( i, grid[0][i] );
                R2.setMove( i, grid[1][i] );
                R3.setMove( i, grid[2][i] );
                C1.setMove( i, grid[i][0] );
                C2.setMove( i, grid[i][1] );
                C3.setMove( i, grid[i][2] );
                D1.setMove( i, grid[i][i] );
                D2.setMove( i, grid[2-i][i] );
            }

        return checkLines();
    }

bool Board::checkLines()
    {

        if ( R1.isWinner() || R2.isWinner() || R3.isWinner() ||
             C1.isWinner() || C2.isWinner() || C3.isWinner() ||
             D1.isWinner() || D2.isWinner() )
            {
                return true;
            }

        else
            {
                return false;
            }
    }

// returns false if input is bad
// returns true if input is good
bool Board::isInputOkay(char input[2])
    {
        if ( (input[0] != 'A' && input[0] != 'B' && input[0] != 'C') ||
             (input[0] != 'a' && input[0] != 'b' && input[0] != 'c') ||
             (input[1] != '1' && input[1] != '2' && input[1] != '3') )
            {
                cout << "I didn't understand your input. Please enter:\n\n";
                cout << "A1 | A2 | A3\n"
                     << "------------\n"
                     << "B1 | B2 | B3\n"
                     << "------------\n"
                     << "C1 | C2 | C3\n\n";

                return false;
            }

        else if ( !isSpaceEmpty(input) )
            {
                cout << "\nYou can't go there!\n";
                return false;
            }

        else
            {
                return true;
            }
    }



bool Board::isSpaceEmpty( char mov[2] )
    {
            int i = ( mov[0] - 65);
            int j = (mov[1] - 49);

            if (grid[i][j] != ' ')
                {
                    return false;
                }

            else
                {
                    return true;
                }
    }
