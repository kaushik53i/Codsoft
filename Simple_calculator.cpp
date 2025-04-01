#include <iostream>
using namespace std;

class Calculator {
private:
    double num1, num2; // Member variables

public:
    // Constructor to initialize numbers
    Calculator(double a, double b) {
        num1 = a;
        num2 = b;
    }

    // Addition
    double add() {
        return num1 + num2;
    }

    // Subtraction
    double sub() {
        return num1 - num2;
    }

    // Multiplication
    double mul() {
        return num1 * num2;
    }

    // Division with zero check
    double div() {
        if (num2 == 0) {
            cout << "Error: Division by Zero is Not Allowed!" << endl;
            return 0; // Returning 0 as default
        }
        return num1 / num2;
    }
};

int main() {
    int choice;
    double op1, op2;
    char cont; // Variable to continue calculations

    do {
        // Loop to ensure user enters a valid choice
        while (true) {
            // Display menu
            cout << "\n===== Simple Calculator =====\n";
            cout << "1. Addition (+)\n";
            cout << "2. Subtraction (-)\n";
            cout << "3. Multiplication (*)\n";
            cout << "4. Division (/)\n";
            cout << "Enter Your Choice (1-4): ";
            cin >> choice;

            // Validate input
            if (choice >= 1 && choice <= 4) {
                break; // Valid choice, exit loop
            } else {
                cout << "Invalid Choice! Please enter a valid option (1-4).\n";
                cin.clear(); // Clear error flag
                cin.ignore(10000, '\n'); // Ignore incorrect input
            }
        }

        // Taking input for operands
        cout << "Enter The First Operand: ";
        cin >> op1;
        cout << "Enter The Second Operand: ";
        cin >> op2;

        // Creating an object of Calculator class with user inputs
        Calculator calc(op1, op2);

        // Perform operation based on user choice
        switch (choice) {
            case 1:
                cout << op1 << " + " << op2 << " = " << calc.add() << endl;
                break;
            case 2:
                cout << op1 << " - " << op2 << " = " << calc.sub() << endl;
                break;
            case 3:
                cout << op1 << " * " << op2 << " = " << calc.mul() << endl;
                break;
            case 4:
                cout << op1 << " / " << op2 << " = " << calc.div() << endl;
                break;
        }

        // Ask user if they want to continue
        cout << "Do you want to perform another calculation? (y/n): ";
        cin >> cont;

    } while (cont == 'y' || cont == 'Y');

    cout << "Thank you for using the calculator. Goodbye!" << endl;
    return 0;
}
