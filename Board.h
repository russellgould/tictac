#ifndef BOARD_H
#define BOARD_H
#include "Line.h"


class Board
{
    friend class Line;
    private:
        char grid[3][3]; // holds the moves;
        void updateLines(); // updates all the line objects
        void checkLines();
        bool isSpaceEmpty( char mov[2] );
        Line R1, R2, R3, C1, C2, C3, D1, D2;
        bool winner;


    public:
        Board();
        void printGrid();
        void printLines();
        void makeMove(char mv[2], char player);
        bool isInputOkay(char mov[2]);
        bool isWinner();

};

#endif // BOARD_H
