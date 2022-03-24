#pragma once
#include "Personnage.h"#pragma once
#include "Personnage.h"
using namespace std;


class Remember : public Personnage
{
public:
	Remember();
	Remember(int p);


	void playRemember(Personnage& p);


	friend ostream& operator<<(ostream& os, Remember& r);
};


