// Workshop 6 : Class with a resource
// Name: Kashyap Bharda	
// Student #: 140622176
// Course: OOP244 Fall 2018
// File: Contact.cpp

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include "Contact.h"

using namespace std;
using namespace sict;

namespace sict {

	Contact::Contact()
	{
		this->contactName[0] = '\0';
		this->phoneNumber = nullptr;
		this->noOfPhoneNum = 0;
	}

	Contact::Contact(const char* contactname, const long long* phoneNumbers, int lengthOfNum)
	{

		//memory Allocation
		if (phoneNumbers != nullptr && phoneNumbers[0] != '\0')
		{
			phoneNumber = new long long[lengthOfNum];
		}

		// 16478313654
		int i;
		for (i = 0; i < lengthOfNum; i++)
		{
			long long n = phoneNumbers[i];

		}
	}

	Contact::~Contact()
	{
		//Memory Deallocation
		delete[] phoneNumber;
		phoneNumber = nullptr;
	}


	bool Contact::isEmpty() const
	{
		if (this->phoneNumber == nullptr && this->contactName[0] == '\0' && noOfPhoneNum == 0)
		{
			return true;
		}
		else
		{
			return false;
		}

	}

	void Contact::display() const
	{
		if (isEmpty())
		{

		}
	}

}