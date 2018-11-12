#pragma once
// Workshop 7 : Derived Classes
// Name: Kashyap Bharda	
// Student #: 140622176
// Course: OOP244 Fall 2018
// File: Hero.h

#ifndef SICT_HERO_H
#define SICT_HERO_H

namespace sict {
	//Constants
	const int MAX_ROUNDS = 100;
	const int MAX_NAME = 41;

	class Hero
	{
		//Protected members for SuperHero
	protected:

		char heroName[MAX_NAME];
		int healthHero;
		int strengthHero;

	public:

		//public members

		Hero();

		Hero(const char*, int, int);

		~Hero();

		void operator-=(int attack);

		bool isAlive() const;

		int attackStrength() const;

		friend std::ostream& operator<<(std::ostream&, const Hero&);

	};

	const Hero& operator*(const Hero& first, const Hero& second);
}
#endif // !SICT_HERO_H
