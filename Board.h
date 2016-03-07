#ifndef BOARD_H
#define BOARD_H
#include "Line.h"


class Board
{
    friend class Line;

    private:
        char grid[3][3]; // holds the actual grid
        void updateLines(); // updates all the line objects
        void checkLines(); // checks the line objects for a winner
        bool isSpaceEmpty( char mov[2] ); // checks the board to see if a move is valid
        Line R1, R2, R3, C1, C2, C3, D1, D2; // line objects for the board
        bool winner; // true = someone won. false = nope

    public:
        Board();
        void printGrid();
        void printLines();
        void makeMove(char mv[2], char player);
        bool isInputOkay(char mov[2]);
        bool isWinner();
        void computersMove(char);
        char whoWon();

};

#endif // BOARD_H
