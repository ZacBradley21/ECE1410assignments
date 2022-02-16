#ifndef PIGGY_BANK_HPP
#define PIGGY_BANK_HPP

#include <iomanip>
#include <iostream>

class PiggyBank //define class
{
public: //make these public
	PiggyBank(); //default constructor
	PiggyBank(double money); //parameter constructor
	~PiggyBank(); //deconstructor
	PiggyBank(PiggyBank const&) = delete; //deleted copy constructor
	double deposit(double money); //deposit function
	double countSavings() const; //countSavings function
	double withdraw(double money); //withdraw function
	void smash(); //smash function
	
private: //make these private
	double balance; //piggy bank balances
	bool smashed; //True or false statement if piggy bank is smashed or not
};
#endif