#ifndef INTERFACE_H
#define INTERFACE_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include "generator.h"
#include "algorythm.h"

class Interface
{
	std::string mainMenuContent() const;
	void regenerateTable();
	void readTableFromUser();
	std::string tableAjustmentMenuContent;
	std::vector<Algorythm> sortings;
	std::vector<int> tab;
	int maxi, mini;
	bool tableFromUser;

public:
	const std::string programInfo;

	Interface(std::vector<Algorythm>& sortings);
	void mainMenu();
	void tableAjustmentMenu();
};

#endif //INTERFACE_H