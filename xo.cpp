
#include <iostream>
using namespace std;

// Function to display the board
void displayBoard(char board[3][3]) {
    cout << "\n";

    for (int i = 0; i < 3; i++) {
        cout << " ";

        for (int j = 0; j < 3; j++) {
            cout << board[i][j];

            if (j < 2)
                cout << " | ";
        }

        cout << endl;

        if (i < 2)
            cout << "---|---|---\n";
    }

    cout << endl;
}

// Function to check for a winner
bool checkWinner(char board[3][3], char player) {

    // Check rows and columns
    for (int i = 0; i < 3; i++) {

        if (board[i][0] == player &&
            board[i][1] == player &&
            board[i][2] == player)
            return true;

        if (board[0][i] == player &&
            board[1][i] == player &&
            board[2][i] == player)
            return true;
    }

    // Check diagonals
    if (board[0][0] == player &&
        board[1][1] == player &&
        board[2][2] == player)
        return true;

    if (board[0][2] == player &&
        board[1][1] == player &&
        board[2][0] == player)
        return true;

    return false;
}

// Function to check if the board is full
bool isBoardFull(char board[3][3]) {

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {

            if (board[i][j] == ' ')
                return false;
        }
    }

    return true;
}

// Main function
int main() {

    char board[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };

    char currentPlayer = 'X';
    int row, col;

    cout << "===== XO GAME =====\n";
    cout << "Player 1: X\n";
    cout << "Player 2: O\n";

    while (true) {

        displayBoard(board);

        cout << "Player " << currentPlayer
             << ", enter row (1-3): ";
        cin >> row;

        cout << "Enter column (1-3): ";
        cin >> col;

        // Validate input
        if (row < 1 || row > 3 || col < 1 || col > 3) {
            cout << "Invalid position! Try again.\n";
            continue;
        }

        // Check if cell is occupied
        if (board[row - 1][col - 1] != ' ') {
            cout << "This cell is already occupied! Try again.\n";
            continue;
        }

        // Place player's symbol
        board[row - 1][col - 1] = currentPlayer;

        // Check for winner
        if (checkWinner(board, currentPlayer)) {

            displayBoard(board);

            cout << "Congratulations! Player "
                 << currentPlayer << " wins!\n";

            break;
        }

        // Check for draw
        if (isBoardFull(board)) {

            displayBoard(board);

            cout << "Game Over! It's a Draw!\n";

            break;
        }

        // Switch players
        if (currentPlayer == 'X')
            currentPlayer = 'O';
        else
            currentPlayer = 'X';
    }

    return 0;
}

