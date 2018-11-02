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
	char * Contact::getPartialStr(const char str[], int start, int end)
	{	
		const int len = strlen(str);
		char *temp = new char[len];
		int i = 0;
		while (str != '\0') {
			if (start == i) {
				strcpy(temp, str[i]);
			}
			i++;
		}
	}

	Contact::Contact()
	{
		//Safe Empty State
		this->contactName[0] = '\0';
		this->phoneNumber = nullptr;
		this->noOfPhoneNum = 0;
	}

	Contact::Contact(const char contactname[], const long long phoneNumbers[], int lengthOfNum)
	{
		if (
			(contactname != nullptr && contactname[0] != '\0') &&
			(phoneNumbers != nullptr) &&
			(lengthOfNum != 0)
			) {
			for (int i = 0; i < lengthOfNum; i++) {
				char phnNumber[14] = "";
				sprintf(phnNumber, "%lld", phoneNumbers[i]);
				phnNumber[14 - 1] = '\0';
				if (strlen(phnNumber) == 11 || strlen(phnNumber) == 12) {
					
				}
			}
		}
		else {
			this->contactName[0] = '\0';
			this->phoneNumber = nullptr;
			this->noOfPhoneNum = 0;
		}
	}

	Contact::~Contact() //Memory Deallocation
	{
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
			cout << "Empty contact!" << endl;
		}
		else
		{
			cout << this->contactName << endl;
		}
	}

}