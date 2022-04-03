#include "JustePrix.h"
#include <iostream>
#include<ctime>

JustePrix::JustePrix()
{

}

JustePrix::JustePrix(int p)
{
	setPoints(p);
}

void JustePrix::playJustePrix(Personnage& p, Inventaire& I)
{
	srand(time(0));

	int random = rand() % 100;
	int guess = -1;
	int moves = 0;


	while (guess != random && moves < 10)
	{
		system("cls");
		HANDLE console;
		console = GetStdHandle(STD_OUTPUT_HANDLE);
		if (guess < random && guess != -1) {
			cout << "------------------------------" << endl;
			cout << "Votre nombre est trop petit" << endl;
			cout << "------------------------------" << endl;
			cout << endl;
		}
		else if (guess > random && guess != -1) {
			cout << "------------------------------" << endl;
			cout << "Votre nombre est trop grand" << endl;
			cout << "------------------------------" << endl;
			cout << endl;
		}
		cout << "	Le Juste Prix" << endl << "------------------------------" << endl;
		cout << "Trouvez le nombre entre 0 et 100" << endl;
		cout << "------------------------------" << endl;
		cout << "Il vous reste " << 10 - moves << " tours" << endl;
		cout << "Entrez un nombre : ";
		cin >> guess;

		moves++;
	}
	if (guess == random) {
		cout << "Vous avez gagne !" << endl;
		getObjet(I);
	}
	else {
		cout << "Vous avez perdu !" << endl;
		attack(p);
		
	}
}

void JustePrix::getObjet(Inventaire& I)
{
	int random = rand () % 2;
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

ostream& operator<<(ostream& os, JustePrix& m)
{
	os << "Le juste prix a " << m.getPoints() << " points d'attaque" << endl << endl;
	return os;
}
