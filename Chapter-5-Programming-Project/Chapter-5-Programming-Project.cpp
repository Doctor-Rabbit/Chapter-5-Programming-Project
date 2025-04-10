#include <iostream>

using namespace std;

// Function Prototypes
void displayPatternA();
void displayPatternB();

int main() {
	cout << "Pattern A" << endl;
	displayPatternA();

	cout << "\nPattern B" << endl;
	displayPatternB();

	return 0;
}

// Displays Pattern A
void displayPatternA() {
	for (int i = 1; i <= 10; ++i) {
		for (int j = 1; j <= i; ++j) {
			cout << "+";
		}
		cout << endl;
	}
}

// Displays Pattern B
void displayPatternB() {
	for (int i = 10; i >= 1; --i) {
		for (int j = 1; j <= i; ++j) {
			cout << "+";
		}
		cout << endl;
	}
}