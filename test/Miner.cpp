#include "Miner.h"
#include "Algorithm.h"


Miner::Miner()
{
	count_Bitcoin = 0;
	vlstr[0] = '\0';
	ptr = NULL;
}

void Miner::Choice_Hash_Func(Algorithm* choice)
{
	ptr = choice;
}

void Miner::operator++(int)
{
	count_Bitcoin++;
}

void Miner::Get_Secret_Shifr()
{
	const int size = 20;
	srand(time(NULL));

	string shifr;

	for (int i = 0, j = 0; i < size; i++) {
		j = rand() % 10 + 1;

		if (j > size - i) j = size - i;
		i += j;

		for (int k = 0; k < j; k++) {
			shifr += (char)(rand() % 26 + 97);
		}
		shifr += ' ';
	}
	shifr[shifr.size() - 1] = '.';
	strcpy(vlstr, shifr.c_str());
}

int Miner::Get_Balance()
{
	return count_Bitcoin;
}

bool Miner::work_process()
{
	return ptr->Calculate_Hash(vlstr);
}
