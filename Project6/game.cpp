//FileName:		game.cpp
//Programmer:	Bing Zhang 989108575 and YunPeng Zhang 989106123
//Date:			04/23/2013
//Purpose:		This file defines the header for the characters class
//Referece:     Project 8 is from Professor's rescours and LinkedList is also from Professor's rescours
//              Some of the codes are from the professor's lab activities
#include "game.h"
#include "fourt.h"
#include "enemy.h"
#include "item.h"
#include "magicWeapon.h"
#include "magicShield.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <Windows.h>
#include "MagicHouse.h"
#include "skill.h"
using namespace std;

Game::Game()
{
	srand(time(0));

	world = 0;
	rows = cols = 0;
}

void Game::setUpGame()
{
	int r, c;

	rows = 8;
	cols = 8;

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

	//Now we need to place all of the elements into the world
	//First place the player's fourt
	world[0][0] = new Fourt();
	//Place the Goblin Fourt
	r = rand()%(rows-4) + 2;
	c = rand()%(cols-4) + 2;
	//cout << "Goblin Fourt at row " << r << " column " << c << endl;
	world[r][c] = new Enemy("Goblin Fourt", 25, 8, 8, 'G'); 
	//Place goblins around the base
	world[r+1][c] = new Enemy("Goblin camp", 5,  4, 4, 'g');
	world[r-1][c] = new Enemy("Goblin camp", 5,  4, 4, 'g');
	world[r][c+1] = new Enemy("Goblin camp", 5,  4, 4, 'g');
	world[r][c-1] = new Enemy("Goblin camp", 5,  4, 4, 'g');

	//Find a place for the magic sword
	do
	{
		r = rand()%rows;
		c = rand()%cols;
	} while (world[r][c] != 0);
	world[r][c] = new MagicWeapon("magic weapon", 'w', 12);

	//Find a place for the magic shield
	do
	{
		r = rand()%rows;
		c = rand()%cols;
	} while (world[r][c] != 0);
	world[r][c] = new MagicShield("magic shield", 's', 8);
	do
	{
		r = rand()%rows;
		c = rand()%cols;
	} while (world[r][c] != 0);
	world[r][c]=new MagicHouse;

		do
	{
		r = rand()%rows;
		c = rand()%cols;
	} while (world[r][c] != 0);
	world[r][c]=new Task;
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

	p.chooseUnits();  //New for project 6
}


void Game::drawGame()
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
char Game::getKeyPress()
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

void Game::playGame()
{
	int state = 1;
	char move = 'x';
	int moves;
	int tempcol=0,temprow=0;

	instructions();
	setUpGame();  //Make sure everything is set up for the first level
	current =  p.getCurrentUnit(); //set the current unit
	
	while (state > 0 && p.getUnits() > 0) //the game continues as long as state is not zero
	{
		system("cls");
		drawGame();
		moves = current->moves(); //roll the dice for the number of moves the player gets
		cout << current->getName() << " has " << moves << " move(s)." << endl;

			if (healCharacter(p, current)) moves = 0; //If this player heals an adjacent character then the turn is over
		
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
			tempcol=current->getCol();
			temprow=current->getRow();
			state = world[current->getRow()][current->getCol()]->visit(p);
	
			if (state == 2) //indicates a battle
			{
				int result = battle(current, (Enemy *)(world[current->getRow()][current->getCol()]));
				if (result == 1 && ((Enemy *)(world[current->getRow()][current->getCol()]))->getName() == "Goblin Fourt") //We defeated the enemy fourt
				{
					cout << "\nYOU WON THE GAME!" << endl;
					system("pause");
					return;
				}
				else if (result == 0)  //a unit was defeated
				{
					p.removeUnit(current->getName()); //NOTE: This both removes the unit from the list and subtracts one from the total "units" attribute
					current = p.getCurrentUnit(); //Find the "new" current since the old current was just defeated
					moves = 0; //If this was a scout we want to remove the rest of its moves
					system("pause");
				}
				else //Redraw the gameboard if the game is not over and the unit was not defeated
				{
					system("pause");
					system("cls");
					drawGame();
				}
			}
			else if (state == 3) //found an item
			{
				foundItem(current, (Item *)(world[current->getRow()][current->getCol()]));
				system("cls");
				drawGame();
			}
			else if (state ==4)// meet the magichouse
			{
				magichouse(current,(MagicHouse*)(world[current->getRow()][current->getCol()]));
				system("cls");
				drawGame();
			}
			else if (state == 5)// meet the task
			{
				temp=p;//this is temp point that can save the current unit's information
				char cho;
				cout<<"Hello, I am Johnny. There is an evil in the other world"<<endl
					<<" which you can not use all skills in."<<endl
					<<" but you can get some benifits when you kill the GOBLIN."<<endl
					<<"Do you want to accept this task?(y/n)"<<endl;
				cin>>cho;
				if(cho == 'y')
				{
					task(p,(Task*)(world[current->getRow()][current->getCol()]));
					/****************************************************************
					Updata the unit's information, because you beat the task Boss
					**************************************************************/
					cout << "Your attack, defense and Maxhearts has increased"<<endl;
					current->setAttackDice(current->getAttackdice()+2);
					current->setDefenseDice(current->getDefensedice()+2);
					current->setMAXHEARTS(current->getMAXHEARTS()+2);
					cout<<"Your current attack is: "<<current->getAttackdice()<<endl
						<<"Your current defence is: "<<current->getDefensedice()<<endl
						<<"Your current MaxHeart is: "<<current->getMAXHEARTS()<<endl;
				}
				system("cls");
				//redefine the current unit's col and row that can keep the current unit's location
				current->setCol(tempcol);
				current->setRow(temprow);
				drawGame();
			}
			moves--;
		}
		if (p.getUnits() > 0) //move to the next player if there are players left
		{
			p.moveToNextUnit();
			current = p.getCurrentUnit(); 
		}
		Sleep(1000); //pause for half a second
	}
	cout << "\nAll of your units were defeated.  You lost the game." << endl;
	system("pause");
}

