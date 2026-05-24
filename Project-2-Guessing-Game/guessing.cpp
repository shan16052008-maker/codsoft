#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>
using namespace std;

class GuessGame {
    private:
        int randomNumber;
        int attempts;
        int maxAttempts;
        int maxrange;
    public:
        GuessGame(){
            srand(time(0));
            attempts = 0;
        }
    void selectDifficulty() {
        int choice;
        cout << "Select Difficulty Level:" << endl;
        cout << "1. Easy (1-50)" << endl;
        cout << "2. Medium (1-100)" << endl;
        cout << "3. Hard (1-200)" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                maxrange = 50;
                maxAttempts = 10;
                break;
            case 2:
                maxrange = 100;
                maxAttempts = 7;
                break;
            case 3:
                maxrange = 200;
                maxAttempts = 5;
                break;
            default:
                cout << "Invalid choice. Defaulting to Medium difficulty." << endl;
                maxrange = 100;
                maxAttempts = 7;
        }
        randomNumber = rand() % maxrange + 1;
    }
    int getValidinput() {
        int guess;
        while (true) {
            cout << "Enter your guess: ";
            cin >> guess;
            if (cin.fail() || guess < 1 || guess > maxrange) {
                cout << "Invalid input. Please enter a number between 1 and " << maxrange << "." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            } else {
                return guess;
            }
        }
    }
    void play() {
        selectDifficulty();
        int userGuess;
        cout <<"\n==========NUMBER GUESSING GAME============\n" << endl;
        cout <<"guess the number between 1 and " << maxrange << "!" << endl;
        while (attempts < maxAttempts) {
            cout << "Attempts left: " << maxAttempts - attempts << endl;
            userGuess = getValidinput();
            attempts++;
            if (userGuess > randomNumber) {
                cout << "Too high! Try again." << endl;
            } else if (userGuess < randomNumber) {
                cout << "Too low! Try again." << endl;
            } else {
                int score = (maxAttempts - attempts + 1) * 10;
                cout << "\n🎉🎊correct guess!\n";
                cout << "attempts used: " << attempts << endl;
                cout << "your score: " << score << endl;
                return;
            }
        }
        cout << "\n❌Game Over!\n";
        cout << "The correct number was: " << randomNumber << endl;
    }
  };
int main() {
    char choice;
    do {
        GuessGame game;
        game.play();
        cout << "Do you want to play again? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');
    cout<<"\n Thank you for playing! Goodbye!\n";
    return 0;
}
