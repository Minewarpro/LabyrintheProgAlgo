#include "TicTac.h"
using namespace std;

TicTac::TicTac()
{
}

TicTac::TicTac(int p)
{
	setPoints(p);
}

void TicTac::getObjet(Inventaire& I)
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


void TicTac::playTictac(Personnage& p, Inventaire& I)
{

	clock_t timerInit;
	clock_t timer;
	timerInit = clock();
	int secondsPreview = 5;
	int secondsMax = 5;
	string word;
	string line;
	vector<string> lines;
	srand(time(NULL));
	

	//choisi aleatoirement une ligne du texte
	ifstream wordBank("TicTacBank.txt");
	int totalLines = 0;
	while (getline(wordBank, line))
	{
		totalLines++;
		lines.push_back(line);
	}
	int randomNumber = rand() % totalLines;
	string wordToWrite = lines[randomNumber];
	//****************
	
	for (int i = 0; i < 6; i++) {
		system("cls");
		HANDLE console;
		console = GetStdHandle(STD_OUTPUT_HANDLE);
		cout << "   TicTac" << endl;
		cout << "-----------------" << endl;
		cout << "Vous aurez : " << secondsMax << " secondes pour ecrire le mot affiche" << endl;
		cout << "-----------------" << endl;
		cout << "Le jeu commence dans : " << secondsPreview << " secondes" << endl;
		cout << "-----------------" << endl;
		secondsPreview--;
		Sleep(1000);
	}

	cout << "tu dois ecrire le mot (en minuscule): " << wordToWrite << endl;
	cin >> word;
	timer = clock() - timerInit;
	cout << "-----------------" << endl;
	cout << "Vous avez mis : " << ((double)timer / CLOCKS_PER_SEC) - 6 << " secondes a ecrire le mot" << endl << endl;


	if (word == wordToWrite && ((double)timer / CLOCKS_PER_SEC) - 6 < secondsMax) {
		cout << "-----------------" << endl;
		cout << "Vous avez gagne" << endl;
		cout << "-----------------" << endl;
		getObjet(I);
	}
	else {
		cout << "-----------------" << endl;
		cout << "vous avez perdu" << endl;
		cout << "-----------------" << endl;
		attack(p);
	}
}

ostream& operator<<(ostream& os, TicTac& tictac)
{
	os << "LeTicTac a " << tictac.getPoints() << " points d'attaque" << endl << endl;

	return os;
}