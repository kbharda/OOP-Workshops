// Workshop 7 : Derived Classes
// Name: Kashyap Bharda	
// Student #: 140622176
// Course: OOP244 Fall 2018
// File: Hero.cpp

#include <iostream>
#include <cstring>
#include "Hero.h"

using namespace std;

namespace sict {
	
	void Hero::operator-=(int attack)
	{
		if (attack >= 0 )
		{
			if (healthHero > attack)
			{
				healthHero -= attack;
			}
			else
			{
				healthHero = 0;
			}
		}
	}

	bool Hero::isAlive() const
	{
		if (this->healthHero > 0)
		{
			return true;
		}
		return false;
	}

	int Hero::attackStrength() const
	{
		if (this->strengthHero > 0)
		{
			return strengthHero;
		}
		else
		{
			return 0;
		}

	}

	ostream & operator<<(ostream & os, const Hero & hero)
	{
		// TODO: insert return statement here
		if (!(hero.heroName == NULL || hero.heroName[0] == '\0' || strcmp(hero.heroName, "") == 0
			|| hero.healthHero < 0
			|| hero.strengthHero < 0))
		{
			os << hero.heroName;
		}
		else
		{
			os << "No hero";
		}
	}
	const Hero & operator*(const Hero & first, const Hero & second)
	{
		// TODO: insert return statement here


	}
}