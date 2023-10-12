#pragma once
#include "Personnage.h"
#include "Inventaire.h"


class Morpion : public Personnage
{
public:
	Morpion();
	Morpion(int p);


	vector<vector<int>> tabMorpion(int tabX, int tabY);
	void showMorpion(vector<vector<int>>& tab);
	void playMorpion(Personnage& p, Inventaire& I);
	int testWin(vector<vector<int>>& tab);
	void getObjet(Inventaire& I);

	friend ostream& operator<<(ostream& os, Morpion& m);
};

