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

	}
	else {
		cout << "perd une vie";
		attack(p);
	}
}

void Quizz::question(bool& verif)
{

	int r;

	Sleep(100);
	cout << "                  Question sérieuse :  " << endl;
	Beep(100, 300);
	Sleep(500);
	cout << "Qu'elle être vivant fut le premier dans l'espace ?" << endl << endl;
	Sleep(1000);


	Sleep(500);
	Beep(200, 300);
	cout << "1 : Un chien ?";
	Sleep(500);
	Beep(200, 300);
	cout << "     2 : Un humain ? " << endl << endl;
	Sleep(500);
	Beep(200, 300);
	cout << "3 : Un rat ?";
	Sleep(500);
	cout << "     4 : Des poissons ?" << endl << endl;
	Beep(200, 300);

	cout << "La réponse : "; cin >> r;

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
	cout << "                  Question logique :  " << endl;
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

		break;
	}

}

void Quizz::question3(bool& verif)
{
	int r;

	Sleep(100);
	cout << "                  Question logique :  " << endl;
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

	cout << "La reponse (entrer un chiffre) : "; cin >> r;

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
		cout << "Je sais meme pas ce qu'il y avait d'ecrit !";
		verif = false;
		break;
	case 3:
		cout << "Oui ce mec est un dieu vivant, Bravo !";
		verif = true;
		break;
	case 4:
		cout << "Une legende mais non";
		verif = false;
		break;
	}

}

void Quizz::question4(bool& verif)
{
	int r;

	Sleep(100);
	cout << "                  Question d'avis personelle :  " << endl;
	Beep(100, 300);
	Sleep(500);
	cout << "En voyant notre jeux ?  " << endl << endl;

	Sleep(500);
	Beep(200, 300);
	cout << "1 : on est Artiste";
	Sleep(500);
	Beep(200, 300);
	cout << "     2 : On des programeurs " << endl << endl;
	Sleep(500);
	Beep(200, 300);
	cout << "3 : Ni l'un ni l'autre";
	Sleep(500);
	cout << "     4 : Des allant trop loin pour une simple note" << endl << endl;
	Beep(200, 300);

	cout << "La réponse (entrer un chiffre) : "; cin >> r;

	switch (r)
	{
	default:
		cout << "Réponse invalide";
		break;
	case 1:
		cout << "MDR t'est aveugle";
		verif = false;
		break;
	case 2:
		cout << "Et Merci stackoverflow";
		verif = true;
		break;
	case 3:
		cout << "OOF";
		verif = false;
		break;
	case 4:
		cout << " Aussi mais je suis vexé de cette réponse donc non";
		verif = false;
		break;
	}

}

void Quizz::question5(bool& verif)
{
	int r;

	Sleep(100);
	cout << "                  Question de culture général :  " << endl;
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

	cout << "La réponse (entrez un chiffre) : "; cin >> r;

	switch (r)
	{
	default:
		cout << "Réponse invalide";
		break;
	case 1:
		cout << "Pas du tout !";
		verif = false;
		break;
	case 2:
		cout << "Tout à fait";
		verif = true;
		break;
	case 3:
		cout << "Alors peut etre...."; Sleep(100); cout << " mais non !";
		verif = false;
		break;
	case 4:
		cout << "Pas du tout";
		verif = false;
		break;
	}

}

void Quizz::question6(bool& verif)
{
	int r;

	Sleep(100);
	cout << "                  Question de culture général :  " << endl;
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
		cout << "Mais non !";
		verif = false;
		break;
	case 3:
		cout << "Non !";
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
	cout << "                  Question de culture général :  " << endl;
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
	cout << "     4 : La belle et la bête" << endl << endl;
	Beep(200, 300);

	cout << "La réponse (entrer un chiffre) : "; cin >> r;

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
		cout << "Non !";
		verif = false;
		break;
	case 4:
		cout << "Nul !";
		verif = false;
		break;
	}

}

void Quizz::question8(bool& verif)
{
	int r;

	Sleep(100);
	cout << "                  Question de culture général :  " << endl;
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
		cout << "Pourrit !";
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
	cout << "                  Question de culture général :  " << endl;
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
		cout << "Réponse invalide";
		break;
	case 1:
		cout << "C'est l'enfer qui t'attend !";
		verif = false;
		break;
	case 2:
		cout << "Malédiction sur toi et ta descendance !";
		verif = false;
		break;
	case 3:
		cout << "Heureusement que tu connais la réponse !";
		verif = true;
		break;
	case 4:
		cout << "Honte a toi !";
		verif = false;
		break;
	}

}

void Quizz::question10(bool& verif)
{
	int r;

	Sleep(100);
	cout << "                  Question de culture géneral :  " << endl;
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
		cout << "Réponse invalide";
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