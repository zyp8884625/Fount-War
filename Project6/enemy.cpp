//FileName:		enemy.cpp
//Programmer:	Bing Zhang 989108575 and YunPeng Zhang 989106123
//Date:			04/23/2013
//Purpose:		This file defines the header for the characters class
//Referece:     Project 8 is from Professor's rescours and LinkedList is also from Professor's rescours
//              Some of the codes are from the professor's lab activities

#include "enemy.h"
#include "character.h"
#include "location.h"

Enemy::Enemy(string n, int h, int a, int d, char s) : Character(n,h,a,d), Location(s)
{
	;
}

void Enemy::draw()
{
	if (visited == false) 
		cout << ".";
	else if (visited == true && hearts <= 0)
		cout << " ";
	else
		cout << symbol;
}

int Enemy::visit(Player &p)
{
	if (hearts > 0) //There will be an enemy here as long as it has hearts
	{
		cout << "You found a " << name << endl;
		visited = true;
		return 2;  //2 indicates that a battle should be fought
	}
	else
		return 1; //nothing happens
}