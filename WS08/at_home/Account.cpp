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

	Account::Account() {
		accountBal = 0;
	}

	double Account::balance() const
	{
		return accountBal;
	}

	// One Argument Consructor
	Account::Account(double balance = 0)
	{
		if (balance > 0)
		{
			this->accountBal = balance;
		}
		else
		{
			balance = 0;
		}
	}

	// Credit from Balance
	bool Account::credit(double cBalance)
	{
		if (cBalance > 0)
		{
			this->accountBal += cBalance;
			return true;
		}
		else
		{
			return false;
		}
	}

	// Debit from balance
	bool Account::debit(double dBalance)
	{
		if (dBalance > 0)
		{
			this->accountBal -= dBalance;
			return true;
		}
		else
		{
			return false;
		}

	}
}