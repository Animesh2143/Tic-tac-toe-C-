#include <bits/stdc++.h>
#include <windows.h>

using namespace std;

void printBoard(const vector<vector<string>>& board) {
    system("CLS");
    for (int i = 0; i < 3; ++i) {
        cout << board[i][0] << " | " << board[i][1] << " | " << board[i][2] << endl;
        if (i < 2) cout << "---------" << endl;
    }
}

bool checkWin(const vector<vector<string>>& board, const string& player) {
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) return true;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) return true;
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) return true;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) return true;
    return false;
}

bool makeMove(vector<vector<string>>& board, int move, const string& player) {
    int row = (move - 1) / 3;
    int col = (move - 1) % 3;
    if (board[row][col] == " ") {
        board[row][col] = player;
        return true;
    } else {
        cout << "Already filled, try again." << endl;
        Sleep(1000);
        return false;
    }
}

int main() {
    char ch;
    do {
        vector<vector<string>> board(3, vector<string>(3, " "));
        string currentPlayer = "X";
        bool gameWon = false;

        for (int i = 0; i < 9 && !gameWon; ++i) {
            printBoard(board);
            int move;
            cout << "\nEnter move for Player " << (currentPlayer == "X" ? "A" : "B") << " (1-9): ";
            cin >> move;

            if (move < 1 || move > 9) {
                cout << "Invalid input, please try again." << endl;
                Sleep(1000);
                --i;
                continue;
            }

            if (!makeMove(board, move, currentPlayer)) {
                --i;
                continue;
            }

            if (checkWin(board, currentPlayer)) {
                printBoard(board);
                cout << "***************Congratulations**************\n        Player " 
                     << (currentPlayer == "X" ? "A" : "B") << " won the Game" << endl;
                gameWon = true;
            } else {
                currentPlayer = (currentPlayer == "X" ? "O" : "X");
            }
        }

        if (!gameWon) {
            printBoard(board);
            cout << "It's a draw!" << endl;
        }

        cout << "Press Y if you want to continue... ";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');

    return 0;
}
