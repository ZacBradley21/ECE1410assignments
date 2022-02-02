#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <math.h>

void openFile(std::ifstream& inputfile, std::ofstream& outputfile);
void printResult(std::ofstream& outputfile);

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
	std::ofstream outputfile;
	openFile(inputfile, outputfile);
	printResult(outputfile);
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
void printResult(std::ofstream& outputfile) {
	//Set the formatting necessary for program to build under each column
	outputfile << std::setprecision(2) << std::fixed;
	outputfile << std::setw(10) << std::left << "Letter" << std::setw(10) << std::left
		<< "Count" << "Percentage" << std::endl;
}