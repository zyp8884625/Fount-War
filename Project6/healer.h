//FileName:		healer.h
//Programmer:	Bing Zhang 989108575 and YunPeng Zhang 989106123
//Date:			04/23/2013
//Purpose:		This file defines the header for the characters class
//Referece:     Project 8 is from Professor's rescours and LinkedList is also from Professor's rescours
//              Some of the codes are from the professor's lab activities

#ifndef HEALER_H
#define HEALER_H

#include "playerCharacter.h"
#include <string>
using namespace std;

class Healer : public PlayerCharacter
{
	public:
		Healer (string n = "healer", int h = 4, int a = 4, int d = 1, char Mo='h') : PlayerCharacter(n,h,a,d,Mo) {;}

		void heal(PlayerCharacter *u) {u->setHearts(u->getMAXHEARTS());}
};

#endif