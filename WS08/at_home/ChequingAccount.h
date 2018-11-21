#pragma once
// Workshop 8 :Virtual Functions
// Name: Kashyap Bharda	
// Student #: 140622176
// Course: OOP244 Fall 2018
// File: ChequingAccount.h

#ifndef SICT_CHEQUINGACCOUNT_H
#define SICT_CHEQUINGACCOUNT_H

#include <iostream>
#include "Account.h"

namespace sict {

	class ChequingAccount : public Account {

		double transactionFee;
		double monthlyFee;

		//Public Member Functions
	public:

		ChequingAccount(double, double, double);

		bool credit(double);

		bool debit(double);

		void monthEnd();

		void display(std::ostream&) const;
	};
}

#endif // !SICT_CHEQUINGACCOUNT_H
