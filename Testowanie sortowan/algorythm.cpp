#include "algorythm.h"

using namespace std;

Algorythm::Algorythm(const string name, void(*sortowanie) (vector<int>&)) : name(name), sortowanie(sortowanie)
{
	
}

std::string Algorythm::getName() const
{
	return name;
}

void Algorythm::setName(std::string name)
{
	this->name = name;
}

void Algorythm::sort(vector<int>& tab)
{
	sortowanie(tab);
}
