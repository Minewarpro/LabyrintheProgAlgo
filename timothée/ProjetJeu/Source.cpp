#include "Morpion.h"
#include "TicTac.h"


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
void showTab(vector<vector<int>> tab, Personnage& p) {
    system("cls");
    HANDLE console;
    console = GetStdHandle(STD_OUTPUT_HANDLE);
    for (int i = 0; i < tab.size(); i++) {
        for (int j = 0; j < tab[i].size(); j++) {
            if (p.getY() == i && p.getX() == j) {
                SetConsoleTextAttribute(console, 204); // rouge
                cout << "XX";

            }
            else {
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
                case 43:
                    SetConsoleTextAttribute(console, 15); // noir futur bleu
                    cout << "  ";
                    break;
                case 4:
                    SetConsoleTextAttribute(console, 170); // vert
                    cout << "  ";
                    break;
                case 44:
                    SetConsoleTextAttribute(console, 15); // noir futur vert
                    cout << "  ";
                    break;
                default:
                    break;
                }
            }

        }
        SetConsoleTextAttribute(console, 15);
        cout << endl;
    }
}
void showMaze(vector<vector<int>> tab) {
    system("cls");
    HANDLE console;
    console = GetStdHandle(STD_OUTPUT_HANDLE);
    for (int i = 0; i < tab.size(); i++) {
        for (int j = 0; j < tab[i].size(); j++) {
           
                switch (tab[i][j])
                {
                case -1:
                    SetConsoleTextAttribute(console, 136); // gris foncé
                    cout << "XX";
                    break;
                default:
                    SetConsoleTextAttribute(console, 119); // gris clair
                    cout << "XX";
                    break;
            }

        }
        SetConsoleTextAttribute(console, 15);
        cout << endl;
    }
}

