#include "Morpion.h"

Morpion::Morpion()
{
}

Morpion::Morpion(int p)
{
	setPoints(p);
}

vector<vector<int>> Morpion::tab(int tabX, int tabY)
{
    vector<vector<int>> tab;
    

    for (int i = 0; i < tabY; i++) {
        tab.push_back(vector<int>(tabX));
        for (int j = 0; j < tabX; j++) {
            tab[i][j] = rand() % 2;
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
                cout << "|O|";
                break;
            case 1:
                cout << "|X|";
                break;
            case 2:
                cout << "| |";
                break;
            default:
                break;
            }
        }
        cout << endl;
    }
}

ostream& operator<<(ostream& os, Morpion const& m)
{
	os << "Le Morpion a " << m.getPoints() << " points" << endl << endl;
	return os;
}
