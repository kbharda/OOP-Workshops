// Workshop 6 : Class with a resource
// Name: Kashyap Bharda	
// Student #: 140622176
// Course: OOP244 Fall 2018
// File: Contact.h

#ifndef SICT_CONTACT_H
#define SICT_CONTACT_H

namespace sict {

	const int MAX_CHAR = 20;

	class Contact
	{
	private:

		char contactName[MAX_CHAR + 1];
		long long* phoneNumber;
		int lengthOfPhoneNumber;

		char* getPartialStr(char*, int start, int end) const;

	public:

		Contact();

		Contact(const char[], const long long[], int);

		~Contact();

		bool isEmpty() const;

		void display() const;

		Contact(const Contact&);
		Contact& operator=(const Contact&);

		Contact& operator+=(const Contact& rhs);
	};
}
#endif // !SICT_CONTACT_H
