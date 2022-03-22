#pragma once
#include <iostream>
#include <windows.h>
#include <time.h>
#include <vector>
#include <stdio.h>
#include <conio.h>

using namespace std;

class Personnage
{
protected:
	int points;
	
public:
	//Constructeurs
	Personnage();
	Personnage(int p);

	// Getteurs  Setteurs
	int getPoints() const;
	void setPoints(int p);

	//Methods Gameplay
	void attack(Personnage& ennemy);

	friend ostream& operator<<(ostream& os, Personnage const& p);
};

