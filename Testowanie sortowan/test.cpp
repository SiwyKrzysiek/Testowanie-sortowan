#include "test.h"

using namespace std;

bool Test::autoTest(vector<Algorythm>& sortings)
{
	if (Test::generator()) return true;
	if (Test::allSortings(sortings)) return true;

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

bool Test::sorting(void(*sortowanie) (std::vector<int>&))
{
	vector<int> randomNumbers = { 35, 20, 18, 79, 43, 51, 6, 17, 30, 86, 23, 27, 9, 86, 76, 41, 71, 98, 33, 25 };
	vector<int> sortedNumbers = { 6, 9, 17, 18, 20, 23, 25, 27, 30, 33, 35, 41, 43, 51, 71, 76, 79, 86, 86, 98 };

	sortowanie(randomNumbers);

	return randomNumbers != sortedNumbers;
}

bool Test::allSortings(vector<Algorythm>& sortings)
{
	for (Algorythm& sorting : sortings)
		if (Test::sorting(sorting.getSortingFunction()))
			return true;

	return false;
}