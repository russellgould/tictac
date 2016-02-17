# tictac
Dan and I's tic-tac-toe game!!

okay so i'm thinking we can split this up into a bunch of functions, you write some, i write some, then we could throw them all together in the end and hope for the best

OUTPUT:
  A B C
1  | |
  - - -
2  | |
  - - -
3  | |

player X's move:

USER INPUT: A1

OUTPUT:
  A B C
1 X| |
  - - -
2  | |
  - - -
3  | |

player O's move:

INPUT: B2

OUTPUT:
  A B C
1 X| |
  - - -
2  |O|
  - - -
3  | |

etc.

we could just make a 2D 3x3 array, like game[3][3], which would look like this:

*   0      1      2
0 [0][0] [0][1] [0][2]
1 [1][0] [1][1] [1][2]
2 [2][0] [2][1] [2][2]

so we'd need to check six groups of three when we want to determine the winner:

rows:
R1 [0][0] [0][1] [0][2]
R2 [1][0] [1][1] [1][2]
R3 [2][0] [2][1] [2][2]

columns:
C1 [0][0] [1][0] [2][0]
C2 [0][1] [1][1] [1][2]
C3 [0][2] [1][2] [2][2]

diagonals:
D1 [0][0] [1][1] [2][2]
D2 [2][0] [1][1] [0][2]

i guess there are two ways we could approach this game:
  -check each row/column/diagonal after a move in [i][j] to see if it's filled (brute force)
  -check only the rows/columns/diagonals connected to the entry to see if they're filled (harder)

-------------------------------------------------------------------------------------------------
| 17 feb 2016 update |
----------------------

okay there are now two versions of the game up

version 1:
tictac.cpp is the self-contained version (procedurally written) which basically just has a loop and a function to check if a line/row/diagonal is full

version 2:
a little more convoluted so i'll walk you through how it works

five files, main.cpp, Board.h, Board.cpp, Line.h, Line.cpp 

just compile them all at once and it'll work. again, there's no guard against the buffer overflow, so you can fuck around with it and play an entire game in one line, if you want. like try entering "A1 B2 A2 C3 A3" and you'll immediately win by filling the first row with X's

i've been meaning to fix that but haven't gotten around to it yet
