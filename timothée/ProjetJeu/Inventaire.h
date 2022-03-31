#pragma once
#include "Personnage.h"




class Inventaire
{
protected:
	int place;
public:
	Inventaire();
	Inventaire(int p);


	int getPlace();
	void setPlace(int p);

	vector <int> tabInventaire();
	
	friend ostream& operator<<(ostream& os, Inventaire& i);
};

