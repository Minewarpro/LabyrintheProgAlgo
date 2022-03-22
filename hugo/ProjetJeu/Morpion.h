#pragma once
#include "Personnage.h"

class Morpion : public Personnage
{
public :
	Morpion();
	Morpion(int p);

	vector<vector<int>> tab(int tabX, int tabY);
	void showMorpion(vector<vector<int>>& tab);

	friend ostream& operator<<(ostream& os, Morpion const& m);
};

