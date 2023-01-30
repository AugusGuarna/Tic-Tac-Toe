#include <iostream>

using namespace std;

char board[3][3] = {{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};

void showBoard(){
    cout<<"  \t 0   1   2\n";
    cout<<"  \t   |   |   \n";
    cout<<"0 \t "<<board[0][0]<<" | " << board[0][1]<<" | "<<board[0][2]<< " \n";
    cout<<"  \t___|___|___\n";
    cout<<"  \t   |   |   \n";
    cout<<"1 \t "<<board[1][0]<<" | " << board[1][1]<<" | "<<board[1][2]<< " \n";
    cout<<"  \t___|___|___\n";
    cout<<"  \t   |   |   \n";
    cout<<"2 \t "<<board[2][0]<<" | " << board[2][1]<<" | "<<board[2][2]<< " \n";
    cout<<"  \t   |   |   \n";
}

bool p1HasWon (){
    if (board[0][0] == 'O' && board[0][1] == 'O' && board[0][2] == 'O'){
        return true;
    } else if (board[1][0] == 'O' && board[1][1] == 'O' && board[1][2] == 'O'){
        return true;
    } else if (board[2][0] == 'O' && board[2][1] == 'O' && board[2][2] == 'O'){
        return true;
    } else  if (board[0][0] == 'O' && board[1][0] == 'O' && board[2][0] == 'O'){
        return true;
    } else if (board[0][1] == 'O' && board[1][1] == 'O' && board[2][1] == 'O'){
        return true;
    } else if (board[0][2] == 'O' && board[1][2] == 'O' && board[2][2] == 'O'){
        return true;
    } else if (board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O'){
        return true;
    } else if (board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == 'O'){
        return true;
    } else {
        return false;
    }
}

bool p2HasWon (){
    if (board[0][0] == 'X' && board[0][1] == 'X' && board[0][2] == 'X'){
        return true;
    } else if (board[1][0] == 'X' && board[1][1] == 'X' && board[1][2] == 'X'){
        return true;
    } else if (board[2][0] == 'X' && board[2][1] == 'X' && board[2][2] == 'X'){
        return true;
    } else  if (board[0][0] == 'X' && board[1][0] == 'X' && board[2][0] == 'X'){
        return true;
    } else if (board[0][1] == 'X' && board[1][1] == 'X' && board[2][1] == 'X'){
        return true;
    } else if (board[0][2] == 'X' && board[1][2] == 'X' && board[2][2] == 'X'){
        return true;
    } else if (board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X'){
        return true;
    } else if (board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X'){
        return true;
    } else {
        return false;
    }
}

void play(){
    int line, column;
    int i = 0;
    int j = 0;
    while (!p1HasWon() && !p2HasWon() && i < 5){
        showBoard();
        if (i <= j){
            cout <<"\nPlayer 1 it's your turn, please indicate the line\n";
            cin >> line;
            cout <<"and column\n";
            cin >> column;
            board[line][column] = 'O';
            i++;
        } else{
            cout <<"\nPlayer 2 it's your turn, please indicate the line\n";
            cin >> line;
            cout <<"and column\n";
            cin >> column;
            board[line][column] = 'X';
            j++;
        }
    }
    showBoard();

}


int main() {
    cout << "\nWelcome to my Tic - Tac - Toe game! :D\n";
    cout << "\nTwo players: Player 1 = [O] and Player 2 = [X]\n";
    cout << "\nThe line number is on the left side of the board while the column number is on top\n";
    cout << "\nHave fun and enjoy!!\n";
    play();
    if (p1HasWon()){
        cout << "Player 1 has won. Congrats player 1, you've asserted your dominance. You're officially a sigma male.";
    } else if (p2HasWon()){
        cout << "Player 2 has won. Congrats player 2, you've asserted your dominance. You're officially a sigma male.";
    } else {
        cout << "\nDraw. You're both beta males, I'm disapointed.";
    }
}
