#ifndef INTERFACE_H
#define INTERFACE_H

#include <iostream>
#include <string>

class Interface
{
	std::string mainMenuContent() const;

public:
	const std::string programInfo = "Krzysztof Dabrowski gr. 1I2\nProjekt 1 - Testowanie szybkosci algorytmow sortujacych\n-------------------------------------------------------\n";

	void mainMenu();
};

#endif //INTERFACE_H