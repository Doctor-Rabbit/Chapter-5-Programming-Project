#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Function Prototypes
int generateRandomNumber(int min = 1, int max = 100);
void playGuessingGame(int target);

int main() {
	cout << "Welcome to the Number Guessing Game!\n";
	int randomNumber = generateRandomNumber();
	playGuessingGame(randomNumber);
	return 0;
}

// Generates a random number between min and max
int generateRandomNumber(int min, int max) {
	srand(static_cast<unsigned int>(time(0))); // Seed RNG
	return rand() % (max - min + 1) + min;
}

// Handles the guessing loop and feedback
void playGuessingGame(int target) {
	int guess;
	int attempts = 0;

	do {
		cout << "Enter your guess (between 1 and 100): ";
		cin >> guess;
		attempts++;

		if (guess > target) {
			cout << "Too high, try again.\n";
		}
		else if (guess < target) {
			cout << "Too low, try again.\n";
		}
		else {
			cout << "Congratulations! You guessed it in " << attempts << " attempts.\n";
		}
	} while (guess != target);
}