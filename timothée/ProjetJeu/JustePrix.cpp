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

void JustePrix::playJustePrix(Personnage& p)
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
	if (moves <= 10) {
		cout << "Vous avez gagne !" << endl;
	}
	else {
		cout << "Vous avez perdu !" << endl;
		attack(p);
	}
}

ostream& operator<<(ostream& os, JustePrix& m)
{
	os << "Le juste prix a " << m.getPoints() << " points d'attaque" << endl << endl;
	return os;
}
