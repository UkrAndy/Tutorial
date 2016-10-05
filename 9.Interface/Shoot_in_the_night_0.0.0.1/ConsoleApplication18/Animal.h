#pragma once
#include "IMoveable.h";
#include "IPositionable.h";
#include  "ISerializable.h";
#include <string>
class Animal:public IMoveable, public IPositionable, public ISerializable
{

public:
	
protected:
	int animalType;
	int position;
	int maxStep;
	int maxPosition;
public:
	void move();
	int getPosition();
	void setPosition(int value);
	string serialize();
	void deSerialize(string str);
	Animal(int animalType, int position, int maxStep, int maxPosition);
	Animal(int maxPosition);
};

