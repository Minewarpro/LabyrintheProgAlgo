#pragma once
#include "Personnage.h"
#include "Inventaire.h"

class Pendu : public Personnage
{
public:
	Pendu();
	Pendu(int p);

	void showPendu(int essais);
	void playPendu(Personnage& p, Inventaire& I);
	void getObjet(Inventaire& I);

	friend ostream& operator<<(ostream& os, Pendu& m);
};