#pragma once
#include "Personnage.h"
using namespace std;


class JustePrix : public Personnage
{
public: 
	JustePrix();
	JustePrix(int p);


	void playJustePrix(Personnage& p);


	friend ostream& operator<<(ostream& os, JustePrix& m);
};
