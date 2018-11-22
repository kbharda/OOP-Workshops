// Workshop 8 :Virtual Functions
// Name: Kashyap Bharda	
// Student #: 140622176
// Course: OOP244 Fall 2018
// File: SavingsAccount.cpp

#include <iostream>
#include "SavingsAccount.h"

using namespace std;

namespace sict {

	// Two argument constructor
	SavingsAccount::SavingsAccount(double balance, double rate) : Account(balance)
	{
		if (rate > 0)
		{
			this->interestRate = rate;
		}
		else
		{
			this->interestRate = 0.0;
		}
	}

	// Interest calculate and assign to credit bal with interest 
	void SavingsAccount::monthEnd()
	{
		double interestEarned;
		
		interestEarned = (balance() * interestRate);

		credit(interestEarned);
	}

	// Display Function with set value
	void SavingsAccount::display(std::ostream& ostr) const
	{
		std::cout << "Account type: Savings" << std::endl;
		std::cout.setf(std::ios::fixed);
		std::cout.precision(2);
		std::cout << "Balance: $" << balance() << std::endl;
		std::cout << "Interest Rate (%): " << interestRate * 100 << std::endl;
		std::cout.unsetf(std::ios::fixed);
	}
}