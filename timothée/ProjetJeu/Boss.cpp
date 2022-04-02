#include "Boss.h"

Boss::Boss()
{
	setPoints(200);
}

Boss::Boss(int p)
{
	setPoints(p);
}

void Boss::ShowBoss()
{

	cout << " ----Boss----" << endl;
	cout << "Le boss a : " << getPoints() << endl;
	Sleep(200);

}

ostream& operator<<(ostream& os, Boss& m)
{
	os << "Le boss a " << m.getPoints() << " points de vie" << endl << endl;
	return os;
}
