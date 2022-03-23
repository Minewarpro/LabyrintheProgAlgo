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

	int random = rand() % 100 + 20;
	int guess = 0;
	int moves = 0;



	while (guess != random);
	{
		moves++;
		cout << "Enter your guess : ";
		cin >> guess;
		if (guess = random) {
			cout << "Congrats ! Right guess after" << moves << "moves" << endl;
		}
		else if (guess << random) {
			cout << "Wrong guess ! You entered a lower number !" << endl;
		}
		else  {
			cout << "Wrong guess ! You entered a higher number !" << endl;
		}
	}
}

ostream& operator<<(ostream& os, JustePrix& m)
{
	os << "Le juste prix a " << m.getPoints() << " points" << endl << endl;
}
