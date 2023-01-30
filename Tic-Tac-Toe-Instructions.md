# Instructions
Tic-Tac-Toe is multiplayer game where two different people take turns in order to form a line, column or diagonal of Os or Xs inside a board that looks like this: #. The first one to achieve it becomes the winner. If none manages to do it, it ends up in a draw.\n

# Board
So the first thing we need to do is to declare a board and a function that prints it.\nIn this case as we'll do a empty board we ought to initialize a 3x3 array full of blank spaces `' '`. Since blank spaces are `char`, outside the main we're going to write
```
char board[3][3] = {{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};
```
\nThis allow us to consider the board as a "given constant" so it won't be necessary to include it as the parameters of any function.\nTo print it, a simple void function will be ok. You can either build two for cycles one inside another, or if you want it more fancy and with the traditional display you can do it like this:
```
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
```
# When does a player win?
Other easy thing to do (and that will be useful later on) is to create a function that determines when a player wins. You can write one function for both or two separate functions that'll have the same code with minimal differences. No matter what you choose the function must check if the players have form a line, column or diagonal. For this you may write different cycles or a chain of `if(){} else{} if(){}`, since both complexities will be O(1) it really doesn't matter which you choose (the cycles maybe more fancy or tidy, but anyone it's ok ;)).
```
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
```
The code for p2HasWon it's exactly the same with the difference that you have to replace the 'O' with 'X'.

# The function that'll allow us to play
This will be the function that determines the different turns of the players and that changes the board with the decisions they'll make (I really don't know how to do it so the board doesn't appears every time you play, later on I'll investigate on that). This function basically is a while that executes itself in 3 different situations:
1. If player 1 didn't won
2. If player 2 didn't won
3. If i < 5. i in this case represents the number of movements of player 1. As i is initialize it in 0 and the most movements player 1 can make is 5 without winning, if i = 6 and neither of the players have won, then there's no more game to play.
Inside this cycle will ask the player to tell us the coordinates of each movement. For this we'll assume that they do know how to play and won't try to occupy a position that has already been taken. Once the coordinate is indicated, the map will change. To show the map at the end of the game we'll write `showBoard()` at the end of the cycle.
```
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

}
```

# Integrating everything in the main
So once you've done something like this, what remains is the integration inside the main.

```
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
```
