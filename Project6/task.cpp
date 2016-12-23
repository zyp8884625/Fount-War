//FileName:		game.cpp
//Programmer:	Bing Zhang 989108575 and YunPeng Zhang 989106123
//Date:			04/23/2013
//Purpose:		This file defines the header for the characters class
//Referece:     Project 8 is from Professor's rescours and LinkedList is also from Professor's rescours
//              Some of the codes are from the professor's lab activities
#include "task.h"
#include "fourt.h"
#include "enemy.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <Windows.h>
using namespace std;

Task::Task():Location('S')//THe symbol 'S' means you meet the task (Just like NPC in the game)
{
	srand(time(0));

	world = 0;
	rows = cols = 0;
	current=pp.getCurrentUnit();
}

void Task::Print()//setupgame
{
	int r, c;

	rows = 4;
	cols = 4;

	//Now we need to dynamically allocate world to be a 2D array of pointers to Locations
	world = new Location **[rows];
	for (r = 0; r < rows; r++)
	{
		world[r] = new Location *[cols];
	}

	//Next, go and initialize all of the pointers in the array to NULL
	for (r = 0; r < rows; r++)
	{
		for (c = 0; c < cols; c++)
		{
			world[r][c] = 0;
		}
	}
	//Now world[0][0] = new Fourt();we need to place all of the elements into the world
	//First place the player's fourt
	//Place the Goblin Fourt
	//cout << "Goblin Fourt at row " << r << " column " << c << endl;
	world[3][3] = new Enemy("Goblin Fourt",8, 5, 5, 'g'); 
	//now put blank locations everywhere else.
	for (r = 0; r < rows; r++)
	{
		for (c = 0; c < cols; c++)
		{
			if (world[r][c] == 0) //nothing at this place yet
			{
				world[r][c] = new Location();
			}
		}
	}

	world[0][0]->setVisited(true); //No action where the player begins
	//playerRow = 0;  //Not in Project 6
	//playerCol = 0;  //Not in Project 6

	//p.chooseUnits();  //New for project 6
}


void Task::drawGame()
{
	cout << current->getName() << "'s hearts: " << current->getHearts() << endl << endl;

	for (int r = 0; r < rows; r++)
	{
		for (int c = 0; c < cols; c++)
		{
			if (r == current->getRow() && c == current->getCol())
				cout << current->getName()[0];
			else
				world[r][c]->draw();
		}
		cout << endl;
	}
}

//Acknowledgment: Thanks goes to the following webpages which provided the
// info needed to read the arrow keys from the keyboard:
//	http://www.daniweb.com/software-development/cpp/threads/47195
//	http://www.codingforums.com/archive/index.php/t-100973.html
char Task::getKeyPress()
{
	char key = 127;
	key = _getch();
	
	if (key == 0 || key == -32)  //get a special key
	{
		key = _getch();

		if (key == 72) //up arrow
		{
			key = 'u';
		}
		else if (key == 75) //left arrow
		{
			key = 'l';
		}
		else if (key == 77) //right
		{
			key = 'r';
		}
		else if (key == 80) //down
		{
			key = 'd';
		}
	}
	return key;
}

void Task::playGame()
{
	int state = 1;
	char move = 'x';
	int moves;


	Print();  //Make sure everything is set up for the first level
	current =  pp.getCurrentUnit(); //set the current unit
	current ->setCol(0);
	current->setRow(0);
	while (state > 0 && pp.getUnits() > 0) //the game continues as long as state is not zero
	{
		system("cls");
		drawGame();
		moves = current->moves(); //roll the dice for the number of moves the player gets
		cout << current->getName() << " has " << moves << " move(s)." << endl;
		if (healCharacter(pp, current)) moves = 0; //If this player heals an adjacent character then the turn is over
		while (moves > 0)
		{
			do
			{
				cout << "Use the arrow keys to move " << current->getName() << endl;
				move = getKeyPress();
				cout << endl;
				if (move == 'u' && current->getRow() > 0)
				{
					current->setRow(current->getRow() - 1);
				}
				else if (move == 'd' && current->getRow() < rows-1)
				{
					current->setRow(current->getRow() + 1);
				}
				else if (move == 'l' && current->getCol() > 0)
				{
					current->setCol(current->getCol() - 1);
				}
				else if (move == 'r' && current->getCol() < cols-1)
				{
					current->setCol(current->getCol() + 1);
				}
				else
				{
					cout << "You can't do that!" << endl;
					move = 'x';
				}
			} while (move == 'x');

			system("cls");
			drawGame();
			//resolve actions involved with that move
			state = world[current->getRow()][current->getCol()]->visit(pp);
	
			if (state == 2) //indicates a battle
			{
				int result = battle(current, (Enemy *)(world[current->getRow()][current->getCol()]));
				if (result == 1 && ((Enemy *)(world[current->getRow()][current->getCol()]))->getName() == "Goblin Fourt") //We defeated the enemy fourt
				{
					system("pause");
					return ;
				}
				else if (result == 0)  //a unit was defeated
				{
					pp.removeUnit(current->getName()); //NOTE: This both removes the unit from the list and subtracts one from the total "units" attribute
					current = pp.getCurrentUnit(); //Find the "new" current since the old current was just defeated
					moves = 0; //If this was a scout we want to remove the rest of its moves
					system("pause");
					return ;
				}
				else //Redraw the gameboard if the game is not over and the unit was not defeated
				{
					system("pause");
					system("cls");
					drawGame();
					return ;
				}
			}		
			moves--;
		}
		
		Sleep(1000); //pause for half a second
	}
	cout << "\nAll of your units were defeated.  You lost the game." << endl;
	system("pause");
	return ;
}

