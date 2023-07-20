#include <iostream>
using namespace std;

const int BOARD_SIZE = 3;

// Function to initialize the game board with empty spaces
void initializeBoard(char board[][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = ' ';
        }
    }
}

// Function to display the game board
void displayBoard(const char board[][BOARD_SIZE]) {
    cout << "   0   1   2" << endl;
    cout << "0  " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
    cout << "  -----------" << endl;
    cout << "1  " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
    cout << "  -----------" << endl;
    cout << "2  " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
}

// Function to check if the game is over (win or draw)
bool isGameOver(const char board[][BOARD_SIZE], char symbol) {
    // Check rows, columns, and diagonals for a win
    for (int i = 0; i < BOARD_SIZE; i++) {
        if ((board[i][0] == symbol && board[i][1] == symbol && board[i][2] == symbol) ||
            (board[0][i] == symbol && board[1][i] == symbol && board[2][i] == symbol) ||
            (board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol) ||
            (board[0][2] == symbol && board[1][1] == symbol && board[2][0] == symbol)) {
            return true;
        }
    }

    // Check for a draw
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == ' ') {
                return false; // If any empty space is found, the game is not a draw yet
            }
        }
    }
    // If all spaces are filled and no winner found, it's a draw
    return true;
}

// Function to get player's move
void getPlayerMove(char board[][BOARD_SIZE], char symbol) {
    int row, col;
    cout << "Player " << symbol << ", enter your move (row and column): ";
    cin >> row >> col;

    // Check if the move is valid and the cell is empty
    while (row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE || board[row][col] != ' ') {
        cout << "Invalid move! Try again: ";
        cin >> row >> col;
    }

    board[row][col] = symbol;
}

int main() {
    char board[BOARD_SIZE][BOARD_SIZE];
    char player1Symbol = 'X';
    char player2Symbol = 'O';
    int currentPlayer = 1;

    initializeBoard(board);
    displayBoard(board);

    while (!isGameOver(board, player1Symbol) && !isGameOver(board, player2Symbol)) {
        if (currentPlayer == 1) {
            getPlayerMove(board, player1Symbol);
            currentPlayer = 2;
        } else {
            getPlayerMove(board, player2Symbol);
            currentPlayer = 1;
        }
        displayBoard(board);
    }

    // Check for the winner or declare a draw
    if (isGameOver(board, player1Symbol)) {
        cout << "Player X wins!" << endl;
    } else if (isGameOver(board, player2Symbol)) {
        cout << "Player O wins!" << endl;
    } else {
        cout << "It's a draw!" << endl;
    }

    return 0;
}

