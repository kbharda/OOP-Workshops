
// Workshop 9 :Function Templates 
// Name: Kashyap Bharda	
// Student #: 140622176
// Course: OOP244 Fall 2018
// File: Data.cpp

#include "Data.h"
using namespace std;

namespace sict {
	
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
		std::cout << "Population change from " << year[0] << " to " << year[n - 1] << " is " << static_cast<double>(population[n - 1] - population[0]) / 1000000 << " million" << std::endl;


		// Q2. print whether violent crime rate has gone up or down between 2000 and 2005

		std::cout << "Violent Crime trend is " << (violentCrimeRate[n - 1] < violentCrimeRate[0] ? "down" : "up") << std::endl;


		// Q3 print the GTA number accurate to 0 decimal places

		std::cout << "There are " << static_cast<double>(average(grandTheftAuto, n)) / 1000000 << " million Grand Theft Auto incidents on average a year" << endl;


		// Q4. Print the min and max violentCrime rates

		std::cout << "The Minimun Violent Crime rate was " << static_cast<int>(min(violentCrimeRate, n)) << endl;
		std::cout << "The Maximum Violent Crime rate was " << static_cast<int>(max(violentCrimeRate, n)) << endl;

		std::cout.unsetf(std::ios::fixed);
	}
}