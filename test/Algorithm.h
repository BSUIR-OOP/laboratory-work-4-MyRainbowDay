#pragma once
#include "verylong.h"

class Algorithm
{
public:
	virtual bool Calculate_Hash(char* str) = 0;
};

class SHA256 :public Algorithm
{
private:
	verylong Hash;
	int n;
public:
	bool Calculate_Hash(char* str);

	verylong fast_exp(verylong a, verylong z, verylong n);
};
