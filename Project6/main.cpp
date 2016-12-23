//FileName:		character.h
//Programmer:	Bing Zhang 989108575 and YunPeng Zhang 989106123
//Date:			04/23/2013
//Purpose:		This file defines the header for the characters class
//Referece:     Project 8 is from Professor's rescours and LinkedList is also from Professor's rescours
//              Some of the codes are from the professor's lab activities
/******************************************************************************************************
In this project, we add four new features. First one is skill, which are "Aimed Shot";"Steal Life";"Call Angel".
Second one is task, which can make units enter into another map to attack the GOBLIN and if the unit beat the GOBLIN
the character of unit will be increased.
Third one is magichouse. we use vector(STL) in this class. In this feature, player can choose three choices. one is transfer its 
attack to defense, another one is transfer defense to attack, final one is nothing to do.
Last one is Sounds. We use playSound function to create background sounds.
******************************************************************************************************/

#include "game.h"
#include<windows.h>
#pragma  comment(lib,"WinMM.Lib")
#include <iostream>

DWORD WINAPI Fun(LPVOID lpParamter)//This is second line (Thread), we can play music when you play game
{
     while(1)
	{
       PlaySound(TEXT("linkin park - new divide.wav"), NULL, SND_ASYNC | SND_NODEFAULT);//playSound function
	   Sleep(270000);//the music's time
	}
}

int main()
{
	//open the Thread
	HANDLE hThread = CreateThread(NULL, 0, Fun, NULL, 0, NULL);

    CloseHandle(hThread);
	//**********************************

	Game g;

	g.playGame();

	return 0;
}