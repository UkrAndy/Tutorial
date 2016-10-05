#pragma once
#include <string>;
using namespace std;

__interface ISerializable
{
	string serialize();
	void deSerialize(string str);
};