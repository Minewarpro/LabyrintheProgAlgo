#pragma once
#include "Personnage.h"
class Shifumi :
    public Personnage
{
public:
    Shifumi();
    Shifumi(int p);

    void playShifumi(Personnage& p);

    friend ostream& operator<<(ostream& os, Shifumi& tictac);
};

