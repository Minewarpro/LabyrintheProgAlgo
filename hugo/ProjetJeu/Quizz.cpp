#include "Quizz.h"

bool verif = false;

Quizz::Quizz()
{
}

Quizz::Quizz(int p)
{
	setPoints(p);
}

void Quizz::playQuizz(Personnage& p)
{
	int questionC = 0;
	int BeebR = 0;
	srand(time(NULL));

	system("cls");
	HANDLE console;
	console = GetStdHandle(STD_OUTPUT_HANDLE);

	questionC = (rand() % 2) + 1;

	int vie = 3;
	int r;
	string str = "QUIZZ";

	int j = 100;

	cout << "                ";
	for (int i = 0; i < str.size(); i++) {
		cout << "  ";
		cout << str[i];
		BeebR = (rand() % 10) + 100;
		Beep(BeebR, 300);
		Sleep(350);
	}

	cout << endl;

	switch (questionC)
	{
	default:
		cout << "Error out of range";
		break;
	case 1:
		question(verif);
		break;
	case 2:
		question2(verif);
		break;

	}

	cout << verif;

	Sleep(2000);
	system("cls");

	if (verif == true)
	{
		cout << "gg ta win";
	    
	}
	else {
		cout << "perd une vie";
		attack(p);
	}
}

void Quizz::question(bool &verif)
{

	int r;

	Sleep(100);
	cout << "                  question sample :  " << endl;
	Beep(100, 300);
	Sleep(500);
	cout << "sample Text " << endl << endl;
	Sleep(1000);


	Sleep(500);
	Beep(200, 300);
	cout << "1.?";
	Sleep(500);
	Beep(200, 300);
	cout << "     2.? " << endl << endl;
	Sleep(500);
	Beep(200, 300);
	cout << "3.?";
	Sleep(500);
	cout << "     4.?" << endl << endl;
	Beep(200, 300);

	cout << "La reponse : "; cin >> r;

	switch (r)
	{
	default:
		cout << "Choix indisponible";
		break;
	case 1:
		cout << "En vrai oui mais non";
		verif = false;
		break;
	case 2:
		cout << "Dommage";
		verif = false;
		break;
	case 3:
		cout << "alors, pas vraiment...";
		verif = false;
		break;
	case 4:
		cout << "Exact";
		verif = true;
		break;

	}
}

void Quizz::question2(bool& verif)
{
	int r;

	Sleep(100);
	cout << "                  question logique :  " << endl;
	Beep(100, 300);
	Sleep(500);
	cout << "Qu'elle est le meilleur moteur  " << endl << endl;

	Sleep(500);
	Beep(200, 300);
	cout << "1 : Atmosphir";
	Sleep(500);
	Beep(200, 300);
	cout << "     2 : Unity " << endl << endl;
	Sleep(500);
	Beep(200, 300);
	cout << "3 : Phaser3";
	Sleep(500);
	cout << "     4 : Unreal" << endl << endl;
	Beep(200, 300);

	cout << "La reponse (entrez un chiffre) : "; cin >> r;

	switch (r)
	{
	default:
		cout << "Reponse invalide";
		break;
	case 1:
		cout << "Fc cruz mais nan";
		verif = false;
		break;
	case 2:
		cout << "Unity = Unreal du bled (la meme lettre complot ?)";
		verif = false;
		break;
	case 3:
		cout << "Soon les projets de fin d'année";
		verif = false;
		break;
	case 4:
		cout << "BG";
		verif = true;
		cout << verif;
		break;
	}
}