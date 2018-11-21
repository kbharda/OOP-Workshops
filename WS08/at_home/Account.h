#pragma once

// Workshop 8 :Virtual Functions
// Name: Kashyap Bharda	
// Student #: 140622176
// Course: OOP244 Fall 2018
// File: Account.h

#ifndef SICT_ACCOUNT_H
#define SICT_ACCOUNT_H

#include "iAccount.h"

namespace sict {

	class Account : public iAccount {

		// Private Member
		double accountBal;

	public:
		Account();
		// Private Members
		Account(double);

		bool credit(double);

		bool debit(double);

	protected:
		// Protect Members
		double balance() const;

	};

	iAccount* CreateAccount(const char*, double);
}
#endif // !SICT_ACCOUNT_H
