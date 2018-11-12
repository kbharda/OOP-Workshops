// Workshop 7 : Derived Classes
// Name: Kashyap Bharda	
// Student #: 140622176
// Course: OOP244 Fall 2018
// File: SuperHero.cpp

#include <iostream>
#include <cstring>
#include "SuperHero.h"

using namespace std;
using namespace sict;

namespace sict {

	//Default
	SuperHero::SuperHero()
	{
		//safe empty state
		this->bonusAttack = 0;
		this->bonusDefend = 0;
	}

	//Five Argument Constructor
	SuperHero::SuperHero(const char * name, int health, int strength, int bonus_attack, int bonus_defend)
	{
		if (
			(name != nullptr && name[0] != '\0' && strcmp(name, "") != 0) &&
			(health != 0) &&
			(strength != 0) &&
			(bonus_attack != 0) &&
			(bonus_defend != 0)
			)
		{
			//Assign Copy
			strncpy(this->heroName, name, MAX_NAME);
			this->heroName[MAX_NAME] = '\0';
			this->healthHero = health;
			this->strengthHero = strength;
			this->bonusAttack = bonus_attack;
			this->bonusDefend = bonus_defend;
		}
		else
		{
			//safe empty state
			this->heroName[0] = '\0';
			this->healthHero = 0;
			this->strengthHero = 0;
			this->bonusAttack = 0;
			this->bonusDefend = 0;
		}
	}

	//returns strength of hero plus bonus attack
	int SuperHero::attackStrength() const
	{
		if (Hero::attackStrength() != 0 && bonusAttack > 0)
		{
			return (Hero::attackStrength() + bonusAttack);
		}
		else
		{
			return 0;
		}

	}

	// returns defend strength
	int SuperHero::defend() const
	{
		if (this->bonusDefend != 0)
		{
			return bonusDefend;
		}
		else
		{
			return 0;
		}

	}

	const SuperHero & operator*(const SuperHero & first, const SuperHero & second)
	{
		// TODO: insert return statement here

		SuperHero left = first;
		SuperHero right = second;
		int round = 0;

		for (int i = 0; (i < MAX_ROUNDS) && left.isAlive() && right.isAlive(); i++)
		{
			left -= (right.attackStrength() - left.defend());
			right -= (left.attackStrength() - right.defend());
			round++;
		}

		cout << "Super Fight! " << first << " vs " << second << " : Winner is ";

		if (left.isAlive())
		{
			cout << first << " in " << round << " rounds." << endl;
			return first;
		}
		else if (right.isAlive())
		{
			cout << second << " in " << round << " rounds." << endl;
			return second;
		}
		else if (left.isAlive() && right.isAlive())
		{
			cout << first << " in " << round << " rounds." << endl;
		}
		return first;
	}

}