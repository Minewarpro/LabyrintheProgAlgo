#pragma once
#include "Personnage.h"
#include "Inventaire.h"
using namespace std;


class JustePrix : public Personnage , public Inventaire
{
public:
	JustePrix();
	JustePrix(int p);


	virtual void playJustePrix(Personnage& p, Inventaire& I);
	void getObjet(Inventaire& I);


	friend ostream& operator<<(ostream& os, JustePrix& m);
};
