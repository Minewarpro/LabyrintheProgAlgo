#include "Morpion.h"
#include "TicTac.h"
#include "JustePrix.h"
#include "Remember.h"
#include "Pendu.h"
#include "Ui.h"
#include "Quizz.h"
#include "Shifumi.h"
#include "Inventaire.h"
#include "Boss.h"

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_A 97
#define KEY_B 98
#define KEY_S 115

void showColor() {
    HANDLE console;
    int m;
    console = GetStdHandle(STD_OUTPUT_HANDLE);
    for (m = 1; m < 255; m++) {
        SetConsoleTextAttribute(console, m);
        cout << m << " " << endl;
    }
}
void lab(vector<vector<int>>& tab, int& maze_size, int& nbEtage, int& nbFloorDo, int& nbEvent, Personnage& p) {
    system("cls");

    vector <int> wall;
    vector <int> line;

    int nb = 2;

    tab.clear();

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
    for (int i = 0; i < maze_size; i++) {
        for (int j = 0; j < maze_size; j++) {
            if (i == 0) {
                tab[i][j] = 42;
            }
            else if (i == tab[i].size() - 1) {
                tab[i][j] = 42;
            }
            else if (j == 0) {
                tab[i][j] = 42;
            }
            else if (j == tab[j].size() - 1) {
                tab[i][j] = 42;
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

    p.setX(1);
    p.setY(1);
}        
void event( Morpion& m, TicTac& t, JustePrix& j, Remember& r, Pendu& p, Quizz& q, Shifumi& s, Personnage& player, Inventaire& inv) {
    int aleaMiniJeu = rand() % 7;
    if (aleaMiniJeu == 0) { //Morpion
        m.playMorpion(player, inv);
    }
    else if (aleaMiniJeu == 1) {  // TicTac
        t.playTictac(player, inv);
    }
    else if (aleaMiniJeu == 2) { // JustePrix
        j.playJustePrix(player, inv);
    }
    else if (aleaMiniJeu == 3) { // Remember
        r.playRemember(player, inv);
    }
    else if (aleaMiniJeu == 4) { // Remember
        p.playPendu(player, inv);
    }
    else if (aleaMiniJeu == 5) { // Remember
        q.playQuizz(player, inv);
    }
    else if (aleaMiniJeu == 6) { // Remember
        s.playShifumi(player, inv);
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
                case 2:
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
                case 42:
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
}
void Save(vector<vector<int>>& tab, int maze_size, int nbEtage, int nbFloorDo, int nbEvent, Personnage& p, Inventaire& inv) {
    ofstream savelab;
    ofstream saveSize;
    ofstream savePotion;
    ofstream saveBombe;
    ofstream saveEtage;
    ofstream savePv;

    savelab.open("save/save_lab.txt");
    if (savelab) {
        for (int i = 0; i < tab.size(); i++) {
            for (int j = 0; j < tab[i].size(); j++) {

                savelab << tab[i][j] << " ";

            }
            savelab << endl << endl;
        }
    }
    else {
        cout << "erreur";
        Sleep(10000);
    }


    saveSize.open("save/save_taille.txt");
    if (saveSize) {
        saveSize << maze_size << " ";
    }
    else {
        cout << "erreur";
        Sleep(10000);
    }


    savePotion.open("save/save_potion.txt");
    if (savePotion) {
        savePotion << inv.getNbPotion() << " ";
    }
    else {
        cout << "erreur";
        Sleep(10000);
    }

    saveBombe.open("save/save_bombe.txt");
    if (saveBombe) {
        saveBombe << inv.getNbBombe() << " ";
    }
    else {
        cout << "erreur";
        Sleep(10000);
    }

    saveEtage.open("save/save_etage.txt");
    if (saveEtage) {
        saveEtage << nbFloorDo << " ";
    }
    else {
        cout << "erreur";
        Sleep(10000);
    }

    savePv.open("save/save_pv.txt");
    if (savePv) {
        savePv << p.getPoints() << " ";
    }
    else {
        cout << "erreur";
        Sleep(10000);
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
                    if (tab[p.getY() + j][p.getX() + i] == 42) {
                        tab[p.getY() + j][p.getX() + i] = 2;

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
                if (tab[p.getY() + j][p.getX() + i] == 42) {

                    tab[p.getY() + j][p.getX() + i] = 2;
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
void Load(vector<vector<int>>& tab, int& maze_size, Personnage& p, Inventaire& inv, int& nbFloorDo) {
    tab.clear();

    ifstream maze_s;

    ifstream maze_e;

    ifstream load;
    int mot;
    vector<int> ligne;

    ifstream Pv;
    int loadpv = 0;

    ifstream bombe;
    int loadb = 0;

    ifstream potion;
    int loadp = 0;



    maze_s.open("save/save_taille.txt");
    if (maze_s) {

        maze_s >> maze_size;

    }
    else {
        cout << "erreur";
        Sleep(10000);
    }

    maze_e.open("save/save_etage.txt");
    if (maze_e) {

        maze_e >> nbFloorDo;

    }
    else {
        cout << "erreur";
        Sleep(10000);
    }

    load.open("save/save_lab.txt");
    if (load) {

        for (int i = 0; i < maze_size; i++) {
            for (int j = 0; j < maze_size; j++) {

                load >> mot;

                ligne.push_back(mot);

            }

            tab.push_back(ligne);
            ligne.clear();
        }

    }
    else {
        cout << "erreur";
        Sleep(10000);
    }

    Pv.open("save/save_pv.txt");
    if (Pv) {
        Pv >> loadpv;

        p.setPoints(loadpv);
    }
    else {
        cout << "erreur";
        Sleep(10000);
    }

    bombe.open("save/save_bombe.txt");
    if (bombe) {
        bombe >> loadb;

        inv.setNbBombe(loadb);
    }
    else {
        cout << "erreur";
        Sleep(10000);
    }

    potion.open("save/save_potion.txt");
    if (potion) {
        potion >> loadp;

        inv.setNbPotion(loadp);
    }
    else {
        cout << "erreur";
        Sleep(10000);
    }

    showMaze(tab);
    Sleep(2000);
    p.setX(1);
    p.setY(1);
}
void move(vector<vector<int>>& tab, Personnage& p, Inventaire& inv, int maze_size, int nbEtage, int nbFloorDo, int nbEvent) {

    int c, ex;
    c = _getch();
    if (c && c != 224 && c != 97 && c != 98 && c!=115)
    {
        
    }
    else if (c && c != 97 && c != 98 && c!=115) {
        switch ((ex = _getch()))
        {
        case KEY_UP:
            if (tab[p.getY() - 1][p.getX()] != 1 && tab[p.getY() - 1][p.getX()] != 2) {
                p.setY(p.getY() - 1);
            }
            break;
        case KEY_DOWN:
            if (tab[p.getY() + 1][p.getX()] != 1 && tab[p.getY() + 1][p.getX()] != 2) {
                p.setY(p.getY() + 1);
            }
            break;
        case KEY_RIGHT:
            if (tab[p.getY()][p.getX() + 1] != 1 && tab[p.getY()][p.getX() + 1] != 2) {
                p.setX(p.getX() + 1);
            }
            break;
        case KEY_LEFT:
            if (tab[p.getY()][p.getX() - 1] != 1 && tab[p.getY()][p.getX() - 1] != 2) {
                p.setX(p.getX() - 1);
            }
            break;
        default:
            cout << endl << "null" << endl;  // not arrow
            break;
        }
    }

    else {
        switch (c) 
        {
        case KEY_A:
            if (inv.getNbPotion() > 0) {
                inv.potion(10, p);        
            }

            

            break;            
        case KEY_B:

            if (inv.getNbBombe() > 0) {
                inv.bombe(tab, p);   
            }
            break;
        case KEY_S:
            system("cls");
            Save(tab, maze_size, nbEtage, nbFloorDo, nbEvent, p, inv);
            cout << "sauvegarde..." << endl << "veulliez ne pas eteindre la console" << endl;
            Sleep(10000);
            break;
        default:
            break;
        }
    }

    brouillard(tab, p, maze_size);
}
int main() {

    

    PlaySound(TEXT("sod.wav"), NULL, SND_FILENAME | SND_ASYNC);


    locale::global(locale{ "" });
    SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, 0);
    
    vector<vector<int>> tab;

    int nbEvent = 20;
    bool c = false;
    int block = 0;
    int maze_size = 31;
    int nbEtage = 0;
    int nbFloorDo = 0;
    int bombe = 0;
    int nbBombe = 0;
    int nbPotion = 0;
    int playerAtk = 40;
    int BossLifepoint = 200;
    


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
    Inventaire inv(6, nbPotion, nbBombe);
    Boss b(200);
    

    ui.start();

    int seed = 0;

    srand(time(NULL));

    seed = rand() % 100000000;
    switch (ui.Startmenu())
    {
    default:
        break;
    case 1:
        switch (ui.StartChoix())
        {
        default:
            break;
        case 1:
            switch (ui.DicultyChoice())
            {
            case 1:



                maze_size = 21;
                nbEvent = 7;
                nbEtage = 1;

                inv.setNbBombe(2);
                inv.setNbPotion(1);

                break;
            case 2:
                maze_size = 31;
                nbEvent = 20;
                nbEtage = 2;

                break;
            case 3:
                maze_size = 41;
                nbEvent = 35;
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

            break;
        case 2:
            maze_size = 21;
            nbEvent = 0;
            nbEtage = -1;
            break;
        case 3:
            seed = ui.SeedChoice();
            break;
        }

        break;
    case 2:
        Load(tab, maze_size, player, inv, nbFloorDo);
        c = true;
        break;
    }

    

    srand(seed);
    
    if (c != true) {
        lab(tab, maze_size, nbEtage, nbFloorDo, nbEvent, player);
    }
    

   

    //Tours
    tab[player.getY()][player.getX()] = 0; // ne pas touchew
    int tour = 10000;
    while (player.getPoints() > 0 && tab[player.getY()][player.getX()] != 5) {
        brouillard(tab, player, maze_size);
        showTab(tab, player, bombe);
        cout << player;
        inv.showInventaire();
        cout << "Appuyez sur 'S' pour sauvegarder" << endl;
        cout << endl;
        cout << "Etage : "<<nbFloorDo<<endl;
        cout << "Seed du labyrinthe : " << seed << endl;
        if (tab[player.getY()][player.getX()] == 3) { // si le joueur touche un event
            event(m,t,j,r,p,q,s,player, inv);
            cout << player;
            tab[player.getY()][player.getX()] = 0;
        }
        move(tab, player, inv, maze_size, nbEtage, nbFloorDo, nbEvent);
        


        if (tab[player.getY()][player.getX()] == 4) {
            system("cls");


            nbFloorDo++;
            cout << nbFloorDo << endl;
            Sleep(1000);

            if (nbFloorDo % 2 == 0)
            {
                

                while (player.getPoints() > 0 && b.getPoints() > 0)
                {
                    system("cls");
                    block = rand() % 100 + 1;

                    int choix;
                    b.ShowBoss();
                    cout << player << endl;

                    cout << " votre choix d'action : " << endl;;
                    cout << "1.Attaque                     2.?" << endl;
                    cin >> choix;
                    cout << endl;

                    switch (choix)
                    {
                    default:
                        cout << "Choix invalide" << endl;
                        break;
                    case 1:
                        cout << "Vous attaqué le boss" << endl;
                        b.setPoints(b.getPoints() - playerAtk);
                        b.ShowBoss();
                        break;

                    case 2:
                        break;
                    }

                    if (b.getPoints() > 0)
                    {
                        if (block <= 80)
                        {
                            cout << "Le boss vous attaque gagné pour blocker les dégat";
                            Sleep(500);
                            event(m, t, j, r, p, q, s, player, inv);

                        }
                    }
                    

                }
                BossLifepoint = BossLifepoint * 1.3;
                b.setPoints(b.getPoints() + BossLifepoint );
            }
            lab(tab, maze_size, nbEtage, nbFloorDo, nbEvent, player);
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
        return 0;
}

    
