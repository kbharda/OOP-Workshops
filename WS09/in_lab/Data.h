#pragma once

// Workshop 9 :Function Templates 
// Name: Kashyap Bharda	
// Student #: 140622176
// Course: OOP244 Fall 2018
// File: Data.h

#ifndef SICT_DATA_H
#define SICT_DATA_H

#include <iostream>
#include <cstring>

using namespace std;

namespace sict {
	// These numbers define 
	// a) the range of data we expect to see in this workshop
	//    0 to 1 billion
	//    use them in the min and max function
	// b) the output column width for a single data field

	const int LARGEST_NUMBER = 1000000000; // 1,000,000,000
	const int SMALLEST_NUMBER = 0;
	const int COLUMN_WIDTH = 15;

	// max returns the largest item in data
	//

	template <class T>

	T max(const T* data, int n) {

		T maxData = SMALLEST_NUMBER;

		for (int i = 0; i < n; i++)
		{
			if (maxData < data[i])
			{
				maxData = data[i];
			}
		}
		return maxData;
	}


	// min returns the smallest item in data
	//

	template <class T>

	T min(const T* data, int n) {

		T minData = LARGEST_NUMBER;

		for (int i = 0; i < n; i++)
		{
			if (minData > data[i])
			{
				minData = data[i];
			}
		}
		return minData;
	}


	// sum returns the sum of n items in data
	//    

	template <class T>
	T sum(const T* data, int n) {
		T sumData = 0;

		for (int i = 0; i < n; i++)
		{
			sumData += data[i];
		}
		return sumData;
	}

	// average returns the average of n items in data
	//

	template <class T>

	double average(const T* data, int n) {

		return (sum(data, n) / n);

	}

	// read extracts n items from input and stores them in data
	// - the items are comma separated
	// - this function assumes that a comma exists at the next field to be read
	// - for example: ,data1, data2,data3, ...., datan
	//

	template <class T>

	bool read(std::istream& input, T* data, int n) {
	
		for (int i = 0; i < n; i++)
		{
			input.ignore(256, ',');
			input >> data[i];
		}

		return true;
	}


	// display inserts n items of data into std::cout
	//

	template <class T>

	void display(const char* name, const T* data, int n) {
	
		std::cout.width(20);
		std::cout << std::right << name;

		for (int i = 0; i < n; i++)
		{
			std::cout.width(15);
			std::cout << data[i];
		}
		std::cout << std::endl;
	}


	bool readRow(std::istream& input, const char* name, int* data, int n);
	bool readRow(std::istream& input, const char* name, double* data, int n);
	void answers(const int*, const int*, const int*, const double*, const int*, const int n);
}

#endif // !SICT_DATA_H