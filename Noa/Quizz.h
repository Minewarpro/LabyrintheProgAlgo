#pragma once
#include "Personnage.h"
class Quizz : 
    public Personnage
{
public :
    Quizz();
    Quizz(int p);
    

    void playQuizz(Personnage& p);
    void question(bool &verif);
    void question2(bool& verif);
};

