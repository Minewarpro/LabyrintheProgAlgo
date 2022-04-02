#pragma once
#include "Personnage.h"
#include "Inventaire.h"

using namespace std;


class Remember : public Personnage
{
public:
	Remember();
	Remember(int p);


	void playRemember(Personnage& p, Inventaire& I);
	void getObjet(Inventaire& I);

	friend ostream& operator<<(ostream& os, Remember& r);
};


