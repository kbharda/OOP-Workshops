
// Workshop 8 :Virtual Functions
// Name: Kashyap Bharda	
// Student #: 140622176
// Course: OOP244 Fall 2018
// File: ChequingAccount.cpp

#include <iostream>
#include "ChequingAccount.h"

using namespace std;

namespace sict {

	ChequingAccount::ChequingAccount(double balance, double transaction, double month) :Account(balance)
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

	bool ChequingAccount::credit(double cAmount)
	{
		if (cAmount > 0) {
			
			Account::credit(cAmount);
			Account::debit(transactionFee);

			return true;
		}
		else {

			return false;
		}
	}
	bool ChequingAccount::debit(double dAmount)
	{
		if (dAmount > 0)
		{
			Account::debit(dAmount);
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
		Account::debit(monthlyFee);
	}
	void ChequingAccount::display(std::ostream& os) const
	{
		os << "Account type: Chequing" << std::endl;
		os.setf(std::ios::fixed);
		os.precision(2);
		os << "Balance: $" << balance() << std::endl;
		os << "Per Transaction Fee: " << transactionFee << std::endl;
		os << "Monthly Fee: " << monthlyFee << std::endl;
		os.unsetf(std::ios::fixed);
	}
}