#include "Morpion.h"


void Morpion::getObjet(Inventaire& I)
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

Morpion::Morpion()
{
}

Morpion::Morpion(int p)
{
    setPoints(p);
}

vector<vector<int>> Morpion::tabMorpion(int tabX, int tabY)
{
    vector<vector<int>> tab;


    for (int i = 0; i < tabY; i++) {
        tab.push_back(vector<int>(tabX));
        for (int j = 0; j < tabX; j++) {
            tab[i][j] = 0;
        }
    }
    return tab;
}

void Morpion::showMorpion(vector<vector<int>>& tab)
{
    system("cls");
    HANDLE console;
    console = GetStdHandle(STD_OUTPUT_HANDLE);
    for (int i = 0; i < tab.size(); i++) {
        for (int j = 0; j < tab[i].size(); j++) {
            switch (tab[i][j])
            {
            case 0:
                cout << "| |";
                break;
            case 1:
                cout << "|X|";
                break;
            case 2:
                cout << "|O|";
                break;
            default:
                cout << "| |";
                break;
            }
        }
        cout << endl;
    }
}

int Morpion::testWin(vector<vector<int>>& tab)
{

    if (tab[0][0] == 1 && tab[0][1] == 1 && tab[0][2] == 1) {
        return 1;
    }
    else if (tab[1][0] == 1 && tab[1][1] == 1 && tab[1][2] == 1) {
        return 1;
    }
    else if (tab[2][0] == 1 && tab[2][1] == 1 && tab[2][2] == 1) {
        return 1;
    }
    else if (tab[0][0] == 1 && tab[1][0] == 1 && tab[2][0] == 1) {
        return 1;
    }
    else if (tab[0][1] == 1 && tab[1][1] == 1 && tab[2][1] == 1) {
        return 1;
    }
    else if (tab[0][2] == 1 && tab[1][2] == 1 && tab[2][2] == 1) {
        return 1;
    }
    else if (tab[0][0] == 1 && tab[1][1] == 1 && tab[2][2] == 1) {
        return 1;
    }
    else if (tab[0][2] == 1 && tab[1][1] == 1 && tab[2][0] == 1) {
        return 1;
    }


    else if (tab[0][0] == 2 && tab[0][1] == 2 && tab[0][2] == 2) {
        return 2;
    }
    else if (tab[1][0] == 2 && tab[1][1] == 2 && tab[1][2] == 2) {
        return 2;
    }
    else if (tab[2][0] == 2 && tab[2][1] == 2 && tab[2][2] == 2) {
        return 2;
    }
    else if (tab[0][0] == 2 && tab[1][0] == 2 && tab[2][0] == 2) {
        return 2;
    }
    else if (tab[0][1] == 2 && tab[1][1] == 2 && tab[2][1] == 2) {
        return 2;
    }
    else if (tab[0][2] == 2 && tab[1][2] == 2 && tab[2][2] == 2) {
        return 2;
    }
    else if (tab[0][0] == 2 && tab[1][1] == 2 && tab[2][2] == 2) {
        return 2;
    }
    else if (tab[0][2] == 2 && tab[1][1] == 2 && tab[2][0] == 2) {
        return 2;
    }

    else {
        return 0;
    }
}

void Morpion::playMorpion(Personnage& p, Inventaire& I)
{
    vector<vector<int>> tab = tabMorpion(3, 3);
    int ligne, colonne;
    int tourRestant = 9;
    showMorpion(tab);

    while (testWin(tab) == 0 && tourRestant != 0) {
        int juste = false;
        
        cout << "Quelle ligne ?" << endl;
        cin >> ligne;
        cout << "Quelle colonne ?" << endl;
        cin >> colonne;

        while (ligne < 1 || ligne>3 || colonne < 1 || colonne>3) {
            cout << "Saisie eronnee" << endl;
            cout << "Quelle ligne ?" << endl;
            cin >> ligne;
            cout << "Quelle colonne ?" << endl;
            cin >> colonne;
        }
        while (tab[ligne - 1][colonne - 1] != 0) {

            showMorpion(tab);
            cout << "Vous ne pouvez pas poser un pion sur une case deja utilise" << endl;
            cout << "Quelle ligne ?" << endl;
            cin >> ligne;
            cout << "Quelle colonne ?" << endl;
            cin >> colonne;
            while (ligne < 1 || ligne>3 || colonne < 1 || colonne>3) {
                showMorpion(tab);
                cout << "Saisie eronnee" << endl;
                cout << "Quelle ligne ?" << endl;
                cin >> ligne;
                cout << "Quelle colonne ?" << endl;
                cin >> colonne;
            }
        }

        tab[ligne - 1][colonne - 1] = 1;
        showMorpion(tab);
        testWin(tab);
        tourRestant -= 1;

        if (tourRestant != 0) {
            int randY = rand() % 3;
            int randX = rand() % 3;
            tab[randY][randX];
            while (tab[randY][randX] != 0) {
                randY = rand() % 3;
                randX = rand() % 3;
            }
            tab[randY][randX] = 2;
            showMorpion(tab);
            testWin(tab);
            tourRestant -= 1;
        }
    }
    if (testWin(tab) == 1) {
        cout << "Vous avez gagne" << endl;
        getObjet(I);
    }
    else {
        cout << "Vous avez Perdu" << endl;
        attack(p);
    }
}



ostream& operator<<(ostream& os, Morpion& m)
{
    os << "Le Morpion a " << m.getPoints() << " points d'attaque" << endl << endl;

    return os;
}
