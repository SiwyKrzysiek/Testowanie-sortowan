#ifndef INTERFACE_H
#define INTERFACE_H

#include <iostream>
#include <string>
#include <vector>

#include "algorythm.h"

class Interface
{
	std::string mainMenuContent() const;
	std::vector<Algorythm> sortings;

public:
	const std::string programInfo;

	Interface();
	void mainMenu();
};

#endif //INTERFACE_H