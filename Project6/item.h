//FileName:		item.h
//Programmer:	Bing Zhang 989108575 and YunPeng Zhang 989106123
//Date:			04/23/2013
//Purpose:		This file defines the header for the characters class
//Referece:     Project 8 is from Professor's rescours and LinkedList is also from Professor's rescours
//              Some of the codes are from the professor's lab activities

#ifndef ITEM_H
#define ITEM_H

#include "location.h"
#include "player.h"
#include "character.h"

class Item : public Location
{		
	protected:
		string name;
		bool taken;

	public:
		Item(string n = "", char s = ' ');

		void setName(string n) {name = n;}
		void setTaken(bool t) {taken = t;}

		string getName() {return name;}
		bool getTaken() {return taken;}

		virtual void draw();
		virtual int visit(Player &p)=0;
		virtual void updateCharacter(Character *u) = 0;
};
#endif