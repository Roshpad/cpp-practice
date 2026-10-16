#include <iostream>
#include <string>
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

int readChoice() {
    int choice;
    while (true) {
        cout << "Enter your choice (0-6): ";
        if (cin >> choice && choice >= 0 && choice <= 6) {
            return choice;
        }
        cout << "Invalid choice. Try again.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

double celsiusToFahrenheit(double c) { return c * 9.0 / 5.0 + 32.0; }
double fahrenheitToCelsius(double f) { return (f - 32.0) * 5.0 / 9.0; }
double celsiusToKelvin(double c) { return c + 273.15; }
double kelvinToCelsius(double k) { return k - 273.15; }
double fahrenheitToKelvin(double f) { return celsiusToKelvin(fahrenheitToCelsius(f)); }
double kelvinToFahrenheit(double k) { return celsiusToFahrenheit(kelvinToCelsius(k)); }

bool belowAbsoluteZero(double value, char unit) {
    if (unit == 'C') return value < -273.15;
    if (unit == 'F') return value < -459.67;
    return value < 0;
}

void showMenu() {
    cout << "\n=== Temperature Converter ===\n";
    cout << "1. Celsius to Fahrenheit\n";
    cout << "2. Fahrenheit to Celsius\n";
    cout << "3. Celsius to Kelvin\n";
    cout << "4. Kelvin to Celsius\n";
    cout << "5. Fahrenheit to Kelvin\n";
    cout << "6. Kelvin to Fahrenheit\n";
    cout << "0. Exit\n";
}

int main() {
    while (true) {
        showMenu();
        int choice = readChoice();

        if (choice == 0) {
            cout << "Goodbye!\n";
            break;
        }

        char fromUnit;
        switch (choice) {
            case 1:
            case 3:
                fromUnit = 'C';
                break;
            case 2:
            case 5:
                fromUnit = 'F';
                break;
            default:
                fromUnit = 'K';
                break;
        }

        double value = readNumber("Enter temperature: ");

        if (belowAbsoluteZero(value, fromUnit)) {
            cout << "Error: temperature is below absolute zero.\n";
            continue;
        }

        switch (choice) {
            case 1:
                cout << value << " C = " << celsiusToFahrenheit(value) << " F\n";
                break;
            case 2:
                cout << value << " F = " << fahrenheitToCelsius(value) << " C\n";
                break;
            case 3:
                cout << value << " C = " << celsiusToKelvin(value) << " K\n";
                break;
            case 4:
                cout << value << " K = " << kelvinToCelsius(value) << " C\n";
                break;
            case 5:
                cout << value << " F = " << fahrenheitToKelvin(value) << " K\n";
                break;
            case 6:
                cout << value << " K = " << kelvinToFahrenheit(value) << " F\n";
                break;
        }
    }

    return 0;
}
