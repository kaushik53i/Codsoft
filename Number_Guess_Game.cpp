#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int highScore = 999; 

void play_game(int min, int max, int maxAttempts) {
    srand(time(0));
    int secretNumber = rand() % (max - min + 1) + min;
    int guess, attempts = 0;
    
    cout << "\nWelcome to the Number Guessing Game!";
    cout << "\nGuess a number between " << min << " and " << max << ".";
    if (maxAttempts != -1) {
        cout << "\nYou have " << maxAttempts << " attempts!";
    }
    
    do {
        cout << "\nEnter your guess: ";
        cin >> guess;
        attempts++;
        
        if (guess > secretNumber) {
            cout << "Too high! Try again.";
        } else if (guess < secretNumber) {
            cout << "Too low! Try again.";
        } else {
            cout << "\nCongratulations! You guessed the number in " << attempts << " attempts!";
            if (attempts < highScore) {
                highScore = attempts;
                cout << "\nNew High Score!";
            }
            break;
        }
        
        if (maxAttempts != -1 && attempts >= maxAttempts) {
            cout << "\nOut of attempts! The correct number was " << secretNumber << ".";
            break;
        }
    } while (true);
}

void choose_level() {
    int choice, min = 1, max = 100, maxAttempts = -1;
    cout << "\nChoose Difficulty Level:";
    cout << "\n1. Easy (1-50, Unlimited Attempts)";
    cout << "\n2. Medium (1-100, 10 Attempts)";
    cout << "\n3. Hard (1-200, 7 Attempts)";
    cout << "\n4. Custom Mode (Set your own range & attempts)";
    cout << "\nEnter your choice: ";
    cin >> choice;
    
    switch (choice) {
        case 1: 
			min = 1; 
			max = 50; 
			maxAttempts = -1; 
			break;
        case 2: 
			min = 1; 
			max = 100; 
			maxAttempts = 10; 
			break;
        case 3: 
			min = 1; 
			max = 200; 
			maxAttempts = 7; 
			break;
        case 4:
            cout << "Enter min number: "; 
			cin >> min;
            cout << "Enter max number: "; 
			cin >> max;
            cout << "Enter max attempts (-1 for unlimited): "; 
			cin >> maxAttempts;
            break;
        default:
            cout << "Invalid choice! Defaulting to Medium difficulty.";
            min = 1; max = 100; maxAttempts = 10;
    }
    
    play_game(min, max, maxAttempts);
}

int main() {
    char playAgain;
    do {
        choose_level();
        cout << "\nDo you want to play again? (y/n): ";
        cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');
    
    cout << "\nThanks for playing! Your best score was " << highScore << " attempts. Goodbye!\n";
    return 0;
}
