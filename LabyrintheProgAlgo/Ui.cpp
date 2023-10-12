#include "Ui.h"

Ui::Ui()
{
}




bool Ui::Death() {

	int n;
	int c;

	PlaySound(TEXT("Midna.wav"), NULL, SND_ASYNC);
	string line;
	ifstream myFile("died.txt");
	if (myFile.is_open())
	{
		while (getline(myFile, line))
		{
			cout << line << '\n';
		}
		myFile.close();
	}

	cout << "Appuyez sur n'importe quel touche pour finir le jeu !";


	c = _getch();
	if (c) {
		return 0;
	}

}

bool Ui::start()
{
	int n;
	int c;
	PlaySound(TEXT("sod.wav"), NULL, SND_ASYNC);
	string line;
	ifstream myFile("art.txt");
	if (myFile.is_open())
	{
		while (getline(myFile, line))
		{
			cout << line << '\n';
		}
		myFile.close();
	}

	cout << "Appuyez sur Alt + Enter pour mettre en pleine écran !" << endl << endl;
	cout << "Appuyez sur n'importe quel touche pour lancer le jeu !";


	c = _getch();
	if (c) {
		return true;
	}

	PlaySound(TEXT("sod.wav"), NULL, SND_ASYNC);

}

bool Ui::Win() {
	int n;
	int c;

	PlaySound(TEXT("VictoryTheme"), NULL, SND_ASYNC | SND_LOOP);
	string line;
	ifstream myFile("Win.txt");
	if (myFile.is_open())
	{
		while (getline(myFile, line))
		{
			cout << line << '\n';
		}
		myFile.close();
	}

	cout << "Appuyez sur n'importe quel touche pour finir le jeu !";


	c = _getch();
	if (c) {
		return true;
	}


}

int Ui::Startmenu()
{

	int choix = 0;
	string str = "Choix de la partie";
	int BeebR = 0;
	int j = 100;

	system("cls");
	cout << "       ";
	for (int i = 0; i < str.size(); i++) {
		cout << " ";
		cout << str[i];
		BeebR = (rand() % 10) + 150;
		Beep(BeebR, 300);
		Sleep(0);
	}
	cout << endl << endl;

	cout << "      1.Nouvelle partie";
	Beep(300, 100);
	Sleep(1000);
	cout << "             2.Continue";
	Beep(300, 100);
	cout << endl << endl;

	while (choix != 1 && choix != 2)
	{
		cin >> choix;
	}




	return choix;
}

int Ui::StartChoix()
{

	int choix = 0;
	string str = "Choix du mode";
	int BeebR = 0;
	int j = 100;

	system("cls");
	cout << "                                     ";
	cout << str;
	Beep(300, 100);
	cout << endl << endl;

	cout << "      1.Classique mode";
	Beep(300, 100);
	Sleep(1000);
	Beep(300, 100);
	cout << "                 2.Endless mode ";
	Sleep(1000);
	Beep(300, 100);
	cout << "                 3.Seed mode ";
	cout << endl;


	while (choix != 1 && choix != 2 && choix != 3)
	{
		cin >> choix;
	}




	return choix;
}

int Ui::DicultyChoice()
{
	int choix = 0;
	string str = "                                     Choix de la difulcuté : ";
	int BeebR = 0;
	int j = 100;

	system("cls");
	cout << str;

	cout << endl << endl;

	cout << "      1.Facile";
	Beep(300, 100);
	Sleep(1000);
	cout << "                 2.Normale ";
	Beep(300, 100);
	Sleep(1000);
	cout << "           3.Dificile";
	Beep(300, 100);
	Sleep(1000);
	Beep(300, 100);
	cout << "               4.Custom " << endl;
	cout << endl;


	while (choix != 1 && choix != 2 && choix != 3 && choix != 4)
	{
		cin >> choix;
	}




	return choix;
}

int Ui::CustomChoiceTaille()
{

	int taille = 0;
	Beep(200, 100);
	cout << "               Choix taille du labyrinthe:" << endl << endl << endl;
	cout << "Taille du carré du labyrinthe ( entre 10 et 100 ) : ";
	cin >> taille;
	cout << endl;
	while (taille <= 10 && taille >= 101) {
		cout << "Taille Invalide";
		cin >> taille;
	}

	return taille;
}

int Ui::CustomChoiceEvent()
{
	int event = 0;
	Beep(200, 100);
	cout << "               Choix nombre minijeux du labyrinthe:" << endl << endl << endl;

	cout << "Nombre de minijeux dans lelabyrinthe ( 10 de moins que la taille conseillé) : ";
	cin >> event;
	cout << endl;

	while (event <= 0) {
		cout << "Taille Invalide";
		cin >> event;
	}
	return event;
}

int Ui::CustomChoiceEtage()
{
	int etage = 0;
	Beep(200, 100);
	cout << "               Choix nombre étage du labyrinthe:" << endl << endl << endl;

	cout << "Nombre d'étage dans le labyrinthe ( 1 minimun) : ";
	cin >> etage;
	cout << endl;

	while (etage <= 0) {
		cout << "Taille Invalide";
		cin >> etage;
	}
	system("cls");
	return etage;
}

int Ui::SeedChoice()
{
	int SeedC;
	string str = "                                     Choix de la Seed : ";
	int BeebR = 0;
	int j = 100;

	system("cls");
	cout << str;

	cout << endl << endl;

	cout << "rentrer votre seed: ";
	cin >> SeedC;

	return SeedC;

}

