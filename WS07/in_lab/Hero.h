#pragma once

// Workshop 7 : Derived Classes
// Name: Kashyap Bharda	
// Student #: 140622176
// Course: OOP244 Fall 2018
// File: Hero.h


#ifndef SICT_HERO_H
#define SICT_HERO_H

namespace sict {

	const int MAX_ROUNDS = 100;
	const int MAX_NAME = 41;

	class Hero
	{

		char heroName[MAX_NAME];
		int healthHero;
		int strengthHero;

	public:

		void operator-=(int attack);
		
		bool isAlive() const;

		int attackStrength() const;

		friend 	ostream& operator<<(ostream& os, const Hero& hero);
	};

	const Hero& operator*(const Hero& first, const Hero& second);
}
#endif // !SICT_HERO_H
