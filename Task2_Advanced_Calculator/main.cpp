#include <iostream>
#include <cmath>
#include <vector>
#include <limits>

using namespace std;

int main() {
    vector<string> history;
    int choice;
    char again;

    cout << "=====================================\n";
    cout << "      ADVANCED CALCULATOR\n";
    cout << "=====================================\n";

    do {
        cout << "\nChoose an Operation:\n";
        cout << "1. Addition\n";
        cout << "2. Subtraction\n";
        cout << "3. Multiplication\n";
        cout << "4. Division\n";
        cout << "5. Modulus\n";
        cout << "6. Power\n";
        cout << "7. Square Root\n";
        cout << "8. Percentage\n";
        cout << "9. View History\n";
        cout << "0. Exit\n";

        cout << "\nEnter your choice: ";
        cin >> choice;

        if(cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "❌ Invalid Input!\n";
            continue;
        }

        double num1, num2, result;

        switch(choice) {

        case 1:
            cout << "Enter two numbers: ";
            cin >> num1 >> num2;
            result = num1 + num2;
            cout << "Result = " << result << endl;
            history.push_back(to_string(num1) + " + " +
                              to_string(num2) + " = " +
                              to_string(result));
            break;

        case 2:
            cout << "Enter two numbers: ";
            cin >> num1 >> num2;
            result = num1 - num2;
            cout << "Result = " << result << endl;
            history.push_back(to_string(num1) + " - " +
                              to_string(num2) + " = " +
                              to_string(result));
            break;

        case 3:
            cout << "Enter two numbers: ";
            cin >> num1 >> num2;
            result = num1 * num2;
            cout << "Result = " << result << endl;
            history.push_back(to_string(num1) + " * " +
                              to_string(num2) + " = " +
                              to_string(result));
            break;

        case 4:
            cout << "Enter two numbers: ";
            cin >> num1 >> num2;

            if(num2 == 0) {
                cout << "❌ Cannot divide by zero!\n";
            }
            else {
                result = num1 / num2;
                cout << "Result = " << result << endl;
                history.push_back(to_string(num1) + " / " +
                                  to_string(num2) + " = " +
                                  to_string(result));
            }
            break;

        case 5:
            int a, b;
            cout << "Enter two integers: ";
            cin >> a >> b;

            if(b == 0) {
                cout << "❌ Cannot perform modulus by zero!\n";
            }
            else {
                cout << "Result = " << a % b << endl;
                history.push_back(to_string(a) + " % " +
                                  to_string(b) + " = " +
                                  to_string(a % b));
            }
            break;

        case 6:
            cout << "Enter base and exponent: ";
            cin >> num1 >> num2;
            result = pow(num1, num2);
            cout << "Result = " << result << endl;
            history.push_back(to_string(num1) + " ^ " +
                              to_string(num2) + " = " +
                              to_string(result));
            break;

        case 7:
            cout << "Enter a number: ";
            cin >> num1;

            if(num1 < 0) {
                cout << "❌ Square root of negative number not possible!\n";
            }
            else {
                result = sqrt(num1);
                cout << "Result = " << result << endl;
                history.push_back("sqrt(" +
                                  to_string(num1) + ") = " +
                                  to_string(result));
            }
            break;

        case 8:
            cout << "Enter value and total value: ";
            cin >> num1 >> num2;

            if(num2 == 0) {
                cout << "❌ Total value cannot be zero!\n";
            }
            else {
                result = (num1 / num2) * 100;
                cout << "Percentage = " << result << "%\n";
                history.push_back(to_string(num1) + "/" +
                                  to_string(num2) + " *100 = " +
                                  to_string(result) + "%");
            }
            break;

        case 9:
            cout << "\n========== HISTORY ==========\n";

            if(history.empty()) {
                cout << "No calculations performed yet.\n";
            }
            else {
                for(size_t i = 0; i < history.size(); i++) {
                    cout << i + 1 << ". "
                         << history[i] << endl;
                }
            }

            cout << "=============================\n";
            break;

        case 0:
            cout << "\nThank you for using Advanced Calculator!\n";
            return 0;

        default:
            cout << "❌ Invalid Choice!\n";
        }

        cout << "\nPerform another calculation? (Y/N): ";
        cin >> again;

    } while(again == 'Y' || again == 'y');

    cout << "\n=====================================\n";
    cout << " Thank You For Using Calculator 👋\n";
    cout << "=====================================\n";

    return 0;
}
