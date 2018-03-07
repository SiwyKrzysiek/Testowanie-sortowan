#ifndef GENERATOR_H
#define GENERATOR_H

#include <vector>
#include <ctime>
#include <cstdlib>

class Generator
{
public:
	Generator();


	void fill(std::vector<int>& tab, int maxValue = RAND_MAX, int minValu = 0);
};

#endif // GENERATOR_H
