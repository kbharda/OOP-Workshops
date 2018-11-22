// Workshop 8 :Virtual Functions
// Name: Kashyap Bharda	
// Student #: 140622176
// Course: OOP244 Fall 2018
// File: Allocator.cpp

#include <iostream>
#include "SavingsAccount.h"
#include "ChequingAccount.h"

using namespace std;

namespace sict {

	// Calling Destrucctor
	iAccount::~iAccount() {

	}
	// Interest Rate
	//const double intrate = 0.05;

	// Allocator Function
	iAccount* CreateAccount(const char* accountType, double balance)
	{
		iAccount* account = nullptr;

		double interestRate = 0.05;
		double transactionFee = 0.50;
		double monthlyFee = 2.00;

		if (accountType[0] == 'S' || accountType[0] == 's')
		{
			account = new SavingsAccount(balance, interestRate);
			return account;
		}
		else if (accountType[0] == 'C' || accountType[0] == 'c')
		{
			account = new ChequingAccount(balance, transactionFee, monthlyFee);
			return account;
		}
		else
		{
			account = nullptr;
			return account;
		}
	}
}

