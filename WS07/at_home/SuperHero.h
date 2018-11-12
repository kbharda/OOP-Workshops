#pragma once
// Workshop 7 : Derived Classes
// Name: Kashyap Bharda	
// Student #: 140622176
// Course: OOP244 Fall 2018
// File: SuperHero.h

#ifndef SICT_SUPERHERO_H
#define SICT_SUPERHERO_H
#include "Hero.h"

namespace sict {

	class SuperHero : public Hero {

		//Private data Members
		int bonusAttack;
		int bonusDefend;

	public:

		//public members
		SuperHero();
		SuperHero(const char*, int, int, int, int);

		int attackStrength() const;

		int defend() const;

	};

	const SuperHero& operator*(const SuperHero& first, const SuperHero & second);
}

#endif // !SICT_SUPERHERO_H
