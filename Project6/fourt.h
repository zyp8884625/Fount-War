//FileName:		fourt.h
//Programmer:	Bing Zhang 989108575 and YunPeng Zhang 989106123
//Date:			04/23/2013
//Purpose:		This file defines the header for the characters class
//Referece:     Project 8 is from Professor's rescours and LinkedList is also from Professor's rescours
//              Some of the codes are from the professor's lab activities

#ifndef FOURT_H
#define FOURT_H

#include "location.h"

class Fourt : public Location
{
	protected: //Attributes go here (implements "encapsulation")
		
		
	public:
		Fourt() {;}

		int visit(Player &p);
		void draw();

}; //Do NOT forget this semicolon
#endif