#include "Shifumi.h"

Shifumi::Shifumi()
{
}

Shifumi::Shifumi(int p)
{
	setPoints(p);
}

void Shifumi::getObjet(Inventaire& I)
{
	int random = rand() % 2;
	int randomObject = rand() % 2;

	if (random == 1) {
		if (I.getNbBombe() + I.getNbPotion() < I.getPlace())
		{
			switch (randomObject)
			{
			case 0:
				I.setNbPotion(I.getNbPotion() + 1);
				break;
			case 1:
				I.setNbBombe(I.getNbBombe() + 1);
				break;
			}
		}
	}
}

void Shifumi::playShifumi(Personnage& p, Inventaire& I)
{

	int choix;
	int bot;
	bool win = false;
	bool loose = false;

	srand(time(NULL));

	system("cls");
	while (win != true && loose != true)
	{
		cout << "Quelle est votre choix ?" << endl;

		cout << "1 pour Pierre		2 pour Feuille		3 pour Ciseaux" << endl;

		cin >> choix;

		bot = rand() % 3 + 1;

		switch (bot)
		{
		case 1:
			cout << "Moi j'ai choisit Pierre" << endl;

			switch (choix)
			{
			case 1: // pierre
				cout << "Egalite on recomence" << endl;
				break;
			case 2: //feuille
				cout << "J'ai perdu MERDE" << endl;
				win = true;
				break;
			case 3: //ciseaux
				cout << "J'ai donc gagne CHEH" << endl;
				loose = true;
				break;
			default:// au cas ou
				cout << "Tu as donc pas compris le principe HEIN ?" << endl;
			}
			break;
		case 2:
			cout << "Moi j'ai choisit Feuille" << endl;

			switch (choix)
			{
			case 1:// pierre
				cout << "J'ai donc gagne CHEH" << endl;
				loose = true;
				break;
			case 2://feuille
				cout << "Egalite on recomence" << endl;
				break;
			case 3://ciseaux
				cout << "J'ai perdu MERDE" << endl;
				win = true;
				break;
			default:
				cout << "Tu as donc pas compris le principe HEIN ?" << endl;
			}
			break;
		default:// au cas ou
			cout << "Moi j'ai choisit Ciseaux" << endl;

			switch (choix)
			{
			case 1:// pierre
				cout << "J'ai perdu MERDE" << endl;
				win = true;
				break;
			case 2://feuille
				cout << "J'ai donc gagne CHEH" << endl;
				loose = true;
				break;
			case 3://ciseaux
				cout << "Egalite on recomence" << endl;
				break;
			default:// au cas ou
				cout << "Tu as donc pas compris le principe HEIN ?" << endl;
			}
		}

		if (win == true) {
			cout << "------------------" << endl;
			cout << "Vous avez gagne GG" << endl;
			cout << "------------------" << endl;
			getObjet(I);
		}
		else {
			cout << "-----------------" << endl;
			cout << "vous avez perdu" << endl;
			cout << "-----------------" << endl;
			cout << "bouh t'es null" << endl;
			cout << "-----------------" << endl;
			attack(p);
		}
	}
}

ostream& operator<<(ostream& os, Shifumi& sfm)
{
	os << "LeTicTac a " << sfm.getPoints() << " points d'attaque" << endl << endl;

	return os;
}
