//FileName:		playerCharacter.h
//Programmer:	Bing Zhang 989108575 and YunPeng Zhang 989106123
//Date:			04/23/2013
//Purpose:		This file defines the header for the characters class
//Referece:     Project 8 is from Professor's rescours and LinkedList is also from Professor's rescours
//              Some of the codes are from the professor's lab activities

#ifndef PLAYERCHARACTER_H
#define PLAYERCHARACTER_H

#include "character.h"
#include <string>
#include <stdlib.h>
using namespace std;

class PlayerCharacter : public Character
{
	protected:
		int food;
		int row;
		int col;
		PlayerCharacter *next;

	public:
		PlayerCharacter(string n = "", int h = 5, int a = 6, int d = 6, char Mo=' ') : Character(n,h,a,d,Mo) {row = 0; col = 0; food = 10; next = 0;}

		void setFood(int f) {food = f;}
		void setRow(int r) {row = r;}
		void setCol(int c) {col = c;}
		void setNext(PlayerCharacter *n) {next = n;}

		int getFood() {return food;}
		int getRow() {return row;}
		int getCol() {return col;}
		PlayerCharacter *getNext() {return next;}

		virtual int moves() {return 1;}
		virtual void heal(PlayerCharacter *u) {u->setHearts(u->getHearts() + 1);  if (u->getHearts() > u->getMAXHEARTS()) u->setHearts(u->getMAXHEARTS());}
};

#endif