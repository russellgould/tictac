#include <iostream>
using namespace std;

void output(char[3][3]);
void fillBoard(char[3][3], char[], char);
bool isGameOver(char[3][3]);
bool isInputValid(char[3][3], char[]);

int main()
{
  char repeat = 'n';

  do {
        char input[2];
        bool gameOver = false;

        char board[3][3] = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};

        for (int i = 0; (i < 9) && !isGameOver(board); i++)
          {
              if (i % 2 == 0)
                {
                  cout << endl;
                  output(board);

                  cout << "player x, make your move: ";
                  cin >> input;

                  input[0] = toupper(input[0]);

                  while (!isInputValid(board, input))
                    {
                        cout << "that space is taken! try again ";
                        cin >> input;
                        input[0] = toupper(input[0]);
                    }

                  fillBoard(board, input, 'X');
                }

              else
                {
                  cout << endl;
                  output(board);

                  cout << "player o, make your move: ";
                    cin >> input;

                  input[0] = toupper(input[0]);

                  while (!isInputValid(board, input))
                    {
                        cout << "that space is taken! try again ";
                        cin >> input;
                        input[0] = toupper(input[0]);
                    }

                  fillBoard(board, input, 'O');
                }

              if(isGameOver(board))
                  {
                    cout << "congrats player ";
                      if (i % 2 == 0)
                        {
                          cout << "X";
                        }

                      else
                        {
                          cout << "Y";
                        }
                  cout << ", you win!\n\n";

                }
            }

        cout << "want to play again? y/n ";
          cin >> repeat;

            while ( (toupper(repeat) != 'Y') && (toupper(repeat) != 'N'))
              {
                  cout << "y or n, fucktard. do you want to play again? y/n ";
                    cin >> repeat;
              }
      } while (toupper(repeat) == 'Y');



return 0;
}

void output(char board[3][3]) {

  cout << "  A B C\n";
  cout << "1 " << board[0][0] << "|" << board[0][1] << "|" << board[0][2] << endl;
  cout << "  -----\n";
  cout << "2 " << board[1][0] << "|" << board[1][1] << "|" << board[1][2] << endl;
  cout << "  -----\n";
  cout << "3 " << board[2][0] << "|" << board[2][1] << "|" << board[2][2] << endl;
}

void fillBoard(char board[3][3], char input[], char player)
  {
    int i = input[1];
          i -= 49;

    int j = input[0];
      j -= 65;

      board[i][j] = player;
  }

bool isGameOver(char board[3][3])
  {
     if ( (board[0][0] == board[0][1] && board[0][0] == board[0][2] && board[0][0] != ' ') ||
          (board[1][0] == board[1][1] && board[1][0] == board[1][2] && board[1][0] != ' ') ||
          (board[2][0] == board[2][1] && board[2][0] == board[2][2] && board[2][0] != ' ') ||
          (board[0][0] == board[1][0] && board[0][0] == board[2][0] && board[0][0] != ' ') ||
          (board[0][1] == board[1][1] && board[0][1] == board[2][1] && board[0][1] != ' ') ||
          (board[0][2] == board[1][2] && board[0][2] == board[2][2] && board[0][2] != ' ') ||
          (board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] != ' ') ||
          (board[0][2] == board[1][1] && board[0][2] == board[2][0] && board[0][2] != ' ')
        )
          {
            return true;
          }

      else
        {
            return false;
        }

  }

  bool isInputValid(char board[3][3], char input[])
    {
      int i = input[1];
            i -= 49;

      int j = input[0];
        j -= 65;

      if (board[i][j] == ' ')
        {
            return true;
        }

      else
        {
            return false;
        }
    }
