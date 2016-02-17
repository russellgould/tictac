/****************************************************************
*tictactoe (with classes this time)
* we'll have two classes:
* 1. the Line class. this class:
*       -holds 3 chars
*       -setter functions to fill them
*       -a function to return a "true" value if the array is
*           full of the same character, "false" if it's not
* 2. the Board class. this class consists of a 9-char array and
*       -8 Line instances (R1, R2, R3, C1, C2, C3, D1, D2)
*       -a 9-character array to contain the tictactoe moves
*       -a setter function that fills the array (and updates the
*           corresponding Lines
*       -a print function to display the contents of the array in
*           the board format
*       -a function returning a "true" if it's okay to fill that
*           cell and "false" if that cell is full
*
* the next way i program this will use a Cell class, to check each
* cell, instead of each row, column, or diagonal
*****************************************************************/

#include <iostream>
#include <cstring>
#include "Board.h"
using namespace std;

int main()
    {
        char repeat = 'n';

    do {
        Board game;
        char mv[3] = "  ";
        char player;
        int i = -1;

        do
            {
                ++i;
                game.printGrid();
                cout << endl;

                if (i % 2 == 0)
                    {
                        cout << "Player X, your turn.\n";
                            player = 'X';
                    }

                else if (i % 2 == 1)
                    {
                        cout << "Player O, your turn.\n";
                            player = 'O';
                    }


                do {
                        cout << "Enter your move. ";
                            cin >> mv;

                    } while (!( game.isInputOkay(mv)));

                cout << endl;
            } while ( (i < 8) && !(game.makeMove( mv, player )) );


            if (!game.makeMove ( mv, player ) )
                {
                    cout << "Draw!\n";
                }

            else
                {
                    cout << "Player " << player << ", you win!\n";
                }



            cout << "\nEnter y to play again, or anything to exit. ";
                cin >> repeat;
        } while (toupper(repeat) == 'Y');

        return 0;
    }
