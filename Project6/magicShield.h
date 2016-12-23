//FileName:		magicShield.h
//Programmer:	Bing Zhang 989108575 and YunPeng Zhang 989106123
//Date:			04/23/2013
//Purpose:		This file defines the header for the characters class
//Referece:     Project 8 is from Professor's rescours and LinkedList is also from Professor's rescours
//              Some of the codes are from the professor's lab activities

#ifndef MAGICSHIELD_H
#define MAGICSHIELD_H

#include "item.h"
#include "player.h"
#include "character.h"

class MagicShield : public Item
{		
	private:
		int defenseModifier;

	public:
		//Constructors allow us to initialize attributes
		MagicShield(string n = "", char s = ' ', int d = 6) : Item(n,s)  {defenseModifier = d;}

		int visit(Player &p);
		void updateCharacter(Character *u);
}; //Do NOT forget this semicolon
#endif