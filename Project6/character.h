//FileName:		character.h
//Programmer:	Bing Zhang 989108575 and YunPeng Zhang 989106123
//Date:			04/23/2013
//Purpose:		This file defines the header for the characters class
//Referece:     Project 8 is from Professor's rescours and LinkedList is also from Professor's rescours
//              Some of the codes are from the professor's lab activities

#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include <stdlib.h>
using namespace std;

class Character
{
	protected: //attributes usually go here
		string name;
		int hearts;
		int MAXHEARTS;
		int attackDice;
		int defenseDice;
		char mo;

	public:  //method prototypes usually go here
		//Constructor - initializes the attributes
		// always has the same name as the class
		// no return type (not even void)
		//We are using = to specify default argument - values to use if
		//none are passed in the function call
		Character(string n = "", int h = 5, int a = 6, int d = 6, char Mo=' ') {name = n; hearts = h; MAXHEARTS = h; attackDice = a; defenseDice = d;mo=Mo;}//we make the new value "mo" that can let us know which one is healer, warrior or scout

		//We often write one set method for each attribute
		//Set methods allow objects to change the attributes
		void setName(string n) {name = n;}
		void setHearts(int h) {hearts = h;}
		void setMAXHEARTS(int h) {MAXHEARTS = h;}
		void setAttackDice(int a) {attackDice = a;}
		void setDefenseDice(int d) {defenseDice = d;}

		//We often write one get method for each attribute
		//Get methods allow objects to tell us about their attributes
		string getName() {return name;}
		int getHearts() {return hearts;}
		int getMAXHEARTS() {return MAXHEARTS;}
		int getAttackdice(){return attackDice;}
		char getMo(){return mo;}
		int getDefensedice(){return defenseDice;}
		//Functionality methods are additional actions of objects of the class
		virtual int attack() {return rand()%attackDice+1;}  //Made virtual in project 6
		virtual int defend() {return rand()%defenseDice+1;} //Made virtual in project 6
};

#endif