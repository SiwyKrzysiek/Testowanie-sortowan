#include "generator.h"


Generator::Generator()
{
	srand(time(nullptr));
}

void Generator::fill(std::vector<int>& tab, int maxValue, int minValu)
{
	for (auto& a : tab)
		a = rand() % ((maxValue - minValu) + 1) + minValu;
}

