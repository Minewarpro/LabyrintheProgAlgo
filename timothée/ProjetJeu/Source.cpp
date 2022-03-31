#include "Morpion.h"
#include "TicTac.h"
#include "JustePrix.h"
#include "Remember.h"
#include "Pendu.h"
#include "Ui.h"
#include "Quizz.h"
#include "Shifumi.h"
#include "Inventaire.h"

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

// #define KEY_ENTER 13

void showColor() {
    HANDLE console;
    int m;
    console = GetStdHandle(STD_OUTPUT_HANDLE);
    for (m = 1; m < 255; m++) {
        SetConsoleTextAttribute(console, m);
        cout << m << " " << endl;
    }
}
void showTab(vector<vector<int>> tab, Personnage& p, int bombe) {
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
                    SetConsoleTextAttribute(console, 102); // orange 
                    cout << "  ";
                    break;
                case 44:
                    SetConsoleTextAttribute(console, 15); // noir futur orange
                    cout << "  ";
                    break;
                case 45:
                    SetConsoleTextAttribute(console, 15); // noir futur vert
                    cout << "  ";
                    break;
                case 5:
                    SetConsoleTextAttribute(console, 170); // vert
                    cout << "  ";
                    break;
                default:
                    SetConsoleTextAttribute(console, 170); // noir au cas ou un default
                    cout << "  ";
                    break;
                }
            }

        }
        SetConsoleTextAttribute(console, 15);
        cout << endl;
    }
    cout << "Nombre de bombe :  " << bombe << endl; 
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
void brouillard(vector<vector<int>>& tab, Personnage& p, int maze_size) {
    bool b = false;
    if (p.getY() > 1 && p.getY() < maze_size - 2 && p.getX() > 1 && p.getX() < maze_size - 2) {
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
                    if (tab[p.getY() + j][p.getX() + i] == 45) {
                        tab[p.getY() + j][p.getX() + i] = 5;
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
                if (tab[p.getY() + j][p.getX() + i] == 45) {
                    tab[p.getY() + j][p.getX() + i] = 5;
                }
            }
        }
    }
}
void move(vector<vector<int>>& tab, Personnage& p, int maze_size,int& bombe) {

    int c, ex;
    c = _getch();
    if (c && c != 224)
    {
        if (tab[p.getY()][p.getX() + 1] == 1) {

            if (bombe >= 1) {
                tab[p.getY()][p.getX() + 1] = 0;
                bombe -= 1;
            }
        }


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

    PlaySound(TEXT("sod.wav"), NULL, SND_FILENAME | SND_ASYNC);


    locale::global(locale{ "" });
    SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, 0);
    srand(time(NULL));
    vector<vector<int>> tab;
    vector <int> wall;
    vector <int> line;

    int nbEvent = 20;
    int nb = 2;
    int maze_size = 31;
    int nbEtage = 0;
    int nbFloorDo = 0;
    int bombe = 10;

    Personnage player(100, 1, 1);

    //Déclaration Events
    Morpion m(15);
    TicTac t(10);
    JustePrix j(20);
    Remember r(10);
    Pendu p(10);
    Quizz q(15);
    Shifumi s(15);
    Ui ui;
    Inventaire inv(9);

    inv.tabInventaire();
    
    
    


    ui.start();

    if (ui.StartChoix() == 1) {
        switch (ui.DicultyChoice())
        {
        case 1: 
            
            maze_size = 21;
            nbEvent = 7;
            nbEtage = 1;

            break;
        case 2: 
            maze_size = 31;
            nbEvent = 20;
            nbEtage = 2;

            break;
        case 3: 
            maze_size = 51;
            nbEvent = 40;
            nbEtage = 3;

            break;
        case 4:
            
            maze_size = ui.CustomChoiceTaille();
            if (maze_size % 2 == 0) {
                maze_size += 1;
            }

            nbEvent = ui.CustomChoiceEvent();
            while (nbEvent >= maze_size * 2) {
                nbEvent -= 2;
            }
            

            nbEtage = ui.CustomChoiceEtage();

            break;
        default:
            cout << "Erreur système";
            break;
        }

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
    while (tab[maze_size - 2][maze_size - 2] != tab[1][1]) {


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

    while (nb_event != nbEvent) {
        int y = rand() % maze_size;
        int x = rand() % maze_size;
        if (tab[y][x] == 40) {
            tab[y][x] = 43;
            nb_event++;
        }
    }

    tab[maze_size - 2][maze_size - 2] = 44;


    //Tours
    tab[player.getY()][player.getX()] = 0; // ne pas touchew
    int tour = 10000;
    while (player.getPoints() > 0 && tab[player.getY()][player.getX()] != 5) {
        brouillard(tab, player, maze_size);
        showTab(tab, player,bombe);
        cout << player;
        if (tab[player.getY()][player.getX()] == 3) { // si le joueur touche un event

            int aleaMiniJeu = rand() % 7;
            if (aleaMiniJeu == 0) { //Morpion
                m.playMorpion(player);
            }
            else if (aleaMiniJeu == 1) {  // TicTac
                t.playTictac(player);
            }
            else if (aleaMiniJeu == 2) { // JustePrix
                j.playJustePrix(player);
            }
            else if (aleaMiniJeu == 3) { // Remember
                r.playRemember(player);
            }
            else if (aleaMiniJeu == 4) { // Remember
                p.playPendu(player);
            }
            else if (aleaMiniJeu == 5) { // Remember
                q.playQuizz(player);
            }
            else if (aleaMiniJeu == 6) { // Remember
                s.playShifumi(player);
            }
            cout << player;
            tab[player.getY()][player.getX()] = 0;
        }
        move(tab, player, maze_size, bombe);
        if (tab[player.getY()][player.getX()] == 4) {
            system("cls");

            nbFloorDo++;

            tab.clear();
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
            while (tab[maze_size - 2][maze_size - 2] != tab[1][1]) {


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
            int nb_event_do = 0;

            while (nb_event_do != nbEvent) {
                int y = rand() % maze_size;
                int x = rand() % maze_size;
                if (tab[y][x] == 40) {
                    tab[y][x] = 43;
                    nb_event_do++;
                }
            }
            if (nbFloorDo != nbEtage) {
                tab[maze_size - 2][maze_size - 2] = 44;
            }
            else {
                tab[maze_size - 2][maze_size - 2] = 45;
            }

            player.setX(1);
            player.setY(1);
        }
    }

    // Vérifie si l'on est sortie du labyrinthe et si l'on a encore de le vie
    if (player.getPoints() <= 0) {
        system("cls");
        HANDLE console;
        console = GetStdHandle(STD_OUTPUT_HANDLE);
        cout << "Vous avez perdu !" << endl;;
        ui.Death();
    }
    if (tab[player.getY()][player.getX()] == 5) {
        system("cls");
        HANDLE console;
        console = GetStdHandle(STD_OUTPUT_HANDLE);
        cout << "Vous avez reussi a sortir du labyrinthe !";
        ui.Win();
    }


    }
    else {
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
        while (tab[maze_size - 2][maze_size - 2] != tab[1][1]) {


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

        while (nb_event != 20) {
            int y = rand() % maze_size;
            int x = rand() % maze_size;
            if (tab[y][x] == 40) {
                tab[y][x] = 43;
                nb_event++;
            }
        }

        tab[maze_size - 2][maze_size - 2] = 44;


        //Tours
        tab[player.getY()][player.getX()] = 0; // ne pas touchew
        int tour = 10000;
        while (player.getPoints() > 0) {
            brouillard(tab, player, maze_size);
            showTab(tab, player,bombe);
            cout << player;
            if (tab[player.getY()][player.getX()] == 3) { // si le joueur touche un event

                int aleaMiniJeu = rand() % 7;
                if (aleaMiniJeu == 0) { //Morpion
                    m.playMorpion(player);
                }
                else if (aleaMiniJeu == 1) {  // TicTac
                    t.playTictac(player);
                }
                else if (aleaMiniJeu == 2) { // JustePrix
                    j.playJustePrix(player);
                }
                else if (aleaMiniJeu == 3) { // Remember
                    r.playRemember(player);
                }
                else if (aleaMiniJeu == 4) { // Remember
                    p.playPendu(player);
                }
                else if (aleaMiniJeu == 5) { // Remember
                    q.playQuizz(player);
                }
                else if (aleaMiniJeu == 6) { // Remember
                    s.playShifumi(player);
                }
                cout << player;
                tab[player.getY()][player.getX()] = 0;
            }
            move(tab, player, maze_size, bombe);
            if (tab[player.getY()][player.getX()] == 4) {
                system("cls");


                tab.clear();
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
                while (tab[maze_size - 2][maze_size - 2] != tab[1][1]) {


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

                while (nb_event != 20) {
                    int y = rand() % maze_size;
                    int x = rand() % maze_size;
                    if (tab[y][x] == 40) {
                        tab[y][x] = 43;
                        nb_event++;
                    }
                }

                tab[maze_size - 2][maze_size - 2] = 44;

                player.setX(1);
                player.setY(1);
            }
           
        }

        // Vérifie si l'on est sortie du labyrinthe et si l'on a encore de le vie
        if (player.getPoints() <= 0) {
            system("cls");
            HANDLE console;
            console = GetStdHandle(STD_OUTPUT_HANDLE);
            cout << "Vous avez enfin perdu !" << endl;;
            ui.Death();
        }
    }
        
    //showColor();

    return 0;
}