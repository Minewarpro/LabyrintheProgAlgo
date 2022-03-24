#pragma once
#include <iostream>
#include <windows.h>
#include <vector>

using namespace std;
// Fonction pour afficher des cases a notre tableau a la place de valeur
void showTab(vector<vector<int>> maze) {
    system("cls");
    HANDLE console;
    console = GetStdHandle(STD_OUTPUT_HANDLE);
    for (int i = 0; i < maze.size(); i++) {
        for (int j = 0; j < maze[i].size(); j++) {
            switch (maze[i][j])
            {
            case -1:
                SetConsoleTextAttribute(console, 119); //gris clair
                cout << "XX";
                break;
            case 1:
                SetConsoleTextAttribute(console, 17); // bleu
                cout << "XX";
                break;
            default:
                
                SetConsoleTextAttribute(console, 17); // bleu
                cout << "XX";
                break;
            }
        }
        SetConsoleTextAttribute(console, 15);
        cout << endl;
    }
    Sleep(100); 
}

int main(){
    vector <int> wall;
    vector <int> line;
    vector <vector<int>> maze;
    int nb = 2;
    int maze_size = 21;

    srand(time(NULL)); // mise en place d'une seed pour mes rand()

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
            maze.push_back(wall);
        }
        else {
            maze.push_back(line);
        }
    }

    // ajout d'une valeur allant de 1 jusqu'à la size de mon labyrinthe pour donner des valeur différente au chemin
    for (int x = 0; x < maze_size; x++) {
        for (int y = 0; y < maze_size; y++) {
            if (maze[x][y] == 0) {
                nb++;

                maze[x][y] = nb;

            }
            
        }
    }

    // Je déffinit mon arriver et ma sorti manuellement pour être plus précis (peut etre fais en rand()
    maze[1][0] = 1; // début
    maze[maze_size - 2][maze_size - 1] = nb; //fin
    // je les anote pour pouvoir etre sur de ce que je fais pour y placer plus tard des valeur pour avoir de vrai arriver et départ

   

    
    // tant que la case a coté de mon départ et la case a coté de mon arrivé non pas la même valeur alors on fait la boucle
   while (maze[21 - 2][21 - 2] != maze[1][1]) {

        
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
        if (maze[x - 1][y] == -1) {
            // on prend rentre dans cell 1 et 2 les coordonée de notre position  y+1 et y-1
            cell_1 = maze[x][y - 1];
            cell_2 = maze[x][y + 1];
        }
        else {//Sinon
            // on prend rentre dans cell 1 et 2 les coordonée de notre position  x+1 et x-1
            cell_1 = maze[x-1][y];
            cell_2 = maze[x+1][y];
        }

        // On vérifie sir les position sont déjà relié par un chemin grace au valeur du chemin
        // si ce n'est pas le cas alors...
        if (cell_1 != cell_2) {
            // le mur ou on est on le remplace par un chemin
            maze[x][y] = 0;
            
            // on parcour notre tableau en entier
            for (int i = 1; i < maze_size - 1; i += 2) {
                for (int j = 1; j < maze_size - 1; j += 2) {

                    // Si la position ou je me trouve a la même valeur que la cellulle 2
                    if (maze[i][j] == cell_2) { 
                        // on la remplace par la valeur de la cellulle 1 pour avoir un chemin rempli de même valeur
                        maze[i][j] = cell_1;
                    }
                }
            }
        }

        // on montre notre tableau grace a la fonction pour faire au file des boucle une sorte d'animation de création de labyrinthe mais aussi pour pouvoir débug
        showTab(maze);
        
    }

   // pour faire un labyrinthe plus complex (pas avec un seul chemin possible pour le finir on casse quelque mur au asad
   for (int i = 0; i < maze_size; i++) {
       int x = rand() % (maze_size - 2) + 1;
       int y;

       if (x % 2 == 0) {
           y = ((rand() % ((maze_size - 1) / 2))) * 2 + 1;
       }
       else {
           y = ((rand() % ((maze_size - 2) / 2))) * 2 + 2;
       }
       maze[x][y] = 0;
       // toujours la fonction pour pouvoir fair l'animation de création est débug
       showTab(maze);
   }
   // Une fois ceci terminier notre labyrinthe est créer donc nous pouvons l'afficher une bonne fois pour tous
        showTab(maze);

        // return 0 dans main() car tradition
    return 0;
}