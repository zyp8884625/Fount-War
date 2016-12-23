//FileName:		fourt.cpp
//Programmer:	Bing Zhang 989108575 and YunPeng Zhang 989106123
//Date:			04/23/2013
//Purpose:		This file defines the header for the characters class
//Referece:     Project 8 is from Professor's rescours and LinkedList is also from Professor's rescours
//              Some of the codes are from the professor's lab activities

#include "fourt.h"
#include "player.h"

void Fourt::draw()
{
	if (visited == false)
		cout << ".";
	else
		cout << "F";
}

int Fourt::visit(Player &p)
{
	if (p.getCurrentUnit()->getHearts() < p.getCurrentUnit()->getMAXHEARTS())
	{
		cout << p.getCurrentUnit()->getName() << " entered your Fourt and received healing." << endl;  system("pause");
		p.getCurrentUnit()->setHearts(p.getCurrentUnit()->getMAXHEARTS());
	}
	visited = true;
	return 10;  //10 is for a fourt
}