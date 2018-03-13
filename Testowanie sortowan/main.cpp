//Program do porownywania skutecznosci algorytmow sortujacych
//Napisany jako projekt 1 na PROI
//Autor: Krzysztof Dabrowski
//Aby dodac nowe sortowanie do testow nalezy: 
//1. Dodac do pliku sortings funkcje sortujaca, ktora przyjmuje jako argument vector<int> i go sortuje
//2. Dodac do vectora sortings w main() - Algorythm("[NAZWA SORTOWANIA]", [FUNKCJA SORTUJACA]),
#include <iostream>
#include <ctime>
#include <vector>
#include "test.h"
#include "generator.h"
#include "sortings.h"
#include "timer.h"
#include "interface.h"

using namespace std;

int main()
{
	vector<Algorythm> sortings = //Tutaj nalezy dodac nowe sortowania
	{
		//Algorythm("Sortowanie glupie", stupidBubbleSort),
		Algorythm("Sortowanie babelkowe nieoptymalne", bubbleSortV1),
		Algorythm("Sortowanie babelkowe zmniejszajace zakres", bubbleSortV3),
		Algorythm("Sortowanie babelkowe wykrywajace uporzadkowanie", bubbleSortV3),
		Algorythm("Sortowanie przez wybor", selectionSort),
		Algorythm("Sortowanie przez wstawienie", insertionSort),
		Algorythm("Sortowanie szybkie", quickSot)
	};

	Interface interface(sortings);
	cout << interface.programInfo << endl;
	interface.mainMenu();

#ifdef _DEBUG
	return Test::autoTest(sortings);
#else
	return 0;
#endif
}
