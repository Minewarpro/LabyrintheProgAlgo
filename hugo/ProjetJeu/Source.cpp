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
                SetConsoleTextAttribute(console, 119);
                cout << "XX";
                break;
            case 1:
                SetConsoleTextAttribute(console, 136);
                cout << "XX";
                break;
            case 2:
                SetConsoleTextAttribute(console, 204);
                cout << "XX";
                break;
            case 3:
                SetConsoleTextAttribute(console, 17);
                cout << "XX";
                break;
            default:
                break;
            }
        }
        SetConsoleTextAttribute(console, 15);
        cout << endl;
    }
}
void move(vector<vector<int>>& tab, int& playerY, int& playerX) {
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
            if (tab[playerY - 1][playerX] != 1) {
                tab[playerY][playerX] = 0;
                playerY -= 1;
                tab[playerY][playerX] = 2;
            }
            break;
        case KEY_DOWN:
            if (tab[playerY + 1][playerX] != 1) {
                tab[playerY][playerX] = 0;
                playerY += 1;
                tab[playerY][playerX] = 2;
            }
            break;
        case KEY_RIGHT:
            if (tab[playerY][playerX + 1] != 1) {
                tab[playerY][playerX] = 0;
                playerX += 1;
                tab[playerY][playerX] = 2;
            }
            break;
        case KEY_LEFT:
            if (tab[playerY][playerX - 1] != 1) {
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
    
    Morpion m1(56);
    Morpion m2(56);
    vector<vector<int>> morpionTab = m1.tab(3, 3);
    vector<vector<int>> morpion2Tab = m2.tab(5, 5);
    
    //taille tableau
    int tabX = 30;
    int tabY = 30;
    //***************//
    // 
    
    
    //creation tableau
    for (int i = 0; i < tabY; i++) { 
        tab.push_back(vector<int>(tabX));
        for (int j = 0; j < tabX; j++) {
            tab[i][j] = 0;
            if (i == 0) {
                tab[0][j] = 1; //premiere ligne
            }
            else if (i == tabY-1) {
                tab[tabY-1][j] = 1; // derniere ligne
            }
            tab[i][0] = 1; // colonne de gauche
            tab[i][tabX-1] = 1; // colonne de droite
            
        }
    }
   
    //position joueur
    int playerX = 5;
    int playerY = 5;
    tab[playerY][playerX] = 2;

    //tableau de Personnage
    vector<Personnage> team;
    team.push_back(m1);
    team.push_back(m2);


    //Events
    vector <int> tabEvent;

        //event1
        int morpionX = playerX;
        int morpionY = playerY+1;
        tab[morpionY][morpionX] = 3;
       //event2
        int morpion2X = 6;
        int morpion2Y = 6;
        tab[morpion2Y][morpion2X] = 3;



    //Tours
    int tour = 10000;
    for (int i = 0; i < tour; i++) {
        showTab(tab);

        //Push_back
        tabEvent.push_back(tab[morpionY][morpionX]);
        tabEvent.push_back(tab[morpion2Y][morpion2X]);
        
        cout << player;
        for (int i = 0; i < tabEvent.size(); i++) {
            if (tab[playerY][playerX] == tabEvent[i]) {
               
                m1.showMorpion(morpionTab);
                
                tabEvent[i] = 0;
                morpionY = 0;
                
            }
        }
        move(tab, playerY, playerX);
    }
    
    //showColor();
    
    return 0;
}