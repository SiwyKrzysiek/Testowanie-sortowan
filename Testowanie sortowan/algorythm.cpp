#include "algorythm.h"

Algorythm::Algorythm()
{
	sortowanie = nullptr;
}

std::string Algorythm::getName() const
{
	return name;
}

void Algorythm::setName(std::string name)
{
	this->name = name;
}