bool Task::healCharacter(Player &p, PlayerCharacter *healer)
{
	//We need to see if any players are adjacent to, or on the same square as, the current player
	//Loop through the players and check the coordinates
	PlayerCharacter *current = p.getCurrentUnit();
	PlayerCharacter *start = p.getCurrentUnit();
	char answer;
	bool returnVal = false;
	if (current != 0) //make sure there are elements in the list
	{	
		do
		{
			if (current != healer && current->getRow() <= healer->getRow() + 1 && current->getRow() >= healer->getRow() - 1 && current->getCol() <= healer->getCol() + 1 && current->getCol() >= healer->getCol() - 1)
			{	//Found someone near the healer
				//Now find out if this character needs healing
				if (current->getHearts() < current->getMAXHEARTS()) //This character could use healing
				{
					do
					{
						cout << "Would " << healer->getName() << " like to heal " << current->getName() << "? (y/n): ";
						cin >> answer;
					} while (answer != 'y' && answer != 'n');
					if (answer == 'y')
					{
						healer->heal(current);
						returnVal = true;
					}
				}
			}
			current = current->getNext();
		} while (current != start); //end when we get back to the first person
	}
	return returnVal;
}


int Task::battle(Character *u, Enemy *e)
{
	int attackerRole, defenderRole, damage;

	system("pause");
	while (u->getHearts() > 0 && e->getHearts() > 0) //No retreating!
	{
		system("cls");
		cout << "Your unit's health: " << u->getHearts() << "\t" << e->getName() << "'s health: " << e->getHearts() << endl;
		cout << "Press any key to role for your attack" << endl;
		cin.get();
		attackerRole = u->attack();
		defenderRole = e->defend();
		cout << "Your attack role is a " << attackerRole << endl;
		cout << "The " << e->getName() << "'s defense role is a " << defenderRole << endl;
		damage = attackerRole - defenderRole;
		if (damage > 0) 
		{
			e->setHearts(e->getHearts() - damage);
			cout << "The " << e->getName() << " takes " << damage << " damage" << endl;
		}
		else
		{
			cout << "The " << e->getName() << " takes no damage" << endl;
		}

		if (e->getHearts() > 0) //Now the enemy gets a turn
		{
			cout << "\nYour unit's health: " << u->getHearts() << "\t" << e->getName() << "'s health: " << e->getHearts() << endl;
			cout << "Press any key to role for your defense" << endl;
			cin.get();
			attackerRole = e->attack();
			defenderRole = u->defend();
			cout << "The " << e->getName() << "'s attack role is a " << attackerRole << endl;
			cout << "Your unit's defense role is a " << defenderRole << endl;
			damage = attackerRole - defenderRole;
			if (damage > 0) 
			{
				u->setHearts(u->getHearts() - damage);
				cout << "Your unit takes " << damage << " damage" << endl;
			}
			else
			{
				cout << "Your unit takes no damage" << endl;
			}
		}
		system("pause");
	}
	if (u->getHearts() <= 0) 
	{
		cout << "Your unit was defeated" << endl;
		return 0; //The player's unit was defeated
	}
	Sleep(3000);
	cout << "Your unit defeated the " << e->getName() << endl;
	return 1;  //The player's unit won
}


Task::~Task()
{
	int r, c;

	if (world != 0) //delete the world if it has been made to point to something
	{
		//first delete all of the objects
		for (r = 0; r < rows; r++)
		{
			for (c = 0; c < cols; c++)
			{
				delete world[r][c];
			}
		}

		//now delete all of the columns on each row
		for (r = 0; r < rows; r++)
		{
			delete [] world[r];
		}

		//finally, we can delete the array
		delete [] world;
	}
}

int Task::visit(Player &p)
{
	setVisited(true);
	return 5;
}