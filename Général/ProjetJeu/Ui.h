#pragma once
#include "Personnage.h"

class Ui
{
public:
	Ui();

	bool start();
	bool Death();
	bool Win();
	int StartChoix();
	int DicultyChoice();
	int CustomChoiceTaille();
	int CustomChoiceEvent();
	int CustomChoiceEtage();
	int SeedChoice();
};
