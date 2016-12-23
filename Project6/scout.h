//FileName:		scout.h
//Programmer:	Bing Zhang 989108575 and YunPeng Zhang 989106123
//Date:			04/23/2013
//Purpose:		This file defines the header for the characters class
//Referece:     Project 8 is from Professor's rescours and LinkedList is also from Professor's rescours
//              Some of the codes are from the professor's lab activities				

#ifndef SCOUT_H
#define SCOUT_H

#include "playerCharacter.h"
#include <string>
#include <stdlib.h>
using namespace std;

class Scout : public PlayerCharacter
{
	public:
		Scout (string n = "scout", int h = 4, int a = 4, int d = 1,char Mo='s') : PlayerCharacter(n,h,a,d,Mo) {;}

		int moves() {return rand()%3+3;}
};

#endif