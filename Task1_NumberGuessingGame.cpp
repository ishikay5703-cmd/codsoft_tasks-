/*
    CODSOFT C++ PROGRAMMING INTERNSHIP
    TASK 1 - NUMBER GUESSING GAME
    -------------------------------------------------------
    The program generates a random number within a specified
    range (1-100). The user is asked to guess the number, and
    the program provides feedback on whether the guess is too
    high, too low, or correct. The user has a limited number
    of attempts to guess the number correctly.

    Features implemented:
    - Random Number Generation
    - User Input for guesses
    - Feedback: Too High / Too Low / Correct
    - Attempt Limit
    - Play Again option
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int MIN_RANGE = 1;
const int MAX_RANGE = 100;
const int MAX_ATTEMPTS = 7;

// Plays a single round of the guessing game
void playGame()
{
    int secretNumber = MIN_RANGE + rand() % (MAX_RANGE - MIN_RANGE + 1);
    int guess;
    int attemptsUsed = 0;
    bool guessedCorrectly = false;

    cout << "\n===========================================\n";
    cout << "   I have chosen a number between "
         << MIN_RANGE << " and " << MAX_RANGE << ".\n";
    cout << "   You have " << MAX_ATTEMPTS << " attempts to guess it.\n";
    cout << "===========================================\n";

    while (attemptsUsed < MAX_ATTEMPTS && !guessedCorrectly)
    {
        cout << "\nAttempt " << (attemptsUsed + 1) << "/" << MAX_ATTEMPTS
             << " - Enter your guess: ";

        // Validate numeric input
        while (!(cin >> guess))
        {
            cout << "Invalid input. Please enter a whole number: ";
            cin.clear();
            cin.ignore(1000, '\n');
        }

        attemptsUsed++;

        if (guess < MIN_RANGE || guess > MAX_RANGE)
        {
            cout << "Please guess a number within the range "
                 << MIN_RANGE << "-" << MAX_RANGE << ".\n";
        }
        else if (guess < secretNumber)
        {
            cout << "Too LOW! Try a higher number.\n";
        }
        else if (guess > secretNumber)
        {
            cout << "Too HIGH! Try a lower number.\n";
        }
        else
        {
            guessedCorrectly = true;
            cout << "\nCorrect! You guessed the number "
                 << secretNumber << " in " << attemptsUsed
                 << " attempt(s). Well done!\n";
        }
    }

    if (!guessedCorrectly)
    {
        cout << "\nOut of attempts! The correct number was "
             << secretNumber << ". Better luck next time!\n";
    }
}

int main()
{
    srand(static_cast<unsigned int>(time(0)));
    char playAgain;

    cout << "###############################################\n";
    cout << "#            NUMBER GUESSING GAME              #\n";
    cout << "#      (CodSoft C++ Internship - Task 1)       #\n";
    cout << "###############################################\n";

    do
    {
        playGame();
        cout << "\nDo you want to play again? (y/n): ";
        cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "\nThanks for playing! Goodbye.\n";
    return 0;
}
