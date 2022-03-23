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
	int guess = 150;
	int moves = 0;


	while (guess != random && moves < 10)
	{
		cout << "Enter your guess : ";
		cin >> guess;
		if (guess < random) {
			cout << "Wrong guess ! You entered a lower number !" << endl;
		}
		else if (guess > random) {
				cout << "Wrong guess ! You entered a higher number !" << endl;
		}
		moves++;
	
	}
	if (moves < 10) {
		cout << "Gagné" << endl;
	}
	else {
		cout << "Perdu" << endl;
		attack(p);
	}

}

ostream& operator<<(ostream& os, JustePrix& m)
{
	os << "Le juste prix a " << m.getPoints() << " points" << endl << endl;
	return os;
}
