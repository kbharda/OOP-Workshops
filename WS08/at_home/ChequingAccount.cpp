
// Workshop 8 :Virtual Functions
// Name: Kashyap Bharda	
// Student #: 140622176
// Course: OOP244 Fall 2018
// File: ChequingAccount.h

#include <iostream>
#include "ChequingAccount.h"

using namespace std;

namespace sict {

	ChequingAccount::ChequingAccount(double transaction, double balance, double month) :Account(balance)
	{
		if (transaction > 0)
		{
			this->transactionFee = transaction;
		}
		else
		{
			this->transactionFee = 0.0;
		}

		if (month > 0)
		{
			this->monthlyFee = month;
		}
		else
		{
			this->monthlyFee = 0.0;
		}
	}

	bool ChequingAccount::credit(double amount)
	{
		if (amount > 0) {
			Account::credit(amount);
			Account::debit(transactionFee);
			return true;
		}
		else {

			return false;
		}
	}
	bool ChequingAccount::debit(double amount)
	{
		if (amount > 0)
		{
			Account::debit(amount);
			Account::debit(transactionFee);
			return true;
		}
		else
		{
			return false;
		}
	}
	void ChequingAccount::monthEnd()
	{
		debit(monthlyFee);
	}
	void ChequingAccount::display(std::ostream& os) const
	{
		std::cout << "Account type : Chequing" << std::endl;
		std::cout.setf(std::ios::fixed);
		std::cout.precision(2);
		std::cout << "Balance: $" << balance() << std::endl;
		std::cout << "Per Transaction Fee:" << transactionFee << std::endl;
		std::cout << "Monthly Fee:" << monthlyFee << std::endl;
		std::cout.unsetf(std::ios::fixed);
	}
}