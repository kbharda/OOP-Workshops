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

	Contact::Contact(const char contactname[], const long long phoneNumbers[], int lengthOfNum) //3 Argument Construct
	{
		if (contactname != nullptr && contactname[0] != '\0') {
			strncpy(this->contactName, contactname, MAX_CHAR);
			this->contactName[MAX_CHAR] = '\0';
		}
		else {
			this->contactName[0] = '\0';
		}

		if (contactname != nullptr && contactname[0] != '\0'
			(phoneNumbers != nullptr) && //Phone not NULL
			(lengthOfNum != 0) //Number length Not NULL
			) {
			// If parameters are not empty then valdate phone numbers 

			int long long* pn = new int long long[lengthOfNum]; //create temp phonenumber array to hold valid numbers

			int validCount = 0; // variable for valid phone number count

			for (int i = 0; i < lengthOfNum; i++) {

				char phnNumber[14] = ""; // hold string type phone number

				sprintf(phnNumber, "%lld", phoneNumbers[i]); //Convert long long to char[]

				phnNumber[14 - 1] = '\0'; // set last char to null to avaoid memory leak

				if (strlen(phnNumber) == 11 || strlen(phnNumber) == 12) {
					// length of phone number is 10 plus country code(1 or 2 digits) i.e 11 or 12 in total
					// if length of phone number is 11 or 12 then its a valid phone number


					int numberStart; // index for validating 7 digit number
					int areaCodeStart; // index for validating 3 digit area code

					if (strlen(phnNumber) == 11) { //check if length of phone num = 11
						numberStart = 4; // index for number is 4 if phone number length is 11
						areaCodeStart = 1; // index for area code is 1 if phone number length is 11
					}
					else {
						numberStart = 5; // index for number is 5 if phone number length is 12
						areaCodeStart = 2; // index for area code is 2 if phone number length is 12
					}

					// seperate number and area code using getPartialStr function
					const char *number = this->getPartialStr(phnNumber, numberStart, strlen(phnNumber) - 1);
					const char *areaCode = this->getPartialStr(phnNumber, areaCodeStart, areaCodeStart + 2);

					// if first index of number, area code is NOT zero than its valid
					// if first index of phoneNumber is not zero (which is country code) than its valid
					if (!((number[0] - '0' == 0) || (areaCode[0] - '0' == 0) || (phnNumber[0] - '0' == 0))) {
						pn[validCount++] = phoneNumbers[i]; // if phone number pases all validation then add
															// it to temp phone number and increment valid counter
					}
				}
			} // for end

			if (validCount == 0) { // if valid counter is 0 then all phone numbers are invalid, then set object to safe empty state
				this->phoneNumber = nullptr;
				this->lengthOfPhoneNumber = 0;
			}
			else {
				// Dynamically allocate memmory for current phone number array based on valid count;
				this->phoneNumber = new long long[validCount];
				for (int j = 0; j < validCount; j++) {
					this->phoneNumber[j] = pn[j]; // copy all valid numbers from temp pn to current object
				}
				delete[] pn;
				this->lengthOfPhoneNumber = validCount; // se the length of valid numbers to current object
			}
		}
		else {

			//set objects Safe Empty State
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
	//	cout << this->contactName << endl;

		if (isEmpty())
		{
			cout << "Empty contact!" << endl;
		}
		else
		{
			cout << this->contactName << endl;
			for (int i = 0; i < this->lengthOfPhoneNumber && this->phoneNumber != nullptr; i++) {
				char phnNumber[14] = "";
				sprintf(phnNumber, "%lld", this->phoneNumber[i]);
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

	/*
		This function seperates the char* from the index passed and return
	*/
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