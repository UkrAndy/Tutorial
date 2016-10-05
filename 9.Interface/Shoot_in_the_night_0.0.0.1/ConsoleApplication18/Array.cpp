#include "stdafx.h"
#include "Array.h"
#include <fstream>
using namespace std;


int Array::getLength()
{
	return length;
}


void Array::setLength(int value)
{
	if (value <= 0)
		throw "bad value";
	length = value;
	data = new Animal*[value];
}


void Array::saveToFile(string fileName)
{
	try {
		ofstream file(fileName);
		file << length<<endl;
		for (int i = 0; i < length; i++)
		{
			file << data[i]->serialize() << endl;
		}
		file.close();
	}
	catch (...)
	{
		throw "can not save data";
	}
}


void Array::readFromFile(string fileName)
{
	try {
		ifstream file(fileName);
		int n;
		file >> n;
		setLength(n);
		for (int i = 0; i < n; i++)
		{
			string temp;
			getline(file, temp, '\n');
			data[i]->deSerialize(temp);
		}
		file.close();
	}
	catch (...)
	{
		throw "can not read from file";
	}

}

void Array::removeByIndex(int index)
{
	if (index<0 || index>=length)
	{
		throw "index out of range";
	}
	for (int i = index+1; i < length; i++)
	{
		data[i - 1] = data[i];
	}
	length--;
}



Array::Array(string fileName)
{
	readFromFile(fileName);
}


Array::Array(int length)
{
	setLength(length);
}

Array::Array():Array(0)
{

}


Array::~Array()
{
	delete[]data;
}
string Array::toString()
{
	string temp = "";
	for (int i = 0; i < length; i++)
	{
		temp += "-" + to_string(data[i]->getPosition());
	}
	return temp;
}
Animal*& Array::operator[](int index)
{
	if (index<0 || index >= length)
	{
		throw "index out of range";
	}
	return data[index];
}
