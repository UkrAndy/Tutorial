#pragma once
#include <string>
#include "ISerializable.h"
#include "Animal.h"
class Array
{
protected:
	Animal** data;
	int length;
public:
	int getLength();
	void setLength(int value);
	void saveToFile(string fileName);
	void readFromFile(string fileName);
	void removeByIndex(int index);
	Animal*& operator[](int index);
	Array(string fileName);
	Array(int length);
	Array();
	~Array();
	string toString();
};

