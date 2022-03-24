#include "Pendu.h"

Pendu::Pendu()
{
}

Pendu::Pendu(int p)
{
	setPoints(p);
}

vector<vector<int>> Pendu::tabPendu(int tabX, int tabY)
{
	return vector<vector<int>>();
}


void Pendu::showPendu(vector<vector<int>>& tab)
{
    int essais(8);

    //*** Affichage d'intro ***

    system("cls");
    HANDLE console;
    console = GetStdHandle(STD_OUTPUT_HANDLE);
    cout << "====================" << endl;
    cout << " - - - LE PENDU- - - " << endl;
    cout << "====================\n" << endl;
    cout << "   .____________.   " << endl;
    cout << "   [      }     ]   " << endl;
    cout << "   |      O         " << endl;
    cout << "   |     /|\\       " << endl;
    cout << "   |      |         " << endl;
    cout << "   |     / \\       " << endl;
    cout << "   [_____________   \n" << endl;
    cout << "====================" << endl;
    cout << "\nAppuyez sur n'importe quel touche ET enter pour commencer !\n" << endl;
    
    switch (essais) {
    case 8: {
        system("cls");
        HANDLE console;
        console = GetStdHandle(STD_OUTPUT_HANDLE);
        cout << "====================\n" << endl;
        cout << "   .____________.   " << endl;
        cout << "   [            ]   " << endl;
        cout << "   |                " << endl;
        cout << "   |                " << endl;
        cout << "   |                " << endl;
        cout << "   |                " << endl;
        cout << "   [_____________   \n" << endl;
        cout << "====================" << endl;
        essais--;
    }break;
    case 7: {
        system("cls");
        HANDLE console;
        console = GetStdHandle(STD_OUTPUT_HANDLE);
        cout << "====================\n" << endl;
        cout << "   .____________.   " << endl;
        cout << "   [      }     ]   " << endl;
        cout << "   |                " << endl;
        cout << "   |                " << endl;
        cout << "   |                " << endl;
        cout << "   |                " << endl;
        cout << "   [_____________   \n" << endl;
        cout << "====================" << endl;
        essais--;
    }break;
    case 6: {
        system("cls");
        HANDLE console;
        console = GetStdHandle(STD_OUTPUT_HANDLE);
        cout << "====================\n" << endl;
        cout << "   .____________.   " << endl;
        cout << "   [      }     ]   " << endl;
        cout << "   |      O         " << endl;
        cout << "   |                " << endl;
        cout << "   |                " << endl;
        cout << "   |                " << endl;
        cout << "   [_____________   \n" << endl;
        cout << "====================" << endl;
        essais--;
    }break;
    case 5: {
        system("cls");
        HANDLE console;
        console = GetStdHandle(STD_OUTPUT_HANDLE);
        cout << "====================\n" << endl;
        cout << "   .____________.   " << endl;
        cout << "   [      }     ]   " << endl;
        cout << "   |      O         " << endl;
        cout << "   |      |         " << endl;
        cout << "   |                " << endl;
        cout << "   |                " << endl;
        cout << "   [_____________   \n" << endl;
        cout << "====================" << endl;
        essais--;

    }break;

    case 4: {
        system("cls");
        HANDLE console;
        console = GetStdHandle(STD_OUTPUT_HANDLE);
        cout << "====================\n" << endl;
        cout << "   .____________.   " << endl;
        cout << "   [      }     ]   " << endl;
        cout << "   |      O         " << endl;
        cout << "   |     /|         " << endl;
        cout << "   |                " << endl;
        cout << "   |                " << endl;
        cout << "   [_____________   \n" << endl;
        cout << "====================" << endl;
        essais--;

    }break;
    case 3: {
        system("cls");
        HANDLE console;
        console = GetStdHandle(STD_OUTPUT_HANDLE);
        cout << "====================\n" << endl;
        cout << "   .____________.   " << endl;
        cout << "   [      }     ]   " << endl;
        cout << "   |      O         " << endl;
        cout << "   |     /|\\       " << endl;
        cout << "   |                " << endl;
        cout << "   |                " << endl;
        cout << "   [_____________   \n" << endl;
        cout << "====================" << endl;
        essais--;

    }break;
    case 2: {
        system("cls");
        HANDLE console;
        console = GetStdHandle(STD_OUTPUT_HANDLE);
        cout << "====================\n" << endl;
        cout << "   .____________.   " << endl;
        cout << "   [      }     ]   " << endl;
        cout << "   |      O         " << endl;
        cout << "   |     /|\\       " << endl;
        cout << "   |      |         " << endl;
        cout << "   |                " << endl;
        cout << "   [_____________   \n" << endl;
        cout << "====================" << endl;
        essais--;

    }break;

    case 1: {
        system("cls");
        HANDLE console;
        console = GetStdHandle(STD_OUTPUT_HANDLE);
        cout << "====================\n" << endl;
        cout << "   .____________.   " << endl;
        cout << "   [      }     ]   " << endl;
        cout << "   |      O         " << endl;
        cout << "   |     /|\\       " << endl;
        cout << "   |      |         " << endl;
        cout << "   |     /          " << endl;
        cout << "   [_____________   \n" << endl;
        cout << "====================" << endl;
        essais--;

    }break;
    case 0: {
        system("cls");
        HANDLE console;
        console = GetStdHandle(STD_OUTPUT_HANDLE);
        cout << "====================\n" << endl;
        cout << "   .____________.   " << endl;
        cout << "   [      }     ]   " << endl;
        cout << "   |      O         " << endl;
        cout << "   |     /|\\       " << endl;
        cout << "   |      |         " << endl;
        cout << "   |     / \\       " << endl;
        cout << "   [_____________   \n" << endl;
        cout << "====================" << endl;
        essais = -1;
        cout << "\nTu a perdue !!!\n" << endl;
         }break;
    }
}

