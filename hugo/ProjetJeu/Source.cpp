#include "Morpion.h"

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

void showColor() {
    HANDLE console;
    int m;
    console = GetStdHandle(STD_OUTPUT_HANDLE);
    for (m = 1; m < 255; m++) {
        SetConsoleTextAttribute(console, m);
        cout << m << " " << endl;
    }
}
void showTab(vector<vector<int>> tab) {
    system("cls");
    HANDLE console;
    console = GetStdHandle(STD_OUTPUT_HANDLE);
    for (int i = 0; i < tab.size(); i++) {
        for (int j = 0; j < tab[i].size(); j++) {
            switch (tab[i][j])
            {
            case 0:
                SetConsoleTextAttribute(console, 119); //gris clair
                cout << "XX";
                break;
            case 1:
                SetConsoleTextAttribute(console, 136); // gris foncé
                cout << "XX";
                break;
            case 2:
                SetConsoleTextAttribute(console, 204); // rouge
                cout << "XX";
                break;
            case 3:
                SetConsoleTextAttribute(console, 17); // bleu
                cout << "XX";
                break;
            case 40:
                SetConsoleTextAttribute(console, 15); // noir futur gris clair
                cout << "  ";
                break;
            case 41:
                SetConsoleTextAttribute(console, 15); // noir futur gris foncé
                cout << "  ";
                break;
            default:
                break;
            }
        }
        SetConsoleTextAttribute(console, 15);
        cout << endl;
    }
}
void brouillard(vector<vector<int>>& tab, int& playerY, int& playerX) {
    for (int i = -2; i < 3; i++) {
        for (int j = -2; j < 3; j++) {
            
                if (tab[playerY + j][playerX + i] == 40) {
                tab[playerY + j][playerX + i] = 0;
                }
                if (tab[playerY + j][playerX + i] == 41) {
                tab[playerY + j][playerX + i] = 1;
                }
            
        }
    }
}
void move(vector<vector<int>>& tab, int& playerY, int& playerX) {
    
    brouillard(tab, playerY, playerX);

    int c, ex;
    c = _getch();
    if (c && c != 224)
    {
        cout << endl << "Not arrow: " << (char)c << endl;
    }
    else {
        switch ((ex = _getch()))
        {
        case KEY_UP:
            if (tab[playerY - 1][playerX] != 1  && tab[playerY - 1][playerX] !=41) {
                tab[playerY][playerX] = 0;
                playerY -= 1;
                tab[playerY][playerX] = 2;
            }
            break;
        case KEY_DOWN:
            if (tab[playerY + 1][playerX] != 1 && tab[playerY + 1][playerX] != 41) {
                tab[playerY][playerX] = 0;
                playerY += 1;
                tab[playerY][playerX] = 2;
            }
            break;
        case KEY_RIGHT:
            if (tab[playerY][playerX + 1] != 1 && tab[playerY][playerX + 1] != 41) {
                tab[playerY][playerX] = 0;
                playerX += 1;
                tab[playerY][playerX] = 2;
            }
            break;
        case KEY_LEFT:
            if (tab[playerY][playerX - 1] != 1 && tab[playerY][playerX - 1] != 41) {
                tab[playerY][playerX] = 0;
                playerX -= 1;
                tab[playerY][playerX] = 2;
            }
            break;
        default:
            cout << endl << "null" << endl;  // not arrow
            break;
        }
    }
    
}
int main() {
    
    srand(time(NULL));
    vector<vector<int>> tab;
    
    Personnage player(100);
    
    //Déclaration Morpion
    Morpion m1(56);
    
    //taille tableau
    int tabX = 30;
    int tabY = 30;
        
    //Creation tableau
    for (int i = 0; i < tabY; i++) { 
        tab.push_back(vector<int>(tabX));
        for (int j = 0; j < tabX; j++) {
            tab[i][j] = rand()%2 + 40;
            if (i == 0) {
                tab[0][j] = 1; //premiere ligne
            }
            else if (i == 1) { // deuxieme ligne
                tab[1][j] = 1;
            }
            else if (i == tabY-1) {
                tab[tabY-1][j] = 1; // derniere ligne
            }
            else if (i == tabY - 2) {
                tab[tabY - 2][j] = 1; // avant derniere ligne
            }
            else if (j == tabX - 2) {
                tab[i][tabX - 2] = 1; // deuxieme colonne de droite 
            }
            else if (j == 1) {
                tab[i][1] = 1; // deuxieme colonne de gauche 
            }
            tab[i][0] = 1; // colonne de gauche
            tab[i][tabX-1] = 1; // colonne de droite 
        }
    }
   
    //Position joueur
    int playerX = 5;
    int playerY = 5;
    tab[playerY][playerX] = 2;

    //Events
    int eventX = playerX;
    int eventY = playerY+1;
    tab[eventY][eventX] = 3;
           
    //Tours
    int tour = 10000;
    for (int i = 0; i < tour; i++) {
        brouillard(tab, playerY, playerX);
        showTab(tab);
        cout << player;
        if (tab[playerY][playerX] == tab[eventY][eventX]) {
         m1.showMorpion(m1);
         cout << m1;
         eventY = 0;
        }
        move(tab, playerY, playerX);
    }
    
    //showColor();
    
    return 0;
}