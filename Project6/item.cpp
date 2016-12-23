//FileName:		item.cpp
//Programmer:	Bing Zhang 989108575 and YunPeng Zhang 989106123
//Date:			04/23/2013
//Purpose:		This file defines the header for the characters class
//Referece:     Project 8 is from Professor's rescours and LinkedList is also from Professor's rescours
//              Some of the codes are from the professor's lab activities
#include "item.h"

Item::Item (string n, char s) 
	: Location(s) 
{
	name = n; 
	taken = false;
}

void Item::draw()
{
	if (visited == true && taken == false)
		cout << symbol;
	else if (taken == true)
		cout << " ";
	else
		cout << ".";
}