void Pendu::playPendu(Personnage& p)
{
    // ****
    char Devine;
    bool DevineCorrect = false;
    string Word; //le mot qu'on doit deviner
    string WordList[277]; // tableau de chaine de 100 string (jsp vraiment questceque c'est mais trkl)

    // RANDOM
    srand(time(NULL));//on l'utilise pour optenir un mot random de la liste
    ifstream RandomWord;
    RandomWord.open("liste_francais.txt"); //nôtre liste de mots avec 277 mots

    // MOT CHOISI
    for (int i = 0; i < 277; i++)
    {
        RandomWord >> WordList[i];
    }
    int RandomNum = rand() % 278; //return un nombre entre 0/277
    Word = WordList[RandomNum];
    RandomWord.close();

    // MASQUE LE MOT QUI EST CHOISI
    string MysteryWord(Word.length(), '*'); //remplace les lettres avec "_"

    int essais(8);

    // Vie-Mort affichage etc...
    while (essais >= 0)
    {
        //reset bool
        cout << DevineCorrect << endl;

        //Affichage des infos au joueurs
        cout << "== Le mot que tu dois deviner est ==\n\n"
            << "->> " << MysteryWord << " <<-\n\n"
            << "Il te reste " << essais << " essais.\n"
            << "\n-Devine une lettre : \n";
        cin >> Devine;

    }

    // Check de la lettre entrer par le joueur
    for (int i = 0; i < MysteryWord.length(); i++) // pour la longueur du mot fait :
    {
        if (Word[i] == Devine)
        {
            MysteryWord[i] = Devine;
            cout << "Felicitations !" << Devine << " fait parti du mot." << endl;
            DevineCorrect = true;

        }
    }
    if (Word == MysteryWord)
    {
        cout << "VICTOIRE !! Le mots est bel et bien : " << MysteryWord << endl;
    }

    if (DevineCorrect == false) //si la lettre devinné est incorrect :
    {
        essais--; //enleve un point d'essai et donc affiche le pendu en fonction des essais qui reste
        cout << "NON !" << Devine << " ne fait pas parti du mot..." << endl;
    };
}


int Pendu::testWin(vector<vector<int>>& tab)
{

}

ostream& operator<<(ostream& os, Pendu& m)
{
    os << "Le Pendu a " << m.getPoints() << " points d'attaque" << endl << endl;
    return os;

}
