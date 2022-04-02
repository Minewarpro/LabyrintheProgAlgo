#pragma once

#include <windows.h>
#include <iostream>
#include <time.h>
#include <vector>
#include <stdio.h>
#include <conio.h>
#include <chrono>
#include <fstream>
#include<stdlib.h>
#include<string>
#include <cstdlib>
#include<mmsystem.h>


using namespace std;

class Personnage
{
protected:
	int points;
	int x;
	int y;

public:
	//Constructeurs
	Personnage();
	Personnage(int p, int x, int y);


	// Getteurs  Setteurs
	int getPoints();
	void setPoints(int p);

	int getX();
	void setX(int x1);

	int getY();
	void setY(int y1);

	//Methods Gameplay
	void attack(Personnage& ennemy);

	

	friend ostream& operator<<(ostream& os, Personnage& p);
};

