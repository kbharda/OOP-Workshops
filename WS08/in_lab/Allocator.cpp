// Workshop 8 :Virtual Functions
// Name: Kashyap Bharda	
// Student #: 140622176
// Course: OOP244 Fall 2018
// File: Allocator.cpp

#include <iostream>
#include "SavingsAccount.h"

using namespace std;

namespace sict {

	// Calling Destrucctor
	iAccount::~iAccount() {

	}
	// Interest Rate
	const double intrate = 0.05;

	// Allocator Function
	iAccount * CreateAccount(const char* accountType, double balance)
	{
		iAccount* account = nullptr;

		if (accountType[0] == 'S' || accountType[0] == 's')
		{
			account = new SavingsAccount(balance, intrate);
			return account;
		}
		else
		{
			return nullptr;
		}
	}
}

