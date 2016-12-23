//FileName:		linkedList.h
//Programmer:	Bing Zhang 989108575 and YunPeng Zhang 989106123
//Date:			04/23/2013
//Purpose:		This file defines the header for the characters class
//Referece:     Project 8 is from Professor's rescours and LinkedList is also from Professor's rescours
//              Some of the codes are from the professor's lab activities

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "playerCharacter.h"
#include <string>
using namespace std;

class LinkedList
{
	private:
		PlayerCharacter *current;

	public:
		LinkedList() {current = 0;}

		void insert(PlayerCharacter *p);
		PlayerCharacter *remove(string key);
		PlayerCharacter *find(string key);
		PlayerCharacter *getCurrentElement() {return current;}
		void moveCurrentForward() {if (current != 0) current = current->getNext();}
		void removeAll();

		~LinkedList();
};

#endif