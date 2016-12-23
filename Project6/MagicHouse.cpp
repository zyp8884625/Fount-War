//Programmer:	Bing Zhang 989108575 and YunPeng Zhang 989106123
//Date:			04/23/2013
//Purpose:		This file defines the header for the characters class
//Referece:     Project 8 is from Professor's rescours and LinkedList is also from Professor's rescours
//              Some of the codes are from the professor's lab activities

#include "MagicHouse.h"
MagicHouse::MagicHouse():Location('M')//initial class. Symbol'M' in the map that means you meet the magichouse
{
	Str.push_back("Trans Attck to Defence");
	Str.push_back("Trans Defence to Attck");
	Str.push_back("Do Nothing");
}

void MagicHouse::Print(Character *c)//print function, showing information in the map
{
	system("cls");
	
	cout<<"Welcome to Magic House, I'm Paladin. I can help you trans your one attribute to other. Please choice which you want to trans";
	cout<<endl;
	cout<<endl<<c->getName()<<" has "<<c->getAttackdice()<<" Attack and "<<c->getDefensedice()<<" Defense."<<endl;
	vector<string>::iterator i;
	for (int i = 0; i < Str.size(); i++)
	{
		cout << "[" << i+1 << "] . " << Str[i] << endl;
	}
	
}

void MagicHouse::UpgradeCharacter(Character *c)//tansfering the character of units
{
	int choice;
	cin>>choice;
	
	switch(choice)
	{
	case 1://attack to defense
		c->setAttackDice(c->getAttackdice()-1);
		c->setDefenseDice(c->getDefensedice()+1);
		break;
	case 2://defense to attack
		c->setAttackDice(c->getAttackdice()+1);
		c->setDefenseDice(c->getDefensedice()-1);
		break;
	case 3:
		break;
	default:
		return;
	}
	cout<<endl<<"Congratulations!"<<c->getName()<<" now has "<<c->getAttackdice()<<" Attack and "<<c->getDefensedice()<<" Defense."<<endl;
	system("pause");
	return;
}

int MagicHouse::visit(Player &p)
{
	setVisited(true);
	return 4;
}