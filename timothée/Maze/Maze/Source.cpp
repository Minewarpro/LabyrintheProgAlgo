#pragma once
#include <iostream>
#include <windows.h>
#include <vector>

using namespace std;

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
    Sleep(0);
}

int main(){
    vector <int> wall;
    vector <int> line;
    vector <vector<int>> maze;

    int nb = 0;
    int maze_size = 21;

    for (int i = 0; i < maze_size; i++) {
        wall.push_back(-1);

        if (i % 2 == 1) {
            line.push_back(0);
        }
        else {
            line.push_back(-1);
        }
    }

    for (int i = 0; i < maze_size; i++) {

        if (i % 2 == 0) {
            maze.push_back(wall);
        }
        else {
            maze.push_back(line);
        }
    }

    for (int x = 0; x < maze_size; x++) {
        for (int y = 0; y < maze_size; y++) {
            if (maze[x][y] == 0) {
                nb++;

                maze[x][y] = nb;

            }
            
        }
    }

    maze[1][0] = 1;
    maze[maze_size - 2][maze_size - 1] = nb;

    showTab(maze);

    

   /* while (true) {

        srand(time(NULL));

        int x = rand() % (maze_size - 2) + 1;
        int y;

        if (x % 2 == 0) {
            y = ((rand() % ((maze_size - 1) / 2))) * 2 + 1;
        }
        else {
            y = ((rand() % ((maze_size - 2) / 2))) * 2 + 2;
        }
        
        int cell_1;
        int cell_2;

        if (maze[x - 1][y] == -1) {
            cell_1 = maze[x][y - 1];
            cell_2 = maze[x][y + 1];
        }
        else {
            cell_1 = maze[x-1][y];
            cell_2 = maze[x+1][y];
        }

        if (cell_1 != cell_2) {
            maze[x][y] = 0;
            
            for (int i = 1; i < maze_size - 1; i += 2) {
                for (int j = 1; j < maze_size - 1; j += 2) {
                    if (maze[i][j] == cell_2) {
                        maze[i][j] = cell_1;
                    }
                }
            }
        }
        showTab(maze);
    }*/

 

    return 0;
}