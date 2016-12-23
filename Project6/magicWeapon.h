//FileName:		magicWeapon.h
//Programmer:	Bing Zhang 989108575 and YunPeng Zhang 989106123
//Date:			04/23/2013
//Purpose:		This file defines the header for the characters class
//Referece:     Project 8 is from Professor's rescours and LinkedList is also from Professor's rescours
//              Some of the codes are from the professor's lab activities

#ifndef MAGICWEAPON_H
#define MAGICWEAPON_H

#include "item.h"
#include "player.h"
#include "character.h"

class MagicWeapon : public Item
{		
	private:
		int attackModifier;

	public:
		//Constructors allow us to initialize attributes
		MagicWeapon(string n = "", char s = ' ', int a = 6) : Item(n,s)  {attackModifier = a;}

		int visit(Player &p);
		void updateCharacter(Character *u);
}; //Do NOT forget this semicolon
#endif