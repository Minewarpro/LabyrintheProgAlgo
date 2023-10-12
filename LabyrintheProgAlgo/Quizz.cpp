#include "Quizz.h"

bool verif = false;

Quizz::Quizz()
{
}

Quizz::Quizz(int p)
{
	setPoints(p);
}

void Quizz::playQuizz(Personnage& p, Inventaire& I)
{
	int questionC = 0;
	int BeebR = 0;
	srand(time(NULL));

	system("cls");
	HANDLE console;
	console = GetStdHandle(STD_OUTPUT_HANDLE);

	questionC = (rand() % 10) + 1;

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
	case 3:
		question3(verif);
		break;
	case 4:
		question4(verif);
		break;
	case 5:
		question5(verif);
		break;
	case 6:
		question6(verif);
		break;
	case 7:
		question7(verif);
		break;
	case 8:
		question8(verif);
		break;
	case 9:
		question9(verif);
		break;
	case 10:
		question10(verif);
		break;
	}

	Sleep(2000);
	system("cls");

	if (verif == true)
	{
		cout << "gg ta win";
		getObjet(I);
	}
	else {
		cout << "perd une vie";
		attack(p);
	}
}

void Quizz::getObjet(Inventaire& I)
{
	int random = rand() % 3;
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

void Quizz::question(bool& verif)
{

	int r;

	Sleep(100);
	cout << "                  question sèrieuse :  " << endl;
	Beep(100, 300);
	Sleep(500);
	cout << "Qu'elle etre vivant fut le premier dans l'espace ?" << endl << endl;
	Sleep(1000);


	Sleep(500);
	Beep(200, 300);
	cout << "1 : un chien ?";
	Sleep(500);
	Beep(200, 300);
	cout << "     2 : un humain ? " << endl << endl;
	Sleep(500);
	Beep(200, 300);
	cout << "3 : un rat ?";
	Sleep(500);
	cout << "     4 : des poissons ?" << endl << endl;
	Beep(200, 300);

	cout << "La reponse : "; cin >> r;

	switch (r)
	{
	default:
		cout << "Choix indisponible";
		break;
	case 1:
		cout << "c'est exact !";
		verif = true;
		cout << verif;
		break;
	case 2:
		cout << "Dommage !";
		verif = false;
		break;
	case 3:
		cout << "alors, pas vraiment...";
		verif = false;
		break;
	case 4:
		cout << "ce n'est pas ça !";
		verif = false;
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

void Quizz::question3(bool& verif)
{
	int r;

	Sleep(100);
	cout << "                  question logique :  " << endl;
	Beep(100, 300);
	Sleep(500);
	cout << "Qui est le meilleur professeur de programmation de l'univers ?  " << endl << endl;

	Sleep(500);
	Beep(200, 300);
	cout << "1 : vladimir russocof";
	Sleep(500);
	Beep(200, 300);
	cout << "     2 : Jong nagata " << endl << endl;
	Sleep(500);
	Beep(200, 300);
	cout << "3 : Rémy Cham";
	Sleep(500);
	cout << "     4 : Grace Hopper" << endl << endl;
	Beep(200, 300);

	cout << "La reponse (entrez un chiffre) : "; cin >> r;

	switch (r)
	{
	default:
		cout << "Reponse invalide";
		break;
	case 1:
		cout << "n'importe quoi !";
		verif = false;
		break;
	case 2:
		cout << "Je sais meme pas ce qu'il y avait d'écrit !";
		verif = false;
		break;
	case 3:
		cout << "Oui ce mec est un dieu vivant, Bravo !";
		verif = true;
		cout << verif;
		break;
	case 4:
		cout << "il est dépacé depuis longtemps";
		verif = false;
		break;
	}

}

void Quizz::question4(bool& verif)
{
	int r;

	Sleep(100);
	cout << "                  question de culture general :  " << endl;
	Beep(100, 300);
	Sleep(500);
	cout << "Qu'elle est le seul éleve a avoir eut les felicitation au premier semestre ?  " << endl << endl;

	Sleep(500);
	Beep(200, 300);
	cout << "1 : Abadie Mathieu";
	Sleep(500);
	Beep(200, 300);
	cout << "     2 : Bruffa Mathieu " << endl << endl;
	Sleep(500);
	Beep(200, 300);
	cout << "3 : Roche Hugo";
	Sleep(500);
	cout << "     4 : Morville Naomi" << endl << endl;
	Beep(200, 300);

	cout << "La reponse (entrez un chiffre) : "; cin >> r;

	switch (r)
	{
	default:
		cout << "Reponse invalide";
		break;
	case 1:
		cout << "Pas du tout !";
		verif = false;
		break;
	case 2:
		cout << "Presque !";
		verif = false;
		break;
	case 3:
		cout << "Oui, Bravo !";
		verif = true;
		cout << verif;
		break;
	case 4:
		cout << "bah non !";
		verif = false;
		break;
	}

}

void Quizz::question5(bool& verif)
{
	int r;

	Sleep(100);
	cout << "                  question de culture general :  " << endl;
	Beep(100, 300);
	Sleep(500);
	cout << "Hawaï appartient à quel pays ?   " << endl << endl;

	Sleep(500);
	Beep(200, 300);
	cout << "1 : Mexique";
	Sleep(500);
	Beep(200, 300);
	cout << "     2 : Etats Unis" << endl << endl;
	Sleep(500);
	Beep(200, 300);
	cout << "3 : Russie";
	Sleep(500);
	cout << "     4 : Japon" << endl << endl;
	Beep(200, 300);

	cout << "La reponse (entrez un chiffre) : "; cin >> r;

	switch (r)
	{
	default:
		cout << "Reponse invalide";
		break;
	case 1:
		cout << "Pas du tout !";
		verif = false;
		break;
	case 2:
		cout << "tout a fait";
		verif = true;
		cout << verif;
		break;
	case 3:
		cout << "alors peut etre.... en fait non !";
		verif = false;
		break;
	case 4:
		cout << "pas du tout";
		verif = false;
		break;
	}

}

void Quizz::question6(bool& verif)
{
	int r;

	Sleep(100);
	cout << "                  question de culture general :  " << endl;
	Beep(100, 300);
	Sleep(500);
	cout << "Quel est le pays le plus peuplé du monde ?  " << endl << endl;

	Sleep(500);
	Beep(200, 300);
	cout << "1 : La Chine";
	Sleep(500);
	Beep(200, 300);
	cout << "     2 : Les USA " << endl << endl;
	Sleep(500);
	Beep(200, 300);
	cout << "3 : L'Inde";
	Sleep(500);
	cout << "     4 : Le Brésil" << endl << endl;
	Beep(200, 300);

	cout << "La reponse (entrez un chiffre) : "; cin >> r;

	switch (r)
	{
	default:
		cout << "Reponse invalide";
		break;
	case 1:
		cout << "Oui, Bravo !";
		verif = true;
		break;
	case 2:
		cout << "mais non !";
		verif = false;
		break;
	case 3:
		cout << "non !";
		verif = false;
		break;
	case 4:
		cout << "Presque !";
		verif = false;
		break;
	}

}

void Quizz::question7(bool& verif)
{
	int r;

	Sleep(100);
	cout << "                  question de culture general :  " << endl;
	Beep(100, 300);
	Sleep(500);
	cout << "Quel est le premier film de Disney ?  " << endl << endl;

	Sleep(500);
	Beep(200, 300);
	cout << "1 : Cendrillon";
	Sleep(500);
	Beep(200, 300);
	cout << "     2 : Blanche Neige " << endl << endl;
	Sleep(500);
	Beep(200, 300);
	cout << "3 : Le livre de la jungle";
	Sleep(500);
	cout << "     4 : La belle et la bete" << endl << endl;
	Beep(200, 300);

	cout << "La reponse (entrez un chiffre) : "; cin >> r;

	switch (r)
	{
	default:
		cout << "Reponse invalide";
		break;
	case 1:
		cout << "Naze !";
		verif = false;
		break;
	case 2:
		cout << "GG !";
		verif = true;
		break;
	case 3:
		cout << "non !";
		verif = false;
		break;
	case 4:
		cout << "nul !";
		verif = false;
		break;
	}

}

void Quizz::question8(bool& verif)
{
	int r;

	Sleep(100);
	cout << "                  question de culture general :  " << endl;
	Beep(100, 300);
	Sleep(500);
	cout << "En quelle année a eu lieu la découverte de l'Amérique ?  " << endl << endl;

	Sleep(500);
	Beep(200, 300);
	cout << "1 : 1483";
	Sleep(500);
	Beep(200, 300);
	cout << "     2 : 1488 " << endl << endl;
	Sleep(500);
	Beep(200, 300);
	cout << "3 : 1490";
	Sleep(500);
	cout << "     4 : 1492" << endl << endl;
	Beep(200, 300);

	cout << "La reponse (entrez un chiffre) : "; cin >> r;

	switch (r)
	{
	default:
		cout << "Reponse invalide";
		break;
	case 1:
		cout << "Naze !";
		verif = false;
		break;
	case 2:
		cout << "pourrit !";
		verif = false;
		break;
	case 3:
		cout << "Bidon !";
		verif = false;
		break;
	case 4:
		cout << "Insane !";
		verif = true;
		break;
	}

}

void Quizz::question9(bool& verif)
{
	int r;

	Sleep(100);
	cout << "                  question de culture general :  " << endl;
	Beep(100, 300);
	Sleep(500);
	cout << "De quel groupe est la chanson Let it be ?  " << endl << endl;

	Sleep(500);
	Beep(200, 300);
	cout << "1 : Queen";
	Sleep(500);
	Beep(200, 300);
	cout << "     2 : Nirvana" << endl << endl;
	Sleep(500);
	Beep(200, 300);
	cout << "3 : The Beatles";
	Sleep(500);
	cout << "     4 : Radiohead" << endl << endl;
	Beep(200, 300);

	cout << "La reponse (entrez un chiffre) : "; cin >> r;

	switch (r)
	{
	default:
		cout << "Reponse invalide";
		break;
	case 1:
		cout << "c'est l'enfer qui t'attend !";
		verif = false;
		break;
	case 2:
		cout << "malédiction sur toi et ta descendance !";
		verif = false;
		break;
	case 3:
		cout << "heureusement que tu connais la réponse !";
		verif = true;
		break;
	case 4:
		cout << "honte a toi !";
		verif = false;
		break;
	}

}

void Quizz::question10(bool& verif)
{
	int r;

	Sleep(100);
	cout << "                  question de culture general :  " << endl;
	Beep(100, 300);
	Sleep(500);
	cout << "Combien de ligue des champions a gagné Paris ?  " << endl << endl;

	Sleep(500);
	Beep(200, 300);
	cout << "1 : 2";
	Sleep(500);
	Beep(200, 300);
	cout << "     2 : 1" << endl << endl;
	Sleep(500);
	Beep(200, 300);
	cout << "3 : 4";
	Sleep(500);
	cout << "     4 : 0" << endl << endl;
	Beep(200, 300);

	cout << "La reponse (entrez un chiffre) : "; cin >> r;

	switch (r)
	{
	default:
		cout << "Reponse invalide";
		break;
	case 1:
		cout << "tié fada ou quoi !";
		verif = false;
		break;
	case 2:
		cout << "non mais c'est le vase qui eclate la goutte d'eau !";
		verif = false;
		break;
	case 3:
		cout << "tié un fifou dans la tete ou quoi !";
		verif = false;
		break;
	case 4:
		cout << "tié un bon !";
		verif = true;
		break;
	}

}