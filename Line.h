#ifndef LINE_H
#define LINE_H


class Line
{
    friend class Board;

    private:
        char moves[3]; // contains the contents of a row, line, or diagonal
    public:
        Line();
        void setMove( int, char );
        bool isWinner();
        void printLine();
};

#endif // LINE_H
