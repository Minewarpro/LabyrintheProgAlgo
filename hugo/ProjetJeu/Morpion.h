#pragma once
#include "Personnage.h"

class Morpion : public Personnage
{
public:
	Morpion();
	Morpion(int p);


	vector<vector<int>> tabMorpion(int tabX, int tabY);
	void showMorpion(vector<vector<int>>& tab);
	void playMorpion(Personnage& p);
	int testWin(vector<vector<int>>& tab);

	friend ostream& operator<<(ostream& os, Morpion& m);
};

