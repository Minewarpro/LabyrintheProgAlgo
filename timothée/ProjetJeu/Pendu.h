#pragma once
#include "Personnage.h"

class Pendu : public Personnage
{
public:
	Pendu();
	Pendu(int p);

	void showPendu(int essais);
	void playPendu(Personnage& p);


	friend ostream& operator<<(ostream& os, Pendu& m);
};