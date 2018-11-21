// Workshop 8 :Virtual Functions
// Name: Kashyap Bharda	
// Student #: 140622176
// Course: OOP244 Fall 2018
// File: Account.cpp

#include <iostream>
#include "iAccount.h"
#include "Account.h"

using namespace std;

namespace sict {

	
	double Account::balance() const
	{
		return accountBal;
	}

	Account::Account()
	{
	}

	// One Argument Consructor
	Account::Account(double balance)
	{
		if (balance > 0)
		{
			this->accountBal = balance;
		}
		else
		{
			balance = 0.0;
		}
	}

	// Credit from Balance
	bool Account::credit(double balance)
	{
		if (balance > 0)
		{
			this->accountBal += balance;
			return true;
		}
		else
		{
			return false;
		}

	}

	// Debit from balance
	bool Account::debit(double balance)
	{
		if (balance > 0)
		{
			this->accountBal -= balance;
			return true;
		}
		else
		{
			return false;
		}

	}
}