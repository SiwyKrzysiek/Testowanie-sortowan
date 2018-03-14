#ifndef INTERFACE_H
#define INTERFACE_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <iomanip>

#include "parameters.h"
#include "generator.h"
#include "algorythm.h"
#include "timer.h"
#include "test.h"

class Interface
{
	std::string mainMenuContent() const;
	void regenerateTable();
	std::string tableAjustmentMenuContent;
	std::vector<Algorythm> sortings;
	std::vector<int> tab;
	int maxi, mini;

public:
	const std::string programInfo;

	Interface(const std::vector<Algorythm>& sortings);
	void mainMenu();
	void testAllSortings();
	void testGivenSorting();
	void tableAjustmentMenu();
	static std::vector<int> readTableFromUser();
	static std::string vectorToString(const std::vector<int>& tab);
};

#endif //INTERFACE_H