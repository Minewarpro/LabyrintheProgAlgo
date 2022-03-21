#include <iostream>
#include <windows.h>
#include <time.h>
#include <vector>
#include <stdio.h>
#include <conio.h>

using namespace std;

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
                SetConsoleTextAttribute(console, 15);
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
    int in;
    cin >> in;
    switch (in)
    {
    case 1:
        if (tab[playerY - 1][playerX] != 1) {
            tab[playerY][playerX] = 0;
            playerY -= 1;
            tab[playerY][playerX] = 2;
        }
        break;
    case 2:
        if (tab[playerY + 1][playerX] != 1) {
            tab[playerY][playerX] = 0;
            playerY += 1;
            tab[playerY][playerX] = 2;
        }
        break;
    case 3:
        if (tab[playerY][playerX + 1] != 1) {
            tab[playerY][playerX] = 0;
            playerX+= 1;
            tab[playerY][playerX] = 2;
        }
        break;
    case 4:
        if (tab[playerY][playerX - 1] != 1) {
            tab[playerY][playerX] = 0;
            playerX -= 1;
            tab[playerY][playerX] = 2;
        }
        break;
    }
    
}
void moveArrow(vector<vector<int>>& tab, int& playerY, int& playerX) {
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
    
    
    //taille tableau
    int tabX = 30;
    int tabY = 30;
    //***************//
    
    
    //creation tableau
    for (int i = 0; i < tabY; i++) { 
        tab.push_back(vector<int>(tabX));
        for (int j = 0; j < tabX; j++) {
            tab[i][j] = rand()%2;
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
    
    
    //Tours
    int tour = 10;
    showTab(tab);
    for (int i = 0; i < tour; i++) {
        moveArrow(tab, playerY, playerX);
            showTab(tab);
    }
    

    //showColor();
    
    
    return 0;
}