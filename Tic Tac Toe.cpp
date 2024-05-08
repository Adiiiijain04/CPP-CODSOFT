/* 

A simple console-based Tic-Tac-Toe game that
allows two players to play against each other

*/


#include <iostream>
#include <vector>
using namespace std;

void makeboard(vector<vector<char>>& gameBoard);
void displaytheBoard(const vector<vector<char>>& gameBoard);
bool checkifWin(const vector<vector<char>>& gameBoard, char currentPlayer);
bool checkDraw(const vector<vector<char>>& gameBoard);
bool isValidMove(const vector<vector<char>>& gameBoard, int row, int col);
void switchPlayer(char& currentPlayer);

int main() {
    char currentPlayer = 'X';
    char playAgain;

    do {
        vector<vector<char>> gameBoard(3, vector<char>(3, '-'));

        makeboard(gameBoard);

        bool gameOver = false;
        do {
            displaytheBoard(gameBoard);

            int row, col;
            cout << "Player " << currentPlayer << ", enter your move (row and column): ";
            cin >> row >> col;

            if (isValidMove(gameBoard, row, col)) {
                gameBoard[row][col] = currentPlayer;
                if (checkifWin(gameBoard, currentPlayer)) {
                    displaytheBoard(gameBoard);
                    cout << "Player " << currentPlayer << " wins!" << endl;
                    gameOver = true;
                } else if (checkDraw(gameBoard)) {
                    displaytheBoard(gameBoard);
                    cout << "It's a draw!" << endl;
                    gameOver = true;
                } else {
                    switchPlayer(currentPlayer);
                }
            } else {
                cout << "Invalid move. Try again." << endl;
            }
        } while (!gameOver);

        cout << "Do you want to play again? (Y/N): ";
        cin >> playAgain;
    } while (playAgain == 'Y' || playAgain == 'y');

    return 0;
}

void makeboard(vector<vector<char>>& gameBoard) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            gameBoard[i][j] = '-';
        }
    }
}

void displaytheBoard(const vector<vector<char>>& gameBoard) {
    cout << "  0 1 2" << endl;
    for (int i = 0; i < 3; ++i) {
        cout << i << " ";
        for (int j = 0; j < 3; ++j) {
            cout << gameBoard[i][j] << " ";
        }
        cout << endl;
    }
}

bool checkifWin(const vector<vector<char>>& gameBoard, char currentPlayer) {
    for (int i = 0; i < 3; ++i) {
        if (gameBoard[i][0] == currentPlayer && gameBoard[i][1] == currentPlayer && gameBoard[i][2] == currentPlayer) {
            return true;
        }
        if (gameBoard[0][i] == currentPlayer && gameBoard[1][i] == currentPlayer && gameBoard[2][i] == currentPlayer) {
            return true;
        }
    }
    if (gameBoard[0][0] == currentPlayer && gameBoard[1][1] == currentPlayer && gameBoard[2][2] == currentPlayer) {
        return true;
    }
    if (gameBoard[0][2] == currentPlayer && gameBoard[1][1] == currentPlayer && gameBoard[2][0] == currentPlayer) {
        return true;
    }
    return false;
}

bool checkDraw(const vector<vector<char>>& gameBoard) {
    for (const auto& row : gameBoard) {
        for (char cell : row) {
            if (cell == '-') {
                return false;
            }
        }
    }
    return true;
}

bool isValidMove(const vector<vector<char>>& gameBoard, int row, int col) {
    return (row >= 0 && row < 3 && col >= 0 && col < 3 && gameBoard[row][col] == '-');
}

void switchPlayer(char& currentPlayer) {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}
