// Workshop 7 : Derived Classes
// Name: Kashyap Bharda	
// Student #: 140622176
// Course: OOP244 Fall 2018
// File: Hero.cpp

#include <iostream>
#include <cstring>
#include "Hero.h"

using namespace std;
using namespace sict;

namespace sict {

	//Default constructor
	Hero::Hero()
	{
		//safe empty state
		this->heroName[0] = '\0';
		this->healthHero = 0;
		this->strengthHero = 0;
	}

	//3 argument constructor
	Hero::Hero(const char* name, int health, int strength)
	{
		if (
			(name != nullptr && name[0] != '\0' && strcmp(name, "") != 0) &&
			(health != 0) &&
			(strength != 0)
			) {
			strncpy(this->heroName, name, MAX_NAME);
			this->heroName[MAX_NAME] = '\0';
			this->healthHero = health;
			this->strengthHero = strength;
		}
		else {
			//safe empty state
			*this = Hero();
		}
	}

	// Destructor
	Hero::~Hero()
	{
		this->heroName[0] = '\0';
		this->healthHero = 0;
		this->strengthHero = 0;
	}

	//overload -= operator
	void Hero::operator-=(int attack)
	{
		if (attack >= 0)
		{
			if (this->healthHero > attack)
			{
				this->healthHero -= attack;
			}
			else
			{
				this->healthHero = 0;
			}
		}
	}

	//checks if healthof hero
	bool Hero::isAlive() const
	{
		if (this->healthHero > 0)
		{
			return true;
		}
		return false;
	}

	// attackStrength returns strength of hero
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

	// Overload << operator
	std::ostream & operator<<(std::ostream & os, const Hero & hero)
	{
		if (
			(hero.heroName != nullptr && hero.heroName[0] != '\0' && strcmp(hero.heroName, "") != 0) &&
			(hero.healthHero != 0) &&
			(hero.strengthHero != 0)
			) {
			os << hero.heroName;
		}
		else {
			os << "No hero";
		}

		return os;
	}

	// overload * operator
	const Hero & operator*(const Hero & first, const Hero & second)
	{
		Hero left = first;
		Hero right = second;
		int round = 0;

		for (int i = 0; (i < MAX_ROUNDS) && left.isAlive() && right.isAlive(); i++)
		{
			left -= (right.attackStrength());
			right -= (left.attackStrength());
			round++;
		}

		cout << "Ancient Battle! " << first << " vs " << second << " : Winner is ";

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