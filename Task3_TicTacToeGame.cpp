/*
    CODSOFT C++ PROGRAMMING INTERNSHIP
    TASK 3 - TIC-TAC-TOE GAME
    -------------------------------------------------------
    A simple console-based Tic-Tac-Toe game that allows two
    players to play against each other.

    Features implemented (as per task requirements):
    - Game Board:      3x3 grid
    - Players:         "X" and "O"
    - Display Board:   Shows current state of the board
    - Player Input:    Prompts current player for a move
    - Update Board:    Updates board with the player's move
    - Check for Win:   Checks if current player has won
    - Check for Draw:  Determines if the game is a draw
    - Switch Players:  Alternates turns between X and O
    - Display Result:  Shows result (win, draw, or ongoing)
    - Play Again:      Asks if players want another round
*/

#include <iostream>
using namespace std;

char board[3][3];

// Initializes the board with empty cells (numbered 1-9 for guidance)
void initializeBoard()
{
    int cellNumber = 1;
    for (int row = 0; row < 3; row++)
        for (int col = 0; col < 3; col++)
            board[row][col] = ' ';
    (void)cellNumber;
}

// Displays the current state of the board
void displayBoard()
{
    cout << "\n";
    for (int row = 0; row < 3; row++)
    {
        cout << " " << board[row][0] << " | " << board[row][1]
             << " | " << board[row][2] << " \n";
        if (row < 2) cout << "---|---|---\n";
    }
    cout << "\n";
}

// Updates the board with the player's move if the cell is valid and empty
bool updateBoard(int position, char playerSymbol)
{
    if (position < 1 || position > 9) return false;

    int row = (position - 1) / 3;
    int col = (position - 1) % 3;

    if (board[row][col] != ' ') return false;

    board[row][col] = playerSymbol;
    return true;
}

// Checks whether the given player has won
bool checkForWin(char playerSymbol)
{
    // Check rows and columns
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == playerSymbol && board[i][1] == playerSymbol && board[i][2] == playerSymbol)
            return true;
        if (board[0][i] == playerSymbol && board[1][i] == playerSymbol && board[2][i] == playerSymbol)
            return true;
    }
    // Check diagonals
    if (board[0][0] == playerSymbol && board[1][1] == playerSymbol && board[2][2] == playerSymbol)
        return true;
    if (board[0][2] == playerSymbol && board[1][1] == playerSymbol && board[2][0] == playerSymbol)
        return true;

    return false;
}

// Determines whether the game is a draw (board full, no winner)
bool checkForDraw()
{
    for (int row = 0; row < 3; row++)
        for (int col = 0; col < 3; col++)
            if (board[row][col] == ' ')
                return false;
    return true;
}

int main()
{
    char playAgain;

    cout << "###############################################\n";
    cout << "#              TIC-TAC-TOE GAME                #\n";
    cout << "#      (CodSoft C++ Internship - Task 3)       #\n";
    cout << "###############################################\n";
    cout << "\nCell positions are numbered 1-9 as shown below:\n";
    cout << " 1 | 2 | 3 \n---|---|---\n 4 | 5 | 6 \n---|---|---\n 7 | 8 | 9 \n";

    do
    {
        initializeBoard();
        char currentPlayer = 'X';
        bool gameOver = false;
        int movesPlayed = 0;

        while (!gameOver)
        {
            displayBoard();
            cout << "Player " << currentPlayer << ", enter your move (1-9): ";

            int position;
            while (!(cin >> position))
            {
                cout << "Invalid input. Enter a number between 1-9: ";
                cin.clear();
                cin.ignore(1000, '\n');
            }

            if (!updateBoard(position, currentPlayer))
            {
                cout << "Invalid move! That cell is occupied or out of range. Try again.\n";
                continue;
            }

            movesPlayed++;

            if (checkForWin(currentPlayer))
            {
                displayBoard();
                cout << "*** Player " << currentPlayer << " wins! Congratulations! ***\n";
                gameOver = true;
            }
            else if (checkForDraw())
            {
                displayBoard();
                cout << "*** It's a DRAW! Good game. ***\n";
                gameOver = true;
            }
            else
            {
                // Switch players
                currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
            }
        }

        cout << "\nDo you want to play again? (y/n): ";
        cin >> playAgain;

    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "\nThanks for playing Tic-Tac-Toe. Goodbye!\n";
    return 0;
}
