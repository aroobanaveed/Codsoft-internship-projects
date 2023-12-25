#include<iostream>
using namespace std;

char B[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
char turn = 'X';
int row, column;
bool draw = false;

// Function for board display
void board() {
    system("cls");  // To prevent the repetition of the game board
    cout << "\n\t\tT I C  T A C  T O E  G A M E";
    cout << "\n\t\t_____________________________\n\n";

    // Code for board display
    cout << "\t\t     |     |    \n";
    cout << "\t\t  " << B[0][0] << "  |   " << B[0][1] << " |   " << B[0][2] << "\n";
    cout << "\t\t_____|_____|_____\n";
    cout << "\t\t     |     |    \n";
    cout << "\t\t  " << B[1][0] << "  |   " << B[1][1] << " |   " << B[1][2] << "\n";
    cout << "\t\t_____|_____|_____\n";
    cout << "\t\t     |     |    \n";
    cout << "\t\t  " << B[2][0] << "  |   " << B[2][1] << " |   " << B[2][2] << "\n";
    cout << "\t\t     |     |    \n";
}

// Function for players to take turns
void player_turn() {
    int choice;
    cout << "\tplayer1[X]\n\tplayer2[0]\n\n";
    if(turn == 'X')
        cout << "  \nplayer1 [x]  turn ";
    if(turn == '0')
        cout << "  \n\nplayer2 [0]  turn ";
    cin >> choice;  // Input for both players

    switch(choice) {  // For matching the choice entered by the user to a board's box
        case 1:
            row = 0; column = 0;
            break;
        case 2:
            row = 0; column = 1;
            break;
        case 3:
            row = 0; column = 2;
            break;
        case 4:
            row = 1; column = 0;
            break;
        case 5:
            row = 1; column = 1;
            break;
        case 6:
            row = 1; column = 2;
            break;
        case 7:
            row = 2; column = 0;
            break;
        case 8:
            row = 2; column = 1;
            break;
        case 9:
            row = 2; column = 2;
            break;
        default:  // Mandatory, otherwise shows an error
            cout << "\n\t\tInvalid Choice";
            break;
    }

    if(turn == 'X' && B[row][column] != 'X' && B[row][column] != '0') {
        B[row][column] = 'X';
        turn = '0';
    } else if(turn == '0' && B[row][column] != 'X' && B[row][column] != '0') {
        B[row][column] = '0';
        turn = 'X';
    } else {
        cout << "\nBox already filled!\nPlease, try again!!";
        player_turn();
    }
}

// Function for game over, game draw, and game winner
bool gameover() {
    // For game winner
    for(int i = 0; i < 3; i++) {
        if((B[i][0] == B[i][1] && B[i][0] == B[i][2]) || (B[0][i] == B[1][i] && B[0][i] == B[2][i]))
            return false;
    }

    // Diagonal wise
    if((B[0][0] == B[1][1] && B[0][0] == B[2][2]) || (B[0][2] == B[1][1] && B[0][2] == B[2][0]))
        return false;

    // For game over
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++) {
            if(B[i][j] != 'X' && B[i][j] != '0')
                return true;
        }

    // Game draw
    draw = true;
    for(int i = 0; i < 3; i++)
           {
              for(int j = 0; j < 3; j++)
               {
                  if(B[i][j]=='X'||B[i][j]=='0')
                      draw=false;
               }
           }
           if(draw=true)
              cout << "\n\t\G A M E   D R A W!!\n";
           else
              return false;

            /*{
                if(turn == '0')
                    cout << "\nPlayer1 [X] wins!!   Congratulations\n";
                else if(turn == 'X')
                    cout << "\nPlayer2 [0] wins!!   Congratulations\n";
            }*/


}

// Main function
int main() {
    while(gameover())
    {
        board();
        board();
        gameover();
        player_turn();

                if(turn == '0')
                    cout << "\nPlayer1 [X] wins!!   Congratulations\n";
                else if(turn == 'X')
                    cout << "\nPlayer2 [0] wins!!   Congratulations\n";

     }


    return 0;
}

