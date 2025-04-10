#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <utility> // for std::pair
#include <iomanip>

using namespace std;

// Function Prototypes
vector<pair<int, int>> readPopulationData(const string& fileName);
void displayBarChart(const string& townName, const vector<pair<int, int>>& data);

int main() {
	string townName, fileName;

	cout << "Enter the name of the town: ";
	getline(cin, townName);

	cout << "Enter the name of the data file: ";
	getline(cin, fileName);

	vector<pair<int, int>> populationData = readPopulationData(fileName);

	if (populationData.empty()) {
		cout << "Error: Could not read data or file is empty.\n";
		return 1;
	}

	displayBarChart(townName, populationData);
	return 0;
}

// Reads population data (year and population) from a file
vector<pair<int, int>> readPopulationData(const string& fileName) {
	ifstream inputFile(fileName);
	vector<pair<int, int>> data;
	int year, population;

	if (!inputFile) {
		cerr << "Error: Unable to open file\"" << fileName << "\".\n";
		return data; // empty
	}

	while (inputFile >> year >> population) {
		data.emplace_back(year, population);
	}

	inputFile.close();
	return data;
}

// Displays a bar chart of the population data
void displayBarChart(const string& townName, const vector<pair<int, int>>& data) {
	cout << "\n" << townName << " Population Growth\n";
	cout << "(each * represents 1,000 people)\n\n";

	for (const auto& entry : data) {
		int year = entry.first;
		int population = entry.second;
		int numStars = population / 1000;

		cout << year << " ";
		for (int i = 0; i < numStars; ++i) {
			cout << "*";
		}
		cout << endl;
	}
}