void brouillard(vector<vector<int>>& tab, Personnage& p,int maze_size) {
    bool b = false;
    if (p.getY() > 2 && p.getY() < maze_size - 2 && p.getX() > 2 && p.getX() < maze_size - 2) {
    for (int i = -2; i < 3; i++) {
        for (int j = -2; j < 3; j++) {
           
                if (!((i == -2 || i == 2) && (j == -2 || j == 2))) {
                    if (tab[p.getY() + j][p.getX() + i] == 40) {

                        tab[p.getY() + j][p.getX() + i] = 0;
                        
                    }

                    if (tab[p.getY() + j][p.getX() + i] == 41) {
                        tab[p.getY() + j][p.getX() + i] = 1;
                        
                    }
                    if (tab[p.getY() + j][p.getX() + i] == 43) {
                        tab[p.getY() + j][p.getX() + i] = 3;

                    }
                    if (tab[p.getY() + j][p.getX() + i] == 44) {
                        tab[p.getY() + j][p.getX() + i] = 4;

                    }
                    b = true;
                }
                
            }
            
        }
    }
    if (b == false) {
        for (int i = -1; i < 2; i++) {
            for (int j = -1; j < 2; j++) {


                if (tab[p.getY() + j][p.getX() + i] == 40) {

                    tab[p.getY() + j][p.getX() + i] = 0;
                }

                if (tab[p.getY() + j][p.getX() + i] == 41) {

                    tab[p.getY() + j][p.getX() + i] = 1;
                }
                if (tab[p.getY() + j][p.getX() + i] == 43) {
                    tab[p.getY() + j][p.getX() + i] = 3;

                }
                if (tab[p.getY() + j][p.getX() + i] == 44) {
                    tab[p.getY() + j][p.getX() + i] = 4;

                }
            }
        }
    }
}
void move(vector<vector<int>>& tab, Personnage& p,int maze_size) {

    

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
            if (tab[p.getY() - 1][p.getX()] != 1) {
                p.setY(p.getY() - 1);    
            }
            break;
        case KEY_DOWN:
            if (tab[p.getY() + 1][p.getX()] != 1) {
                p.setY(p.getY() + 1);
            }
            break;
        case KEY_RIGHT:
            if (tab[p.getY()][p.getX() + 1] != 1) {
                p.setX(p.getX() + 1);
            }
            break;
        case KEY_LEFT:
            if (tab[p.getY()][p.getX() - 1] != 1) {
                p.setX(p.getX() - 1);
            }
            break;
        default:
            cout << endl << "null" << endl;  // not arrow
            break;
        }
    }

    brouillard(tab, p, maze_size);
}
int main() {

    srand(time(NULL));
    vector<vector<int>> tab;
    vector <int> wall;
    vector <int> line;

    int nb = 2;
    int maze_size = 21;

    Personnage player(100, 1, 1);

    //Déclaration Morpion
    Morpion m1(56);

    TicTac t1(10);

    // Création des collonnes de mon labyrinthe (une totalement en mur (wall) et l'autre a moitier mur et moiter chemin (line)
    for (int i = 0; i < maze_size; i++) {
        wall.push_back(-1);

        if (i % 2 == 1) {
            line.push_back(0);
        }
        else {
            line.push_back(-1);
        }
    }

    // Création du labyrinthe en alternant wall et line pour former un quadrillage
    for (int i = 0; i < maze_size; i++) {

        if (i % 2 == 0) {
            tab.push_back(wall);
        }
        else {
            tab.push_back(line);
        }
    }

    // ajout d'une valeur allant de 1 jusqu'à la size de mon labyrinthe pour donner des valeur différente au chemin
    for (int x = 0; x < maze_size; x++) {
        for (int y = 0; y < maze_size; y++) {
            if (tab[x][y] == 0) {
                nb++;

                tab[x][y] = nb;

            }

        }
    }

    // Je déffinit mon arriver et ma sorti manuellement pour être plus précis (peut etre fais en rand()
    tab[1][1] = 1; // début
    tab[maze_size - 2][maze_size - 2] = nb; //fin
    // je les anote pour pouvoir etre sur de ce que je fais pour y placer plus tard des valeur pour avoir de vrai arriver et départ




    // tant que la case a coté de mon départ et la case a coté de mon arrivé non pas la même valeur alors on fait la boucle
    while (tab[21 - 2][21 - 2] != tab[1][1]) {


        // prend une coordonné x au asard
        int x = rand() % (maze_size - 2) + 1;
        int y;

        // Si elle est divisible part 2 alors on prend une coordonné aléatoire pour y pour "casser" le mur a la vertical
        if (x % 2 == 0) {
            y = ((rand() % ((maze_size - 1) / 2))) * 2 + 1;
        }
        else { // Sinon prend une autre coordonée aléatoire pour y pour "casser" le mur a l'horizontal
            y = ((rand() % ((maze_size - 2) / 2))) * 2 + 2;
        }


        int cell_1;
        int cell_2;

        // Si les coordonné de notre cellulle - 1 en x et unh mur alors
        if (tab[x - 1][y] == -1) {
            // on prend rentre dans cell 1 et 2 les coordonée de notre position  y+1 et y-1
            cell_1 = tab[x][y - 1];
            cell_2 = tab[x][y + 1];
        }
        else {//Sinon
            // on prend rentre dans cell 1 et 2 les coordonée de notre position  x+1 et x-1
            cell_1 = tab[x - 1][y];
            cell_2 = tab[x + 1][y];
        }

        // On vérifie sir les position sont déjà relié par un chemin grace au valeur du chemin
        // si ce n'est pas le cas alors...
        if (cell_1 != cell_2) {
            // le mur ou on est on le remplace par un chemin
            tab[x][y] = 0;

            // on parcour notre tableau en entier
            for (int i = 1; i < maze_size - 1; i += 2) {
                for (int j = 1; j < maze_size - 1; j += 2) {

                    // Si la position ou je me trouve a la même valeur que la cellulle 2
                    if (tab[i][j] == cell_2) {
                        // on la remplace par la valeur de la cellulle 1 pour avoir un chemin rempli de même valeur
                        tab[i][j] = cell_1;
                    }
                }
            }
        }

        // on montre notre tableau grace a la fonction pour faire au file des boucle une sorte d'animation de création de labyrinthe mais aussi pour pouvoir débug
       // showMaze(tab);

    }


    for (int i = 0; i < maze_size; i++) {
        for (int j = 1; j < maze_size - 1; j++) {

            // Si la position ou je me trouve a la même valeur que la cellulle 2
            if (tab[i][j] != -1) {

                tab[i][j] = 1;
            }
        }

        // debug
        // showMaze(tab);
    }
    // On met les bonne valeur
    for (int i = 0; i < maze_size; i++) {
        for (int j = 0; j < maze_size; j++) {

            // Si la position ou je me trouve a la même valeur que la cellulle 2
            if (tab[i][j] == -1) {
                // on la remplace par la valeur de la cellulle 1 pour avoir un chemin rempli de même valeur
                tab[i][j] = 41;
            }
            else {
                tab[i][j] = 40;
            }
        }
    }
    // fin de la création du labyrinthe

    
    
    //Events
    int nb_event = 0;

    while (nb_event != 10) {
        int y = rand() % maze_size;
        int x = rand() % maze_size;
        if (tab[y][x] == 40) {
            tab[y][x] = 43;
            nb_event++;
        }
    }

    tab[maze_size - 2][maze_size -2] = 44;

    
    //Tours
    tab[player.getY()][player.getX()] = 0; // ne pas touchew
    int tour = 10000;
    for (int i = 0; i < tour; i++) {
        brouillard(tab, player, maze_size);
        showTab(tab, player);
        cout << player;
        if (tab[player.getY()][player.getX()] == 3) { // si le joueur touche un event
            
            int aleaMiniJeu = rand() % 2;
            if (aleaMiniJeu == 0) { 
            Morpion m;
            m.playMorpion(player);
            cout << m1;
            }
            else if (aleaMiniJeu == 1) { // mettre un mini jeu -> mettre un 'else if' en plus par mini jeu different
                t1.playTictac(player);
                cout << t1;
            } 
            cout << player;
            tab[player.getY()][player.getX()] = 0;
        }
        move(tab, player, maze_size);
    }

    //showColor();
    
    return 0;
}