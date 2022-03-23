#pragma once
#include "Personnage.h"
class TicTac :
    public Personnage
{
public :
    TicTac();
    TicTac(int p);

    void playTictac(Personnage& p);

    friend ostream& operator<<(ostream& os, TicTac& tictac);
};

