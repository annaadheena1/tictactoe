#include<iostream>
#include<string>
using namespace std;

int main()
{
    int i,j;
    char board[3][3] = {{' ', ' ', ' '},
                        {' ', ' ', ' '},
                        {' ', ' ', ' '}};
    const char* player1 = "Player 1 (X)";
    const char* player2 = "Player 2 (O)";
    char currentPlayer = 'X';
    char winner = ' ';

    int r=-1;
    int c=-1;

    cout << "Tic Tac Toe Board:" << endl;
    
    cout<<"Current Player: "<<currentPlayer<<endl;

    for(int j=0;j<9;j++)
    {
        for(i=0; i<3; i++)
            {
                cout<<" "<<board[i][0]<<"  | "<<board[i][1]<<"  | "<<board[i][2]<<"  "<<endl;
                if(i<2)
                cout<<"____|____|____"<<endl;
            }
            cout<<"    |    |    "<<endl;

        if (winner != ' ')
        {
            break;
        }

        cout<<"Enter row (0-2) and column (0-2) for "<<currentPlayer<<": ";
        cin>>r>>c;
        if (r < 0 || r > 2 || c < 0 || c > 2 || board[r][c] != ' ')
        {
            cout << "Invalid move. Try again." << endl;
            j--; // Decrement j to allow the player to retry
            continue;
        }
        
        board[r][c] = currentPlayer;
        currentPlayer= (currentPlayer == 'X') ? 'O' : 'X';

    for(int r=0;r<3;r++)
        {
            if (board[r][0] == board[r][1] && board[r][1] == board[r][2] && board[r][0] != ' ')
            {
                winner = board[r][0];
                break;
            }
        }
        
    for(int c=0;c<3;c++)
        {
            if (board[0][c] == board[1][c] && board[1][c] == board[2][c] && board[0][c] != ' ')
            {
                winner = board[0][c];
                break;
            }
        }

    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
        {
            winner = board[0][0];
            break;
        }
    else if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
        {
            winner = board[0][2];
            break;
        }
    
    }
    if (winner != ' ')
    {
        cout << "Congratulations! " << winner << " wins!" << endl;
    }
    else
    {
        cout << "It's a draw!" << endl;
    }
 
    
    return 0;
}