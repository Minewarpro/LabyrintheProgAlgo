#include "Quizz.h"

bool verif = false;

Quizz::Quizz()
{

}

Quizz::Quizz(int p)
{
	setPoints(p);
}









void Quizz::main()
{
	int questionC = 0;
	int BeebR = 0;
	srand(time(NULL));

	questionC = (rand() % 2) + 1;



	cout << questionC;

	int vie = 3;
	int r;
	string str = "QUIZZ";

	int j = 100;
	cout << verif;

	cout << "                ";
	for (int i = 0; i < str.size(); i++) {
		cout << "  ";
		cout << str[i];
		BeebR = (rand() % 10) + 100;
		Beep(BeebR, 300);
		Sleep(350);
	}

	cout << endl;

	PlaySound(TEXT("Katana.wav"), NULL, SND_ASYNC);


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

	Sleep(10000);
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
	Sleep(1000);
	cout << "sample Text " << endl << endl;
	Sleep(5000);


	Sleep(1000);
	Beep(200, 300);
	cout << "1.?";
	Sleep(1000);
	Beep(200, 300);
	cout << "     2.? " << endl << endl;
	Sleep(1000);
	Beep(200, 300);
	cout << "3.?";
	Sleep(1000);
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
		PlaySound(TEXT("Success.wav"), NULL, SND_ASYNC);
		cout << "alors, pas vraiment...";
		verif = false;
		break;
	case 4:
		PlaySound(TEXT("Success.wav"), NULL, SND_ASYNC);
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
	Sleep(1000);
	cout << "Qu'elle est le meilleur moteur  " << endl << endl;

	Sleep(1000);
	Beep(200, 300);
	cout << "1.Atmosphir";
	Sleep(1000);
	Beep(200, 300);
	cout << "     2.Unity " << endl << endl;
	Sleep(1000);
	Beep(200, 300);
	cout << "3.Phaser3";
	Sleep(1000);
	cout << "     4.Unreal" << endl << endl;
	Beep(200, 300);

	cout << "La reponse : "; cin >> r;

	switch (r)
	{
	default:
		cout << "Fc cruz mais nan";
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
		PlaySound(TEXT("Success.wav"), NULL, SND_ASYNC);
		cout << "BG";
		verif = true;
		cout << verif;
		break;
	}
}














ostream& operator<<(ostream& os, Quizz& m)
{
	os << "Le Quizz a " << m.getPoints() << " points d'attaque" << endl << endl;
	return os;
}
