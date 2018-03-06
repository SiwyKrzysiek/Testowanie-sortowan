//Program do porownywania skutecznosci algorytmow sortujacych
//Napisany jako projekt 1 na PROI
//Autor: Krzysztof Dabrowski

#include <iostream>
#include <ctime>
#include "test.h"
#include "generator.h"
#include "sortings.h"
#include "timer.h"
#include "interface.h"

using namespace std;

int main()
{
	Interface interface;
	cout << interface.programInfo << endl;
	interface.mainMenu();


 //   vector<int> tablica(1000);
 //   Generator::fill(tablica);
 //   
 //   clock_t t1,t2;
 //   t1=clock();
	//Timer t;
 //   //code goes here
 //   bubbleSortV2(tablica);
 //   
 //   t2=clock();
 //   float diff (static_cast<float>(t2)-static_cast<float>(t1));
 //   cout<<diff/CLOCKS_PER_SEC<<endl;
	//cout << t.getTimeInSeconds() << endl;


	return Test::autoTest();
}
