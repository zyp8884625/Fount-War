//FileName:		enemy.h
//Programmer:	Bing Zhang 989108575 and YunPeng Zhang 989106123
//Date:			04/23/2013
//Purpose:		This file defines the header for the characters class
//Referece:     Project 8 is from Professor's rescours and LinkedList is also from Professor's rescours
//              Some of the codes are from the professor's lab activities

#ifndef ENEMY_H
#define ENEMY_H

#include "character.h"
#include "location.h"

class Enemy : public Location, public Character
{		
	public:
		//Constructors allow us to initialize attributes
		Enemy(string n = "", int h = 5, int a = 6, int d = 6, char s = ' ');
		
		//Functionality methods give additional actions to object
		void draw();
		int visit(Player &p);
}; //Do NOT forget this semicolon
#endif