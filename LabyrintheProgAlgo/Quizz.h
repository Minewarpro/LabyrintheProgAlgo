#pragma once
#include "Personnage.h"
#include "Inventaire.h"

class Quizz :
    public Personnage
{
public:
    Quizz();
    Quizz(int p);


    void playQuizz(Personnage& p, Inventaire& I);
    void getObjet(Inventaire& I);
    void question(bool& verif);
    void question2(bool& verif);
    void question3(bool& verif);
    void question4(bool& verif);
    void question5(bool& verif);
    void question6(bool& verif);
    void question7(bool& verif);
    void question8(bool& verif);
    void question9(bool& verif);
    void question10(bool& verif);
};

