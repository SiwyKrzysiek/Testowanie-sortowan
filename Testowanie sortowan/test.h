#ifndef TEST_H
#define TEST_H

#include <vector>
#include "generator.h"
#include "algorythm.h"

class Test
{
public:
	static bool autoTest(std::vector<Algorythm>& sortings); //Odpala wszystkie automatyczne testy
	static bool generator();
	static bool sorting(void (*sortowanie)(std::vector<int>&));
	static bool allSortings(std::vector<Algorythm>& sortings);
};

#endif //TEST_H
