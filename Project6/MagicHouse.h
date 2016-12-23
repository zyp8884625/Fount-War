//Programmer:	Bing Zhang 989108575 and YunPeng Zhang 989106123
//Date:			04/23/2013
//Purpose:		This file defines the header for the characters class
//Referece:     Project 8 is from Professor's rescours and LinkedList is also from Professor's rescours
//              Some of the codes are from the professor's lab activities

#ifndef MAGICHOUSE_H
#define MAGICHOUSE_H
#include <string>
#include <iostream>
#include <vector>
#include "location.h"
#include "character.h"
using namespace std;

class MagicHouse:public Location
{
private:
	vector<string> Str;//vector(STL)
public:
	MagicHouse();
	void UpgradeCharacter(Character *c);
	void Print(Character *c);
	int visit(Player &p);
};

#endif