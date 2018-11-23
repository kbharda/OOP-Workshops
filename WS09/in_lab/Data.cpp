
// Workshop 9 :Function Templates 
// Name: Kashyap Bharda	
// Student #: 140622176
// Course: OOP244 Fall 2018
// File: Data.cpp

#include "Data.h"
using namespace std;

namespace sict {
	// readRow extracts a single record from input and stores n data fields in data
	// - includes error checking: checks if the name of the row is valid.
	//
	bool readRow(std::istream& input, const char* name, double* data, int n) {
		char rowname[2000];
		bool ok = !input.bad();

		// row format is 
		// name,1,2,3,4,5,6

		if (ok) {
			// read the name  first

			input.get(rowname, 2000, ',');
			// note: get will read a string upto the , character
			// it will leave the , character in the input buffer 

			// check that the caller is reading the correct row (name)
			// - if the user is reading the wrong row, return an error
			if (std::strcmp(rowname, name) != 0) {
				// wrong row
				std::cout << "Cannot parse row for " << name << std::endl;
				input.ignore(2000, '\n');
				ok = false;
			}
		}

		if (ok)
			// read the data array
			ok = read(input, data, n);

		// finish the line
		input.ignore(2000, '\n');
		return ok;
	}

	bool readRow(std::istream& input, const char* name, int* data, int n) {
		char rowname[2000];
		bool ok = !input.bad();

		// row format is 
		// name,1,2,3,4,5,6

		if (ok) {
			// read the name  first

			input.get(rowname, 2000, ',');
			// note: get will read a string upto the , character
			// it will leave the , character in the input buffer 

			// check that the caller is reading the correct row (name)
			// - if the user is reading the wrong row, return an error
			if (std::strcmp(rowname, name) != 0) {
				// wrong row
				std::cout << "Cannot parse row for " << name << std::endl;
				input.ignore(2000, '\n');
				ok = false;
			}
		}

		if (ok)
			// read the data array
			ok = read(input, data, n);

		// finish the line
		input.ignore(2000, '\n');
		return ok;
	}

	// answers outputs statistics for visual validation of data
	//
	void answers(const int* year, const int* population, const int* violentCrime,
		const double* violentCrimeRate, const int* grandTheftAuto, const int n) {

		// Q1: print the population change in millions of people
		// - print answer correct to 2 decimal places.
		// e..g "6.31 million";
		// note that population is an integer, so dividing by 1000000 would yield "6"

		std::cout.setf(std::ios::fixed);
		std::cout.precision(2);
		std::cout << "Population change from " << year[0] << " to " << year[n - 1] << " is " << static_cast<double>(population[n - 1] - population[0]) / 1000000 << " million " << std::endl;


		// Q2. print whether violent crime rate has gone up or down between 2000 and 2005

		std::cout << "Violet Crime trend is " << (violentCrimeRate[n - 1] < violentCrimeRate[0] ? "down" : "up") << std::endl;


		// Q3 print the GTA number accurate to 0 decimal places

		std::cout << "There are " << static_cast<double>(average(grandTheftAuto, n)) / 1000000 << " million Grand Theft Auto incidents on average a year" << endl;


		// Q4. Print the min and max violentCrime rates

		std::cout << "The Minimun Violent Crime rate was " << static_cast<int>(min(violentCrimeRate, n)) << endl;
		std::cout << "The Maximum Violent Crime rate was " << static_cast<int>(max(violentCrimeRate, n)) << endl;

		std::cout.unsetf(std::ios::fixed);
	}
}