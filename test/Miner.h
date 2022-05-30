#pragma once
#include "verylong.h"
#include <ctime>

class Algorithm;

class Miner
{
private:
	Algorithm* ptr;
	int count_Bitcoin;
	char vlstr[SZ];
	Miner();
public:
	void Choice_Hash_Func(Algorithm* choice);

	void operator++(int);

	void Get_Secret_Shifr();

	int Get_Balance();

	bool work_process();
};
