#include "stdafx.h"
#include "Animal.h"


void Animal::move()
{
	int step =1+ (1 - 2 * rand() % 2) * (rand() % maxStep);
	position += step;
	if (position<0)
		position = -position;
	if (position >= maxPosition)
		position = maxPosition - position%maxPosition;
}

int Animal::getPosition()
{
	return position;
}

void Animal::setPosition(int value)
{
	if (value<0 || value>maxPosition)
	{
		throw "position out of range";
	}
	position = value;
}

string Animal::serialize()
{
	return to_string(animalType)+"-"+to_string(position)+"-"+to_string(maxStep)+"-"+to_string(maxPosition);
}

void Animal::deSerialize(string str)
{
	str += "-";
	try {
		int l,p=0;
		animalType= atoi(str.substr(0, (l=str.find('-'))-p).c_str());
		p = l+1;
		position = atoi(str.substr(0, (l = str.find('-')) - p).c_str());
		p = l + 1;
		maxStep = atoi(str.substr(0, (l = str.find('-')) - p).c_str());
		p = l + 1;
		maxPosition = atoi(str.substr(0, (l = str.find('-')) - p).c_str());
	}
	catch (...)
	{
		throw "parsing error";
	}
}

Animal::Animal(int animalType, int position, int maxStep, int maxPosition):animalType(animalType),position(position),maxStep(maxStep),maxPosition(maxPosition)
{
}

Animal::Animal(int maxPosition):Animal(rand()%3,rand()%maxPosition,rand()%5+1,maxPosition)
{
}

