#pragma once
#include "Personnage.h"
class Quizz :
    public Personnage
{
    Quizz();
    Quizz(int p);
    

    void main();
    void question(bool &verif);
    void question2(bool& verif);



    friend ostream& operator<<(ostream& os, Quizz& m);
};

