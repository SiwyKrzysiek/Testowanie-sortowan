#include "test.h"

using namespace std;

bool Test::autoTest()
{
	if (Test::generator()) return true;

	return false;
}

bool Test::generator()
{
	const int min = 1;
	const int max = 100;

	vector<int> tab(100);
    
    Generator generator;
	generator.fill(tab, 100, 1);

	for (int a : tab)
	{
		if (a<min || a>max)
			return true;
	}

	return false;
}
