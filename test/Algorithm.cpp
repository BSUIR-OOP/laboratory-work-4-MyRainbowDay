#include "Algorithm.h"


bool Algorithm::Calculate_Hash(char* str)
{
	return false;
}

bool SHA256::Calculate_Hash(char* str)
{
	Hash = 100;
	n = 2419;
	int str_len = strlen(str);
	int symbol_code;
	for (int i = 0; i < str_len; i++)
	{
		symbol_code = (str[i] & 0xFF);
		Hash = fast_exp(Hash + symbol_code, 2, n);
	}
	if (Hash > 200)
		return false;
	else
		return true;
}

verylong SHA256::fast_exp(verylong a, verylong z, verylong n)
{
	verylong x = 1;
	verylong nul = "0";

	while (z != nul)
	{
		while ((z % 2) == nul)
		{
			z = z / 2;
			a = (a * a) % n;
		}
		z = z - 1;
		x = (x * a) % n;
	}
	return x;
}




