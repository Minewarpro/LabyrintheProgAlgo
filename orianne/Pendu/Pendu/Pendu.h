#pragma once
#include "Personnage.h"

class Pendu : public Personnage
{
public:
	Pendu();
	Pendu(int p);


	vector<vector<int>> tabPendu(int tabX, int tabY);
	void showPendu(vector<vector<int>>& tab);
	void playPendu(Personnage& p);
	int testWin(vector<vector<int>>& tab);

	friend ostream& operator<<(ostream& os, Pendu& m);
};