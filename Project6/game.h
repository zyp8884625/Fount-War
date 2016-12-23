//FileName:		game.h
//Programmer:	Bing Zhang 989108575 and YunPeng Zhang 989106123
//Date:			04/23/2013
//Purpose:		This file defines the header for the characters class
//Referece:     Project 8 is from Professor's rescours and LinkedList is also from Professor's rescours
//              Some of the codes are from the professor's lab activities

#ifndef GAME_H
#define GAME_H

#include "player.h"
#include "character.h"
#include "playerCharacter.h"
#include "enemy.h"
#include "location.h"
#include "item.h"
#include "MagicHouse.h"
#include "task.h"

class Game
{
	protected:
		Location ***world;
		Player p;
		Player temp;
		PlayerCharacter *current; //New for Project 6

		int rows;
		int cols;
		//int playerRow; //removed for Project 6
		//int playerCol; //removed for Project 6

	public:
		Game();

		//Required Methods
		void instructions();
		void setUpGame();
		void playGame();
		void drawGame();
		

		int battle(Character *u, Enemy *e);
		void foundItem(Character *u, Item *i);
		char getKeyPress();
		void magichouse(Character *u, MagicHouse *m);
		void task(Player &p, Task *t);
		bool healCharacter(Player &p, PlayerCharacter *healer);

		~Game();
};

#endif