#pragma once
// Workshop 8 :Virtual Functions
// Name: Kashyap Bharda	
// Student #: 140622176
// Course: OOP244 Fall 2018
// File: iAccount.h

#ifndef SICT_IACCOUNT_H
#define SICT_IACCOUNT_H

namespace sict {

	class iAccount
	{

	public:

		//virtual public member functions
		virtual bool credit(double) = 0;
		virtual bool debit(double) = 0;
		virtual void monthEnd() = 0;
		virtual void display(std::ostream&) const = 0;

		//virtual Destructor
		virtual ~iAccount() = 0;

	};

	iAccount* CreateAccount(const char*, double);
}

#endif // !SICT_IACCOUNT_H
