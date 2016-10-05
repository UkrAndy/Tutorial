#pragma once
#include "Array.h"
class Game
{
	Array* animals;
	int bulletsCount;
	int maxPosition;
	bool cheting;
public:

	Game();
	int play();
	int shootToPosition(int shootPosition);
	void setLevel();
	void createAnimals(int animalsCount, int maxPosition);
	void moveAnimals();
	~Game();
};

