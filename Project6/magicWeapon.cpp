//FileName:		magicWeapon.cpp
//Programmer:	Bing Zhang 989108575 and YunPeng Zhang 989106123
//Date:			04/23/2013
//Purpose:		This file defines the header for the characters class
//Referece:     Project 8 is from Professor's rescours and LinkedList is also from Professor's rescours
//              Some of the codes are from the professor's lab activities

#include "magicWeapon.h"
#include "player.h"
#include "character.h"

int MagicWeapon::visit(Player &p)
{
	if (taken == false)
	{
		cout << "You found a " << name << " that will allow you to roll a D" << attackModifier << " when attacking." << endl;
		visited = true;
		return 3;  //3 is for finding something
	}
	else
		return 1; //nothing happens
}

void MagicWeapon::updateCharacter(Character *u)
{
	u->setAttackDice(attackModifier);
	taken = true;
}