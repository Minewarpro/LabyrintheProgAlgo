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
	
	cout << "Appuyez sur Alt + Enter pour mettre en plein ecran !" << endl;
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
	
	cout << "Appuyez sur Alt + Enter pour mettre en plein ecran !" << endl;
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

	cout << "Appuyez sur Alt + Enter pour mettre en plein ecran !" << endl;
	cout << "Appuyez sur n'importe quel touche pour finir le jeu !";


	c = _getch();
	if (c) {
		return true;
	}


}