#include<iostream>
#include<cstdlib>  // for Random Number Generation
#include<ctime>    // for time
#include<string>

using namespace std;
//OPTIMIZED VERSION OF GAME
// Function to play the guessing game
void playGame() {
    // Initialize random seed based on the current time
    srand(time(NULL));

    // Generate a random number between 10 and 49 (inclusive)
    int num1 = rand() % 40 + 10;

    string num2;
    int attempts = 5;  // Number of attempts allowed

    cout << "Guess the two-digit number between 10 and 49!" << endl;

    // Loop for the number of allowed attempts
    for (int i = 1; i <= attempts; i++) {
        cout << "Round " << i << ": Enter your guess: ";
        cin >> num2;

        // Input validation: check if input is a two-digit number
        if (num2.length() != 2 || !isdigit(num2[0]) || !isdigit(num2[1])) {
            cout << "Invalid input! Please enter a valid two-digit number." << endl;
            i--; // Do not count this as an attempt
            continue;
        }

        int guessedNumber = stoi(num2);  //stoi: to convert input string to integer

        // Check if the guessed number matches the generated number
        if (guessedNumber > num1) {
            cout << "Your guess is too high!" << endl;
        }
        else if (guessedNumber < num1) {
            cout << "Your guess is too low!" << endl;
        }
        else {
            // If guessed correctly
            cout << "Congratulations! You guessed the number correctly." << endl;
            return;  // Exit the function since the user won
        }

        // Provide feedback if the guess is very close (within 5)
        if (abs(guessedNumber - num1) <= 5) {
            cout << "Very close!" << endl;
        }

        // Show the number of attempts left
        cout << "Attempts remaining: " << (attempts - i) << endl;
    }

    // If all attempts are used and the user hasn't guessed correctly
    cout << "You've used all attempts! The correct number was " << num1 << "." << endl;
    cout << "Better luck next time!" << endl;
}

int main() {
    char playAgain;

    do {
        playGame();  // Start the game

        // Ask if the player wants to play again
        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;

    } while (playAgain == 'y' || playAgain == 'Y');  // Replay loop

    cout << "Thanks for playing! Goodbye!" << endl;

    return 0;
}
