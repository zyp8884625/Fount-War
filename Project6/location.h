//FileName:		location.h
//Programmer:	Bing Zhang 989108575 and YunPeng Zhang 989106123
//Date:			04/23/2013
//Purpose:		This file defines the header for the characters class
//Referece:     Project 8 is from Professor's rescours and LinkedList is also from Professor's rescours
//              Some of the codes are from the professor's lab activities

#ifndef LOCATION_H
#define LOCATION_H

#include <string>
#include <iostream>
#include "player.h"
using namespace std;

class Location
{
	protected:
		bool visited;
		char symbol;

	public:
		Location(char s = ' ') {symbol = s; visited = false;}

		void setVisited(bool v) {visited = v;}
		void setSymbol(char s) {symbol = s;}

		bool getVisited() {return visited;}
		char getSymbol() {return symbol;}

		virtual void draw() {if (visited) cout << symbol; else cout << ".";}
		virtual int visit(Player &p) {visited = true; return 1;}
};

#endif