#include "Inventaire.h"


Inventaire::Inventaire()
{
	setPlace(2);
	setNbBombe(0);
	setNbPotion(0);
}

Inventaire::Inventaire(int p, int po, int b)
{
	setPlace(p);
	setNbBombe(po);
	setNbPotion(b);
}

int Inventaire::getPlace()
{
	return place;
}

void Inventaire::setPlace(int p)
{
	place = p;
}

int Inventaire::getNbPotion()
{
	return nbPotion;
}

void Inventaire::setNbPotion(int nbP)
{
	nbPotion = nbP;
}

int Inventaire::getNbBombe()
{
	return nbBombe;
}

void Inventaire::setNbBombe(int nbB)
{
	nbBombe = nbB;
}

void Inventaire::potion(int pv, Personnage& p)
{
	cout << "Vous utilisez une potion, vous avez récupéré " << pv << "points de vie" << endl;
	p.setPoints(p.getPoints() + pv);
	if (p.getPoints() > 100) {
		p.setPoints(100);
	} 
	setNbPotion(getNbPotion() - 1);
}

void Inventaire::bombe(vector<vector<int>>& tab, Personnage& p) {

	if (tab[p.getY() - 1][p.getX()] == 1) {
		tab[p.getY() - 1][p.getX()] = 0;
	}
	if (tab[p.getY() + 1][p.getX()] == 1) {
		tab[p.getY() + 1][p.getX()] = 0;
	}
	if (tab[p.getY()][p.getX() - 1] == 1) {
		tab[p.getY()][p.getX() - 1] = 0;
	}
	if (tab[p.getY()][p.getX() + 1] == 1) {
		tab[p.getY()][p.getX() + 1] = 0;
	}
	setNbBombe(getNbBombe() - 1);
}

void Inventaire::showInventaire()
{
	
	vector <int> tab = tabInventaire();

	cout << "----------------" << endl;
	cout << "   Inventaire" << endl;
	cout << "----------------" << endl;
	for (int i = 0; i < tab.size(); i++) {
		switch (tab[i])
		{
		case 0:
			cout << "|Vide|" << endl;
			break;
		case 1:
			cout << "|Potion|" << endl;
			break;
		case 2:
			cout << "|Bombe|" << endl;
			break;
		default:
			break;
		}
	}
	cout << endl;
	cout << "Appuyez sur 'A' pour utiliser une potion" << endl;
	cout << "Appuyez sur 'B' pour utiliser une bombe" << endl;
}

vector <int> Inventaire::tabInventaire()
{
	vector<int> tab;

	for (size_t i = 0; i < getNbPotion(); i++)
	{
		tab.push_back(1);

	}
	for (size_t i = 0; i < getNbBombe(); i++)
	{
		tab.push_back(2);

	}
	for (size_t i = 0; i <  getPlace() - getNbPotion() - getNbBombe(); i++)
	{
		tab.push_back(0);
	}

	return tab;
}

ostream& operator<<(ostream& os, Inventaire& i)
{
	os << "Vous avez " << i.getPlace() << " " << endl << endl;
	return os;
}
