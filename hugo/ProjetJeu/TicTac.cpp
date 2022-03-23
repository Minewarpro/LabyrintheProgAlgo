#include "TicTac.h"

TicTac::TicTac()
{
}

TicTac::TicTac(int p)
{
	setPoints(p);
}


void TicTac::playTictac(Personnage& p)
{
	int seconds = 10;
	string mot;
	for (int i = 0; i < 10; i++) {
		system("cls");
		HANDLE console;
		console = GetStdHandle(STD_OUTPUT_HANDLE);
		cout << "Il vous reste : " << seconds << " secondes" << endl;
		seconds--;
		Sleep(1000);
	}

}

ostream& operator<<(ostream& os, TicTac& tictac)
{
	os << "LeTicTac a " << tictac.getPoints() << " points" << endl << endl;

	return os;
}