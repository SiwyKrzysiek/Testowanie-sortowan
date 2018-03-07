//Program do porownywania skutecznosci algorytmow sortujacych
//Napisany jako projekt 1 na PROI
//Autor: Krzysztof Dabrowski

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
	vector<Algorythm> sortings =
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

#if 0
    vector<int> tablica(100);
    Generator generator;
    generator.fill(tablica);
	Algorythm algorythm("Sortowanie babelkowe", bubbleSortV3);
    
    clock_t t1,t2;
    t1=clock();
	Timer t;
    //code goes here
	algorythm.sort(tablica);
    
    t2=clock();
    float diff (static_cast<float>(t2)-static_cast<float>(t1));
    cout<<diff/CLOCKS_PER_SEC<<endl;
	cout << t.getTimeInSeconds() << endl;
#endif


	return Test::autoTest();
}
