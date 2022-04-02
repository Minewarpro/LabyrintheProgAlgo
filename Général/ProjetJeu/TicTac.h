#pragma once
#include "Personnage.h"
#include "Inventaire.h"

class TicTac :
    public Personnage
{
public :
    TicTac();
    TicTac(int p);

    void playTictac(Personnage& p, Inventaire& I);
    void getObjet(Inventaire& I);

    friend ostream& operator<<(ostream& os, TicTac& tictac);
};

