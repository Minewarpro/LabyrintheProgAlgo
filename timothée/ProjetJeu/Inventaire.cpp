#include "Inventaire.h"





Inventaire::Inventaire()
{
	setPlace(2);
}

Inventaire::Inventaire(int p)
{
	setPlace(p);
}

int Inventaire::getPlace()
{
	return place;
}

void Inventaire::setPlace(int p)
{
	place = p;
}

vector <int> Inventaire::tabInventaire()
{
    vector<int> tab;

 
	for (size_t i = 0; i <= getPlace(); i++)
	{
		tab.push_back(0);
	

	}
	cout << tab.size();
	Sleep(1000);

    return tab;
}

ostream& operator<<(ostream& os, Inventaire& i)
{
	os << "Vous avez " << i.getPlace() << " " << endl << endl;
	return os;
}
