#include "Remember.h"

Remember::Remember()
{
}

Remember::Remember(int p)
{
	setPoints(p);
}

void Remember::playRemember(Personnage& p, Inventaire& I)
{
	int random1 = rand() % 3000 + 5000;
	int random2 = rand() % 400 + 400;
	int random = random1 * random2;
	int secondsPreview = 5;
	int secondsMax = 10;

	for (int i = 0; i < 6; i++) {
		system("cls");
		HANDLE console;
		console = GetStdHandle(STD_OUTPUT_HANDLE);
		cout << "   Remember" << endl;
		cout << "-----------------" << endl;
		cout << "Vous aurez : " << secondsMax << " secondes pour retenir le nombre affiche" << endl;
		cout << "-----------------" << endl;
		cout << "Le jeu commence dans : " << secondsPreview << " secondes" << endl;
		cout << "-----------------" << endl;
		secondsPreview--;
		Sleep(1000);
	}

	for (int i = 0; i < 11; i++) {
		system("cls");
		HANDLE console;
		console = GetStdHandle(STD_OUTPUT_HANDLE);
		cout << "-----------------" << endl;
		cout << "Vous devez retenir : " << random << endl;
		cout << "-----------------" << endl;
		cout << "Il vous reste : " << secondsMax << " secondes" << endl;
		cout << "-----------------" << endl;
		secondsMax--;
		Sleep(1000);
	}
	int guess;
	system("cls");
	HANDLE console;
	console = GetStdHandle(STD_OUTPUT_HANDLE);
	cout << "Ecrivez votre reponse !" << endl;
	cin >> guess;
	if (guess == random) {
		cout << "Vous avez gagne !" << endl;
		getObjet(I);
	}
	else {
		cout << "Vous avez perdu !" << endl;
		attack(p);
	}
}

void Remember::getObjet(Inventaire& I)
{
	int random = rand() % 3;
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

ostream& operator<<(ostream& os, Remember& r)
{
	os << "Le Remember a " << r.getPoints() << " points d'attaque" << endl << endl;
	return os;
}
	
