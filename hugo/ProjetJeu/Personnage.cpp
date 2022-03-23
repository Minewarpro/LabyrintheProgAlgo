#include "Personnage.h"

Personnage::Personnage()
{
	setPoints(100);
}

Personnage::Personnage(int p)
{
	setPoints(p);
}

int Personnage::getPoints() const
{
	return points;
}

void Personnage::setPoints(int p)
{
	points = p;
}

void Personnage::attack(Personnage& ennemy)
{
	ennemy.setPoints(ennemy.getPoints() - getPoints());
	cout << "vous avez perdu " << getPoints() << " de vie" << endl;
}

ostream& operator<<(ostream& os, Personnage const& p)
{
	os << "Vous avez " << p.getPoints() << " points de vie" << endl << endl;
	return os;
}
