#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <limits>

using namespace std;

// Function Prototypes
vector<string> readNamesFromFile(const string& filename);
void findFrontAndBack(const vector<string>& names, string& front, string& back);

int main() {
	const string filename = "LineUp.txt";
	vector<string> studentNames = readNamesFromFile(filename);

	if (studentNames.empty()) {
		cout << "No students found in the file." << endl;
	}
	else {
		string frontOfLine, backOfLine;
		findFrontAndBack(studentNames, frontOfLine, backOfLine);

		cout << "Number of students: " << studentNames.size() << endl;
		cout << "Student at the front of the line: " << frontOfLine << endl;
		cout << "Student at the end of the line: " << backOfLine << endl;
	}

	return 0;
}

// Reads names from the file and returns them in a vector
vector<string> readNamesFromFile(const string& filename) {
	ifstream inputFile(filename);
	vector<string> names;
	string name;

	if (!inputFile) {
		cerr << "Error opening file: " << filename << endl;
		return names; // Emptyvector
	}

	while (inputFile >> name) {
		names.push_back(name);
	}

	inputFile.close();
	return names;
}

// Find the front and back of the line based on alphabetical order
void findFrontAndBack(const vector<string>& names, string& front, string& back) {
	front = names[0];
	back = names[0];

	for (const string& name : names) {
		if (name < front) {
			front = name;
		}
		if (name > back) {
			back = name;
		}
	}
}