bool Game::healCharacter(Player &p, PlayerCharacter *healer)
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

void Game::foundItem(Character *u, Item *i)
{
	char choice;
	cout << "Would you like to pick it up (y/n)? ";
	cin >> choice;

	if (choice == 'y')
	{
		i->updateCharacter(u);
	}
	cin.get();
}

int Game::battle(Character *u, Enemy *e)
{
	int attackerRole, defenderRole, damage,ra;
	Skill S;

	system("pause");
	while (u->getHearts() > 0 && e->getHearts() > 0) //No retreating!
	{
		system("cls");
		cout << "Your unit's health: " << u->getHearts() << "\t" << e->getName() << "'s health: " << e->getHearts() << endl;
		cout << "Press any key to role for your attack" << endl;
		ra=rand()%10;
		cin.get();
		attackerRole = u->attack();
		defenderRole = e->defend();
		cout << "Your attack role is a " << attackerRole << endl;
		cout << "The " << e->getName() << "'s defense role is a " << defenderRole << endl;
		if ((ra==S.gets(0).Roll) || (ra==S.gets(1).Roll) || (ra==S.gets(2).Roll))//choice the rando skill
		{
			
			switch (ra)
			{
			case 1://first skill
				cout<<endl<<"You cast the "<<S.gets(0).Name
					<<endl<<"Your attackrole has been doubled.";
				damage = attackerRole*2 - defenderRole;
				break;
			case 5://second skill
				cout<<endl<<"You cast the "<<S.gets(1).Name
					<<endl<<"You will be healed 1 heart by one attack.";
				if (u->getHearts()+1 <= u->getMAXHEARTS())
				{
					damage = 1;
					u->setHearts(u->getHearts()+1);
				}
				break;
			case 9://third skill
				cout<<endl<<"You cast the "<<S.gets(2).Name
					<<endl<<"You summon a Angle, and Emeny will be taken extra 3 damages";
				damage= 3;
				break;
			}
		}
		else
		{
			damage = attackerRole - defenderRole;
		}
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
	cout << "Your unit defeated the " << e->getName() << endl;
	return 1;  //The player's unit won
}

void Game::instructions()
{
	cout << "Welcome to Fourt Wars. You live in a mysterious land filled with dragons, orcs," << endl;
	cout << "and goblins. While these creatures once lived far away from your home, they " << endl;
	cout <<	"have recently established nearby fourts and have begun to raid and pillage " << endl;
	cout << "from those who you once called your friends. Your fellow villagers have decided" << endl;
	cout << "that these creatures must be stopped and have established their own fourt near" << endl;
	cout << "the boundary of your territory.  You must lead a team to explore the area past" << endl;
	cout << "this boundary, find the enemies, and destroy their fourts." << endl << endl;
	cout << "To play the game, you can use the arrow keys to move your characters.  When you" << endl;
	cout << "find goblin camps and the goblin fourt you will battle them by rolling dice." << endl;
	cout << "If you survive the battle and lose hearts (your health), you can return to your" << endl;
	cout << "fourt (indicated by the 'F' on the game board) to be healed. You must destroy " << endl;
	cout << "the Goblin Fourt to win the game.\n\nGood luck!\n" << endl;
	cout << endl;
	cout << "Also, in this game, you have skills, and you can use one of three skills when attack gbolin"<<endl;
	cout << "which are 'Aimed Shot','Steal Life','Call Angle'."<<endl;
	cout << "In this game, which has task, which can make units enter into another map to attack the GOBLIN" << endl;
	cout << "and if the unit beat the GOBLIN the character of unit will be increased." << endl;
	cout << "Also it has magichouse. player can choice three choices. one is transfer its attack to defense," << endl;
	cout << "another one is transfer defense to attack, final one is nothing to do." << endl;
	system("pause");
	system("cls");
}

void Game::magichouse(Character *u, MagicHouse *m)//call magichouse class
{
	
	m->Print(u);
	
	m->UpgradeCharacter(u);
}

void Game::task(Player &p, Task *t)//call task class
{
	t->setPlayer(p);
	t->Print();
	t->playGame();
	return ;
}

Game::~Game()
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
