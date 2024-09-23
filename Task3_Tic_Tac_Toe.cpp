#include <iostream>
using namespace std;

char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}}; // Initial board state
char currentPlayer = 'X'; // Player 1 starts with 'X'
bool tie = false;
string player1, player2;
char lastPlayer;  // Track the last player who made the move

// Function to display the current game board
void displayBoard() {
    cout << "     |     |     \n";
    for (int i = 0; i < 3; i++) {
        cout << "  " << board[i][0] << "  |  " << board[i][1] << "  |  " << board[i][2] << "  \n";
        if (i < 2) cout << "-----|-----|-----\n";
    }
    cout << "     |     |     \n";
}

// Function to handle player move
void playerMove() {
    int choice;
    bool validInput = false;

    // Ask the current player for their move
    cout << ((currentPlayer == 'X') ? player1 : player2) << " (" << currentPlayer << "), enter a number (1-9): ";

    while (!validInput) {
        cin >> choice;

        // Determine the row and column from the choice (1-9)
        if (choice >= 1 && choice <= 9) {
            int row = (choice - 1) / 3;
            int col = (choice - 1) % 3;

            // Check if the selected position is available
            if (board[row][col] != 'X' && board[row][col] != '0') {
                board[row][col] = currentPlayer;
                validInput = true;
            } else {
                cout << "The space is already filled! Try another move: ";
            }
        } else {
            cout << "Invalid input! Please enter a number between 1 and 9: ";
        }
    }

    lastPlayer = currentPlayer;  // Record the last player who made a valid move
}

// Function to check for a win or a tie
bool checkWinOrTie() {
    // Check rows, columns, and diagonals for a win
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == board[i][1] && board[i][1] == board[i][2]) ||  // Row check
            (board[0][i] == board[1][i] && board[1][i] == board[2][i])) {  // Column check
            return true;
        }
    }
    // Check diagonals for a win
    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2]) || 
        (board[0][2] == board[1][1] && board[1][1] == board[2][0])) {
        return true;
    }

    // Check for a tie (no more empty spaces)
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != '0') {
                return false;  // Game is still ongoing
            }
        }
    }

    // If all spaces are filled and no one has won, it's a tie
    tie = true;
    return false;
}

// Function to switch the player after each move
void switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? '0' : 'X';
}

int main() {
    // Get player names
    cout << "Enter the name of Player 1 (X): ";
    getline(cin, player1);
    cout << "Enter the name of Player 2 (0): ";
    getline(cin, player2);

    // Game loop
    while (!checkWinOrTie()) {
        displayBoard();
        playerMove();
        if (checkWinOrTie()) break;
        switchPlayer();  // Switch to the next player
    }

    // Display the final board
    displayBoard();

    // Announce the result
    if (tie) {
        cout << "It's a draw!\n";
    } else {
        cout << ((lastPlayer == 'X') ? player1 : player2) << " wins!\n";
    }

    return 0;
}
