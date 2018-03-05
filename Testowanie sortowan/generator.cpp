#include "generator.h"


Generator::Generator()
{
	srand((unsigned int)time(nullptr));
}

void Generator::fill(std::vector<int>& tab, int maxValue, int minValu)
{
	if (maxValue < minValu) return;
	for (auto& a : tab)
		a = rand() % (maxValue - minValu + 1) + minValu;
}

