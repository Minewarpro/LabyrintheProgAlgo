#pragma once
#include "Personnage.h"
class Boss :
    public Personnage
{
public:
    Boss();
    Boss(int p);


    void ShowBoss();


    friend ostream& operator<<(ostream& os, Boss& m);
};

