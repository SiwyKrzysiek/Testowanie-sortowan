#include "test.h"
#include <iostream>

using namespace std;

bool Test::autoTest(vector<Algorythm>& sortings)
{
	if (Test::generator()) return true;
	if (Test::allSortings(sortings)) return true;

	return false;
}

bool Test::generator()
{
	const int min = 1;
	const int max = 100;

	vector<int> tab(100);
    
    Generator generator;
	generator.fill(tab, 100, 1);

	for (int a : tab)
	{
		if (a<min || a>max)
			return true;
	}

	return false;
}

bool Test::sorting(void(*sortowanie) (std::vector<int>&))
{
	vector<int> randomNumbers = { 35, 20, 18, 79, 43, 51, 6, 17, 30, 86, 23, 27, 9, 86, 76, 41, 71, 98, 33, 25 };
	vector<int> sortedNumbers = { 6, 9, 17, 18, 20, 23, 25, 27, 30, 33, 35, 41, 43, 51, 71, 76, 79, 86, 86, 98 };

	sortowanie(randomNumbers);

	return randomNumbers != sortedNumbers;
}

bool Test::allSortings(vector<Algorythm>& sortings)
{
	for (Algorythm& sorting : sortings)
		if (Test::sorting(sorting.getSortingFunction()))
			return true;

	return false;
}

void Test::testingMenu()
{
	const string menu = "Wybierz jaka funkcjonalnosc chcesz przetestowac:\n"
		"1. Licznik czasu\n"
		"q - wroc do glownego menu\n";

	while (true)
	{
		std::cout << menu << endl;

		char decision;
		std::cin >> decision;

		switch (decision)
		{
		case '1':
			timerManualTesting();
			break;
		case 'q':
			return;
		default:
			cout << "Nierozpoznay znak. Sprobuj ponownie" << endl;
		}
	}
}

void Test::timerManualTesting()
{
	cout << "Licznik zostal odpalony." << endl;

	const std::string menu = "Mozliwe akcje:\n"
		"1. Wystartuj licznik\n"
		"2. Zapalzuj licznik\n"
		"3. Zatrzymaj licznik\n"
		"--------------------------------------\n"
		"4. Odczytaj czas w cyknieciach zegra\n"
		"5. Odczytaj czas w sekundach\n"
		"6. Odczytaj czas w minutach\n"
		"7. Odczytaj czas w godzinach\n"
		"q - Wroc do menu testow\n";

	Timer timer;
	while (true)
	{
		cout << menu << endl;
		
		char decision;
		cin >> decision;
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //Wyczyszczenie strumienia

		switch (decision)
		{
		case '1':
			timer.start();
			cout << "Licznik zostal uruchomiony" << endl;
			break;
		case '2':
			timer.pause();
			cout << "Licznik zostal zapalzowany" << endl;
			break;
		case '3':
			timer.stop();
			cout << "Licznik zostal zatrzymany" << endl;
			break;
		case '4':
			cout << timer.getTimeInTicks() << " T" << endl;
			break;
		case '5':
			cout << timer.getTimeInSeconds() << " s" << endl;
			break;
		case '6':
			cout << timer.getTimeInMinutes() << " m" << endl;
			break;
		case '7':
			cout << timer.getTimeInHours() << " h" << endl;
			break;
		case 'q':
			return;
		default:
			cout << "Nierozpoznay znak. Sprobuj ponownie" << endl;
		}
	}
}