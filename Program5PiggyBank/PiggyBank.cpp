#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <thread>
#include <vector>
#include <sstream>

/*
Program Header
Function Title: PiggyBank
Summary: This program initializes many functions that take in parameters
that will be evaluated, changed, and returned depending on the function,
and what is required for the assignment.
Inputs: Money, and none
Outputs: Money, and none
**********************
PSEUDOCODE
Begin
	Initialize empty PiggyBank
	Initialize PiggyBank that uses initial input of money to determine initial balance
	Create deconstructor that prints out amount of money left when deconstructed
	Create deposit function that adds it to the balance if it is not negative, and not smashed
	Create countSavings function that returns balance and takes no parameters
	Make the withdraw function that withdraws money if it is not greater than balance, not negative, and not broken
	Initialize smash function that, when called, smashes piggy bank by turning the bool value
	to true. It then checks if the balance is positive, and if so, prints the balance
End
*/

#include "PiggyBank.hpp"
//Initialize empty PiggyBank
PiggyBank::PiggyBank()
	: balance(0), smashed(0)
{
}
//Initialize PiggyBank that uses initial input of money to determine initial balance
PiggyBank::PiggyBank(double money)
{
	if (money > 0) {
		balance = money;
		smashed = false;
	}
	else {
		balance = 0;
		smashed = false;
	}
}
//Create deconstructor that prints out amount of money left when deconstructed
PiggyBank::~PiggyBank() {
	if (smashed == false) {
		std::cout << "Piggy bank had $" << balance << " upon deconstruction"
			<< std::endl;
	}
}
//Create deposit function that adds it to the balance if it is not negative, and not smashed
double PiggyBank::deposit(double money) {
	if (money > 0) {
		balance += money;
	}
	else if (money < 0) {
		std::cout << "Cannot deposit negative" << std::endl;
	}
	if (smashed == true) {
		std::cout << "Cannot deposit money into broken bank" << std::endl;
	}
	return money;
}
//Create countSavings function that returns balance and takes no parameters
double PiggyBank::countSavings() const {
	return balance;
}
//Make the withdraw function that withdraws money if it is not greater than balance, not negative, and not broken
double PiggyBank::withdraw(double money) {
	if (money > balance) {
		std::cout << "Cannot withdraw more money than is available" << std::endl;
	}
	else if (money > 0) {
		balance -= money;
	}
	else if (money < 0) {
		std::cout << "Cannot withdraw negative" << std::endl;
	}
	if (smashed == true) {
		std::cout << "Cannot withdraw money into broken bank" << std::endl;
	}
	return money;
}
//Initialize smash function that, when called, smashes piggy bank by turning the bool value
//to true. It then checks if the balance is positive, and if so, prints the balance
void PiggyBank::smash() {
	if (smashed == false) {
		smashed = true;
		if (balance > 0) {
			std::cout << "NOOO!!! You lost $" << balance << std::endl;
		}
	}
}