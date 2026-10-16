#include <iostream>
#include <string>
#include <cmath>
#include <limits>

using namespace std;

double readNumber(const string& prompt) {
    double value;
    while (true) {
        cout << prompt;
        if (cin >> value) {
            return value;
        }
        cout << "Invalid input. Please enter a number.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

char readOperator() {
    char op;
    while (true) {
        cout << "Enter operator (+, -, *, /, ^) or q to quit: ";
        cin >> op;
        if (op == '+' || op == '-' || op == '*' || op == '/' || op == '^' || op == 'q' || op == 'Q') {
            return op;
        }
        cout << "Invalid operator. Try again.\n";
    }
}

int main() {
    cout << "=== Simple Calculator ===\n";

    while (true) {
        char op = readOperator();
        if (op == 'q' || op == 'Q') {
            cout << "Goodbye!\n";
            break;
        }

        double a = readNumber("Enter first number: ");
        double b = readNumber("Enter second number: ");
        double result = 0;
        bool valid = true;

        switch (op) {
            case '+':
                result = a + b;
                break;
            case '-':
                result = a - b;
                break;
            case '*':
                result = a * b;
                break;
            case '/':
                if (b == 0) {
                    cout << "Error: cannot divide by zero.\n";
                    valid = false;
                } else {
                    result = a / b;
                }
                break;
            case '^':
                result = pow(a, b);
                break;
        }

        if (valid) {
            cout << a << " " << op << " " << b << " = " << result << "\n";
        }
        cout << "\n";
    }

    return 0;
}
