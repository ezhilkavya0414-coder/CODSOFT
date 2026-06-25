#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <cmath>
#include <limits>

using namespace std;

int main()
{
    srand(time(0));

    char playAgain;
    int bestScore = 0;

    do
    {
        int difficulty;
        int maxNumber, maxAttempts;

        cout << "\n=====================================\n";
        cout << "     NUMBER GUESSING CHALLENGE\n";
        cout << "=====================================\n";

        cout << "\nSelect Difficulty Level:\n";
        cout << "1. Easy   (1 - 50, 10 Attempts)\n";
        cout << "2. Medium (1 - 100, 7 Attempts)\n";
        cout << "3. Hard   (1 - 500, 5 Attempts)\n";

        cout << "\nEnter your choice: ";
        cin >> difficulty;

        switch (difficulty)
        {
        case 1:
            maxNumber = 50;
            maxAttempts = 10;
            break;

        case 2:
            maxNumber = 100;
            maxAttempts = 7;
            break;

        case 3:
            maxNumber = 500;
            maxAttempts = 5;
            break;

        default:
            cout << "\nInvalid choice! Medium selected.\n";
            maxNumber = 100;
            maxAttempts = 7;
        }

        int secretNumber = rand() % maxNumber + 1;
        bool guessed = false;

        vector<int> guessHistory;

        cout << "\nI have chosen a number between 1 and "
             << maxNumber << ".\n";
        cout << "You have " << maxAttempts
             << " attempts to guess it.\n";

        int attemptUsed = 0;

        for (int attempt = 1; attempt <= maxAttempts; attempt++)
        {
            int guess;

            cout << "\nGuess #" << attempt << ": ";

            while (!(cin >> guess))
            {
                cout << "❌ Invalid Input! Enter a number: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            if (guess < 1 || guess > maxNumber)
            {
                cout << "⚠ Enter a number between 1 and "
                     << maxNumber << endl;
                attempt--;
                continue;
            }

            guessHistory.push_back(guess);
            attemptUsed = attempt;

            if (guess == secretNumber)
            {
                guessed = true;
                break;
            }

            int diff = abs(secretNumber - guess);

            if (diff <= 5)
                cout << "🔥 VERY HOT! You're extremely close.\n";
            else if (diff <= 15)
                cout << "🌤 WARM! Getting closer.\n";
            else
                cout << "❄ COLD! Far away.\n";

            if (guess < secretNumber)
                cout << "⬆ Try a higher number.\n";
            else
                cout << "⬇ Try a lower number.\n";

            if (attempt == maxAttempts / 2)
            {
                cout << "\n💡 HINT: The number is ";

                if (secretNumber % 2 == 0)
                    cout << "EVEN.\n";
                else
                    cout << "ODD.\n";
            }
        }

        cout << "\n=====================================\n";

        if (guessed)
        {
            int score = (maxAttempts - attemptUsed + 1) * 10;

            if (difficulty == 2)
                score *= 2;
            else if (difficulty == 3)
                score *= 3;

            cout << "🏆 CONGRATULATIONS! YOU WON! 🏆\n";

            if (score > bestScore)
            {
                bestScore = score;
                cout << "⭐ NEW BEST SCORE!\n";
            }

            cout << "\n========== GAME STATS ==========\n";
            cout << "Secret Number : " << secretNumber << endl;
            cout << "Attempts Used : " << attemptUsed << endl;
            cout << "Score         : " << score << endl;
            cout << "Best Score    : " << bestScore << endl;
            cout << "================================\n";
        }
        else
        {
            cout << "😢 GAME OVER!\n";
            cout << "Secret Number was: "
                 << secretNumber << endl;
        }

        cout << "\nYour Guess History: ";

        for (int num : guessHistory)
            cout << num << " ";

        cout << "\n=====================================\n";

        cout << "\nPlay Again? (Y/N): ";
        cin >> playAgain;

    } while (playAgain == 'Y' || playAgain == 'y');

    cout << "\n=====================================\n";
    cout << " Thank You For Playing! 👋\n";
    cout << "=====================================\n";

    return 0;
}
