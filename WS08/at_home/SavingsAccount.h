#pragma once
// Workshop 8 :Virtual Functions
// Name: Kashyap Bharda	
// Student #: 140622176
// Course: OOP244 Fall 2018
// File: SavingsAccount.h

#ifndef SICT_SAVINGSACCOUNT_H
#define SICT_SAVINGSACCOUNT_H

#include "Account.h"

namespace sict {

	class SavingsAccount : public Account {

		//Private data member
	private:

		double  interestRate;

		//Public member functions
	public:

		SavingsAccount(double, double);

		void monthEnd();

		void display(std::ostream&) const;
	};
}

#endif // !SICT_SAVINGSACCOUNT_H

