// Workshop 6 : Class with a resource
// Name: Kashyap Bharda	
// Student #: 140622176
// Course: OOP244 Fall 2018
// File: Contact.h

#ifndef SICT_CONTACT_H
#define SICT_CONTACT_H

#define MAX_CHAR 20

namespace sict {

	class Contact
	{
	private:

		char contactName[MAX_CHAR + 1];
		long long* phoneNumber;
		int noOfPhoneNum;

	public:

		Contact();

		Contact(const char*, const long long*, int);

		~Contact();

		bool isEmpty() const;

		void display() const;

	};
}
#endif // !SICT_CONTACT_H
