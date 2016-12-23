//FileName:		game.h
//Programmer:	Bing Zhang 989108575 and YunPeng Zhang 989106123
//Date:			04/23/2013
//Purpose:		This file defines the header for the characters class
//Referece:     Project 8 is from Professor's rescours and LinkedList is also from Professor's rescours
//              Some of the codes are from the professor's lab activities
/*******************************************************************************************************
This class is about task, when you choose 'yes', you will enter this class. The new map 
*******************************************************************************************************/
#ifndef TASK_H
#define TASK_H

#include "player.h"
#include "character.h"
#include "playerCharacter.h"
#include "enemy.h"
#include "location.h"
#include "item.h"


class Task:public Location
{
	protected:
		Location ***world;
		Player pp;
		PlayerCharacter *current; //New for Project 6

		int rows;
		int cols;

	public:
		Task();

		//Required Methods
		void playGame();
		void drawGame();
		void Print();

		void setPlayer(Player &pl){pp=pl;}//we set the new Player in the new map that can make us show the unit int the second map
		int battle(Character *u, Enemy *e);
		char getKeyPress();
		bool healCharacter(Player &p, PlayerCharacter *healer);

		int visit(Player &p);
		~Task();
};

#endif