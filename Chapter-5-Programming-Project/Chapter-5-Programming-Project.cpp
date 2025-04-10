#include <iostream>
#include <iomanip>

using namespace std;

// Function Prototypes
int getStartingPopulation();
double getDailyIncrease();
int getNumberOfDays();
void displayPopulationGrowth(int startPop, double dailyIncrease, int numDays);

int main() {
	cout << "Population Growth Predictor\n";

	int startingPopulation = getStartingPopulation();
	double dailyIncrease = getDailyIncrease();
	int numberOfDays = getNumberOfDays();

	displayPopulationGrowth(startingPopulation, dailyIncrease, numberOfDays);

	return 0;
}

// Function to get and validate starting population
int getStartingPopulation() {
	int population;
	do {
		cout << "Enter the starting number of organisms (minimum 2): ";
		cin >> population;
		if (population < 2) {
			cout << "Error: Starting Population must be at least 2.\n";
		}
	} while (population < 2);
	return population;
}

// Function to get and validate daily increase
double getDailyIncrease() {
	double increase;
	do {
		cout << "Enter the average daily population increase (as a percentage): ";
		cin >> increase;
		if (increase < 0) {
			cout << "Error: Daily incease cannot be negative.\n";
		}
	} while (increase < 0);
	return increase;
}

// Funtion to get and validate number of days
int getNumberOfDays() {
	int days;
	do {
		cout << "Enter the number of days the organisms will multiply (minimum 1): ";
		cin >> days;
		if (days < 1) {
			cout << "Error: Number of days must be at least 1.\n";
		}
	} while (days < 1);
	return days;
}

// Function to display population growth
void displayPopulationGrowth(int startPop, double dailyIncrease, int numDays) {
	cout << fixed << setprecision(2);
	cout << "\nDay\tPopulation\n";
	cout << "----------------------\n";

	double population = startPop;
	for (int day = 1; day <= numDays; ++day) {
		cout << day << "\t" << population << endl;
		population += population * (dailyIncrease / 100);
	}
}