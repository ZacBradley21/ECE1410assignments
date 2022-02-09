#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <thread>
#include <vector>
#include <sstream>

/*
Program Header
Function Title: Main
Summary: This program runs Conway's Game of Life
Inputs: Command line tokens to be evaluated
Outputs: None
**********************
PSEUDOCODE
Begin
    Initialize fstream f to open the first element of argv which is the input file
    Check if file exists and print message upon success or failure
    Initialize three integer variables called width height and rounds
    Set the first three numbers of the file to width, height, and rounds
    Initialize three two dimensional vector arrays with width and height as parameters
    Initialize the first board with correct parameters
    Initialize the bigger board to all zeros to create the border
    Put the smaller board into the middle of the bigger board
    Initialize the final board as all zeros for now
    Initialize an integer trueCount and set it equal to zero, and open the output file
    Use a for loop to iterate the amount of rounds, pause the program for 100 milliseconds,
    and put the smaller board into the middle of the bigger board again
    Use nested for loops to move around the board. Don't include the space we are on in trueCount
    If we are on center square and it's 1, subtract 1. Count neighbors only
    If neighbors are equal to 1, add 1 to trueCount
    Keep cells alive if 2 or 3 neighbors are alive
    Bring cells alive if exactly 3 neighbors are alive
    In any other instance, kill the cell if it was alive, or keep dead
    Reset trueCount to 0 after it loops
    Set first board equal to the final board
    Print each round of the board to the screen with proper formatting
    Print the board to the output file using proper formatting
    Return 0 to end the program
End
*/


int main(int argc, char* argv[]) {
    //Initialize fstream f to open the first element of argv which is the input file
    std::fstream f;
    f.open(argv[1]);
    //Check if file exists and print message upon success or failure
    if (!argv[1]) {
        std::cout << "Incorrect input file, exiting..." << std::endl;
        exit(1);
    }
    else {
        std::cout << "Correct input file!" << std::endl;
    }
    //Initialize three integer variables called width, height, and rounds
    int width, height, rounds;
    //Set the first three numbers of the file to width, height, and rounds
    f >> width;
    f >> height;
    f >> rounds;
    //Initialize three two dimensional vector arrays with width and height as parameters
    std::vector<std::vector<int>> board1(width, std::vector<int>(height));
    std::vector<std::vector<int>> board2(width + 2, std::vector<int>(height + 2));
    std::vector<std::vector<int>> board3(width, std::vector<int>(height));

    //Initialize the first board with correct parameters
    for (int j = 0; j < height; j++) {
        for (int i = 0; i < width; i++) {
            f >> board1[i][j];
        }
    }

    //Initialize the bigger board to all zeros to create the border
    for (int j = 0; j < height + 2; j++) {
        for (int i = 0; i < width + 2; i++) {
            board2[i][j] = 0;
        }
    }
    //Put the smaller board into the middle of the bigger board
    for (int x = 1; x < width + 1; x++) {
        for (int y = 1; y < height + 1; y++) {
            board2[x][y] = board1[x - 1][y - 1];
        }
    }
    //Initialize the final board as all zeros for now
    for (int j = 0; j < height; j++) {
        for (int i = 0; i < width; i++) {
            board3[i][j] = 0;
        }
    }
    //Initialize an integer trueCount and set it equal to zero, and open the output file
    int trueCount = 0;
    std::ofstream outputfile;
    outputfile.open(argv[2]);
    //Use a for loop to iterate the amount of rounds, pause the program for 100 milliseconds,
    //and put the smaller board into the middle of the bigger board again
    for (int c = 0; c < rounds; c++) {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        for (int x = 1; x < width + 1; x++) {
            for (int y = 1; y < height + 1; y++) {
                board2[x][y] = board1[x - 1][y - 1];
            }
        }
    //Use nested for loops to move around the board. Don't include the space we are on in trueCount
        for (int x = 1; x < width + 1; x++) {
            for (int y = 1; y < height + 1; y++) {
                for (int i = x - 1; i < x + 2; i++) {
                    for (int j = y - 1; j < y + 2; j++) {
                        //If we are on center square and it's 1, subtract 1. Count neighbors only
                        if (i == x && j == y) {
                            if (board2[x][y] == 1) {
                                trueCount -= 1;
                            }
                        }
                        //If neighbors are equal to 1, add 1 to trueCount
                        if (board2[i][j] == 1) {
                            trueCount += 1;
                        }
                    }
                }
                //Keep cells alive if 2 or 3 neighbors are alive
                if (board2[x][y] == 1 && (trueCount == 2 || trueCount == 3)) {
                    board3[x - 1][y - 1] = 1;
                }
                //Bring cells alive if exactly 3 neighbors are alive
                else if (board2[x][y] == 0 && trueCount == 3) {
                    board3[x - 1][y - 1] = 1;
                }
                //In any other instance, kill the cell if it was alive, or keep dead
                else {
                    board3[x - 1][y - 1] = 0;
                }
                //Reset trueCount to 0 after it loops
                trueCount = 0;
            }
        }
        //Set first board equal to the final board
        for (int i = 0; i < width; i++) {
            for (int j = 0; j < height; j++) {
                board1[i][j] = board3[i][j];
            }
        }
        //Print each round of the board to the screen with proper formatting
        for (int a = 0; a < height; a++) {
            for (int b = 0; b < width; b++) {
                if (board3[b][a] == 1) {
                    std::cout << "o" << " ";
                }
                else {
                    std::cout << " " << " ";
                }
            }
            std::cout << std::endl;
        }
        //Print the board to the output file using proper formatting
        if (c == rounds - 1) {
            for (int a = 0; a < height; a++) {
                for (int b = 0; b < width; b++) {
                    if (board3[b][a] == 1) {
                        outputfile << "o" << " ";
                    }
                    else {
                        outputfile << " " << " ";
                    }
                }
                outputfile << std::endl;
            }
        }
    }
    //Return 0 to end the program
    return 0;
}