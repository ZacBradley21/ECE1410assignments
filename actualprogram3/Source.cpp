#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <math.h>
#include <array>

#define ALPHABET 52
#define SIZE 100000

void openFile(std::ifstream& inputfile, std::ofstream& outputfile);
void myArray(std::ifstream& inputfile);
int count(std::ifstream& inputfile, char array[], int letter);
void printResult(std::ofstream& outputfile, char array[]);

/*
Program Header
Function Title: main
Summary: This function calls the functions listed in this program and
executes them in proper order.
Inputs: None
Outputs: None
**********************
PSEUDOCODE
Begin
	Call all functions, and close the files
End
*/
int main(void) {
	//Call all  functions, and close the files
	std::ifstream inputfile;
	//char array[SIZE];
	int totalLetters = 0;
	std::ofstream outputfile;
	openFile(inputfile, outputfile);
	myArray(inputfile);
	int count(inputfile, myArray, letter);
	void printResult(outputfile, myArray);
	inputfile.close();
	outputfile.close();
	return 0;
}

/*
Program Header
Function Title: openFile
Summary: This function asks the user to input the file to be used later.
The function will determine if the file exists. If it does not, it will
print an error message and then quit. It will also open an output file
that will be edited later.
Inputs: inputfile, outputfile
Outputs: None
**********************
PSEUDOCODE
Begin
	Initialize inputFileName, and ask user for input file name
	Use an if else statement to check if the file exists or not
	Initialize outputFileName, ask the user to name it, and open that file as well
End
*/

void openFile(std::ifstream& inputfile, std::ofstream& outputfile) {
	//Initialize inputFileName, and ask user for input file name
	std::string inputFileName;
	std::cout << "Enter input file name:" << std::endl;
	std::cin >> inputFileName;
	inputfile.open(inputFileName);
	//Use an if else statement to check if the file exists or not
	if (!inputfile) {
		std::cout << "The file name you entered does not exist" << std::endl;
		exit(0);
	}

	else {
		std::cout << "File exists!" << std::endl;
	}
	//Initialize outputFileName, ask the user to name it, and open that file as well
	std::string outputFileName;
	std::cout << "What would you like to name the output file?" << std::endl;
	std::cin >> outputFileName;
	outputfile.open(outputFileName);
}

void myArray(std::ifstream& inputfile) {
	int totalChars = 0;
	int i = 0;
	char myArray[SIZE];
	int arrSize = sizeof(array) / sizeof(array[0]);
	while (!inputfile.eof()) {
		inputfile >> myArray[i];
		i++;
		totalChars++;
	}
	
	for (int i = 0; i <= totalChars; i++) {
		if (ispunct(myArray[i])) {
			static_cast<std::string>(myArray).erase(i--, 1);

		}
	}
}

int count(std::ifstream& inputfile, char array[], int letter) {
	int counter;
	int arrSize = sizeof(array) / sizeof(array[0]);
	letter = static_cast<char>(letter);
	for (int i = 0; i < arrSize; i++) {
		if (array[i] == letter) {
			counter++;
		}
	}
	return counter;
}
/*
Program Header
Function Title: printResult
Summary: This function
Inputs: outputfile
Outputs: None
**********************
PSEUDOCODE
Begin
	Set the formatting necessary for program to build under each column
End
*/

void printResult(std::ofstream& outputfile, char array[]) {
	//Set the formatting necessary for program to build under each column
	outputfile << std::setprecision(2) << std::fixed;
	outputfile << std::setw(15) << std::left << "Letter" << std::setw(10) << std::left
		<< "Count" << "Percentage" << std::endl;

	for (int i = 65; i <= 90; i++) {
		double p = count(array, i);
		double answer = (p / array.length) * 100;
		std::cout << "  %c \t  %.0f \t  %.2f %%", i, p, answer << std::endl;
	}
}
