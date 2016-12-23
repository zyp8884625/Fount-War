//Programmer:	Bing Zhang 989108575 and YunPeng Zhang 989106123
//Date:			04/23/2013
//Purpose:		This file defines the header for the characters class
//Referece:     Project 8 is from Professor's rescours and LinkedList is also from Professor's rescours
//              Some of the codes are from the professor's lab activities

#ifndef SKILL_H
#define SKILL_H

#include <iostream>
#include <string>
using namespace std;

struct s//structure function
{
	string Name;
	int Roll;
	int No;
};

class Skill
{
private:
	s skill[3];
public:
	Skill();
	string getname(s S){return S.Name;}
	int getroll(s S){return S.Roll;}
	int getNo(s S){return S.No;}
	s gets(int i){return skill[i];}
};
#endif