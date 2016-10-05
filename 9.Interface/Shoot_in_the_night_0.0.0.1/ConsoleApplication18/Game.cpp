#include "stdafx.h"
#include "Game.h"
#include <iostream>
using namespace std;

Game::Game()
{
	try {
		setLevel();
		if (play())
			cout << "You won." << endl;
		else
			cout << "You lose." << endl;
	}
	catch (...)
	{
		cout << "Sorry. Error !!!";
	}
}

int Game::play()
{
	while (bulletsCount>0 && animals->getLength()>0)
	{
		cout << "cheating info: "<<animals->toString() << endl;
		int shootPosition;
		cout << "Your coordinate: ";
		cin >> shootPosition;
		cout << "You have killed : " << shootToPosition(shootPosition) << endl;
		bulletsCount--;
		moveAnimals();
	}
	if (animals->getLength()==0)
	{
		return 1;
	}
	return 0;
}

int Game::shootToPosition(int shootPosition)
{
	int killed = 0;
	for (int i = 0; i < animals->getLength(); )
	{
		if ((*animals)[i]->getPosition() == shootPosition)
		{
			animals->removeByIndex(i);
			killed++;
		}
		else
			i++;
	}
	return killed;
}

void Game::setLevel()
{
	int level, animalsCount;

	cout << "What level do you want ? (Choose level number from 1 to 3. Level 1 allows cheating)" << endl;
	cin >> level;
	cheting = false;
	switch (level)
	{
	case 1:bulletsCount = 100;
		animalsCount = 5;
		maxPosition = 20;
		cheting = true;
		break;
	case 2:bulletsCount = 50;
		animalsCount = 10;
		maxPosition = 25;
		break;
	case 3:bulletsCount = 15;
		animalsCount = 10;
		maxPosition = 30;
		break;

	default:
	    bulletsCount = 10;
		animalsCount = 10;
		maxPosition = 40;
		break;
	}	
	createAnimals(animalsCount, maxPosition);
}

void Game::createAnimals(int animalsCount, int maxPosition)
{	
	animals = new Array(animalsCount);
	for (int i = 0; i < animalsCount; i++)
	{
		(*animals)[i] = new Animal(maxPosition);
	}
}

void Game::moveAnimals()
{
	for (int i = 0; i < animals->getLength(); i++)
	{
		(*animals)[i]->move();
	}
}


Game::~Game()
{
}
