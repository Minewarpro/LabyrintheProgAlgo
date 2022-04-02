#pragma once
#include "Personnage.h"




class Inventaire 
{
protected:
	int place;
	int nbPotion;
	int nbBombe;
public:
	Inventaire();
	Inventaire(int p, int po, int b);


	int getPlace();
	void setPlace(int p);

	int getNbPotion();
	void setNbPotion(int nbP);

	int getNbBombe();
	void setNbBombe(int nbB);

	void potion(int pv, Personnage& p);

	void bombe(vector<vector<int>>& tab, Personnage& p);

	void showInventaire();

	vector <int> tabInventaire();

	friend ostream& operator<<(ostream& os, Inventaire& i);
};

