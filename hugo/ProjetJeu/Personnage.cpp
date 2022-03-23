#include "Personnage.h"

Personnage::Personnage()
{
	setPoints(100);
	setX(0);
	setY(0);
}

Personnage::Personnage(int p, int x, int y)
{
	setPoints(p);
	setX(x);
	setY(y);
}

int Personnage::getPoints()
{
	return points;
}

void Personnage::setPoints(int p)
{
	points = p;
}

int Personnage::getX()
{
	return x;
}

void Personnage::setX(int x1)
{
	x = x1;
}

int Personnage::getY()
{
	return y;
}

void Personnage::setY(int y1)
{
	y = y1;
}

void Personnage::attack(Personnage& ennemy)
{
	ennemy.setPoints(ennemy.getPoints() - getPoints());
	cout << "vous avez perdu " << getPoints() << " de vie" << endl;
}

ostream& operator<<(ostream& os, Personnage& p)
{
	os << "Vous avez " << p.getPoints() << " points de vie" << endl << endl;
	return os;
}
