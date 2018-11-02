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
		//Safe Empty State
		this->contactName[0] = '\0';
		this->phoneNumber = nullptr;
		this->lengthOfPhoneNumber = 0;
	}

	Contact::Contact(const char contactname[], const long long phoneNumbers[], int lengthOfNum)
	{
		if (
			(contactname != nullptr && contactname[0] != '\0') &&
			(phoneNumbers != nullptr) &&
			(lengthOfNum != 0)
			) {
			int long long* pn = new int long long[lengthOfNum];
			int validCount = 0;
			for (int i = 0; i < lengthOfNum; i++) {
				char phnNumber[14] = "";
				sprintf(phnNumber, "%lld", phoneNumbers[i]);
				phnNumber[14 - 1] = '\0';
				if (strlen(phnNumber) == 11 || strlen(phnNumber) == 12) {
					int numberStart;
					int areaCodeStart;
					if (strlen(phnNumber) == 11) {
						numberStart = 4;
						areaCodeStart = 1;
					}
					else {
						numberStart = 5;
						areaCodeStart = 2;
					}
					const char *number = this->getPartialStr(phnNumber, numberStart, strlen(phnNumber) - 1);
					const char *areaCode = this->getPartialStr(phnNumber, areaCodeStart, areaCodeStart + 2);
					if (!((number[0] - '0' == 0) || (areaCode[0] - '0' == 0) || (phnNumber[0] - '0' == 0))) {
						pn[validCount++] = phoneNumbers[i];
					}
				}
			}
			if (validCount == 0) {
				this->contactName[0] = '\0';
				this->phoneNumber = nullptr;
				this->lengthOfPhoneNumber = 0;
			}
			else {
				this->phoneNumber = new long long[validCount];
				for (int j = 0; j < validCount; j++) {
					this->phoneNumber[j] = pn[j];
				}
				this->lengthOfPhoneNumber = validCount;
			}
		}
		else {
			this->contactName[0] = '\0';
			this->phoneNumber = nullptr;
			this->lengthOfPhoneNumber = 0;
		}
	}

	Contact::~Contact() //Memory Deallocation
	{
		delete[] phoneNumber;
		phoneNumber = nullptr;
	}


	bool Contact::isEmpty() const
	{
		if (this->phoneNumber == nullptr && this->contactName[0] == '\0' && this->lengthOfPhoneNumber == 0)
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
			
			for (int i = 0; i < this->lengthOfPhoneNumber; i++) {
				char phnNumber[14] = "";
				sprintf(phnNumber, "%lld",this->phoneNumber[i]);
				int numberStart;
				int areaCodeStart;
				if (strlen(phnNumber) == 11) {
					numberStart = 4;
					areaCodeStart = 1;
					cout << "(+" << phnNumber[0] << ") ";
				}
				else {
					numberStart = 5;
					areaCodeStart = 2;
					cout << "(+" << phnNumber[0] << phnNumber[1] << ") ";
				}
				const char *number = this->getPartialStr(phnNumber, numberStart, strlen(phnNumber) - 1);
				const char *areaCode = this->getPartialStr(phnNumber, areaCodeStart, areaCodeStart + 2);
				cout << areaCode << " ";
				int j = 0;
				while (number[j] != '\0') 
				{	
					if (j == 3) {
						cout << "-";
					}
					cout << number[j];
					j++;
				}
				cout << endl;
			}
		}
	}

	char * Contact::getPartialStr(char* str, int start, int end) const
	{
		const int len = strlen(str);
		char *temp = new char[len];
		int i = 0;
		int j = 0;
		while (str[i] != '\0') {
			if (i >= start && i <= end) {
				temp[j++] = str[i];
			}
			i++;
		}
		temp[j] = '\0';
		return temp;
	}

}