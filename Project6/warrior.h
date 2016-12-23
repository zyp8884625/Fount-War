//FileName:		warrior.h
//Programmer:	Bing Zhang 989108575 and YunPeng Zhang 989106123
//Date:			04/23/2013
//Purpose:		This file defines the header for the characters class
//Referece:     Project 8 is from Professor's rescours and LinkedList is also from Professor's rescours
//              Some of the codes are from the professor's lab activities				

#ifndef WARRIOR_H
#define WARRIOR_H

#include "playerCharacter.h"
#include <string>
#include <stdlib.h>
using namespace std;

class Warrior : public PlayerCharacter
{
	private:
		int attackModifier;
		int defenseModifier;

	public:
		Warrior (string n = "warrior", int h = 6, int a = 8, int d = 6,char Mo='w') : PlayerCharacter(n,h,a,d,Mo) {attackModifier = 2; defenseModifier = 2;}

		void setAttackModifier(int a) {attackModifier = a;}
		void setDefenseModifier(int d) {defenseModifier = d;}

		int getDefenseModifier() {return defenseModifier;}
		int getAttackModifier() {return attackModifier;}

		//Functionality methods are additional actions of objects of the class
		virtual int attack() {return rand()%attackDice+attackModifier;}  
		virtual int defend() {return rand()%defenseDice+defenseModifier;} 
};

#endif