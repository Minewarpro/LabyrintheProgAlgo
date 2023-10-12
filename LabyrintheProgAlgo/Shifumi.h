#pragma once
#include "Personnage.h"
#include "Inventaire.h"

class Shifumi :
    public Personnage
{
public:
    Shifumi();
    Shifumi(int p);

    void playShifumi(Personnage& p, Inventaire& I);
    void getObjet(Inventaire& I);

    friend ostream& operator<<(ostream& os, Shifumi& tictac);
};

