/*
    CODSOFT C++ PROGRAMMING INTERNSHIP
    TASK 2 - SIMPLE CALCULATOR
    -------------------------------------------------------
    Develops a calculator program that performs basic
    arithmetic operations: addition, subtraction,
    multiplication, and division. The user inputs two
    numbers and chooses an operation to perform.

    Features implemented:
    - Input two numbers
    - Choose operation (+, -, *, /)
    - Perform the operation and display the result
    - Handles division-by-zero and invalid choices
    - Repeat calculation option
*/

#include <iostream>
using namespace std;

// Performs the arithmetic operation and returns true if successful
bool calculate(double num1, double num2, char op, double &result)
{
    switch (op)
    {
        case '+':
            result = num1 + num2;
            return true;
        case '-':
            result = num1 - num2;
            return true;
        case '*':
            result = num1 * num2;
            return true;
        case '/':
            if (num2 == 0)
            {
                cout << "Error: Division by zero is not allowed.\n";
                return false;
            }
            result = num1 / num2;
            return true;
        default:
            cout << "Error: Invalid operator entered.\n";
            return false;
    }
}

int main()
{
    double num1, num2, result;
    char op, choice;

    cout << "###############################################\n";
    cout << "#               SIMPLE CALCULATOR              #\n";
    cout << "#      (CodSoft C++ Internship - Task 2)       #\n";
    cout << "###############################################\n";

    do
    {
        cout << "\nEnter first number: ";
        while (!(cin >> num1))
        {
            cout << "Invalid input. Enter a valid number: ";
            cin.clear();
            cin.ignore(1000, '\n');
        }

        cout << "Enter second number: ";
        while (!(cin >> num2))
        {
            cout << "Invalid input. Enter a valid number: ";
            cin.clear();
            cin.ignore(1000, '\n');
        }

        cout << "Choose an operation (+, -, *, /): ";
        cin >> op;

        if (calculate(num1, num2, op, result))
        {
            cout << "\nResult: " << num1 << " " << op << " " << num2
                 << " = " << result << "\n";
        }

        cout << "\nDo you want to perform another calculation? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    cout << "\nThank you for using the Simple Calculator. Goodbye!\n";
    return 0;
}
