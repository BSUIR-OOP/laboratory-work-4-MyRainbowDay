#include <iostream>
#include <Windows.h>
#include "DI_Library.h"
#include "Miner.h"
#include "verylong.h"
#include "Algorithm.h"
using namespace std;


int main()
{
	Miner& miner = Singleton<Miner>::getInstance();	
	Transient<Algorithm, SHA256> transient;

	Algorithm* ptr = transient.add_link();
	miner.Choice_Hash_Func(ptr);

	while (true)
	{
		miner.Get_Secret_Shifr();
		if (miner.work_process() == true)
		{
			miner++;
			cout << "Congratulations, you have found Bitcoin!" << endl;
			cout << "Your balance is: " << miner.Get_Balance() << endl;
		}

		if (miner.Get_Balance() == 10)
			break;

		Sleep(5);
	}


	return 0;
}