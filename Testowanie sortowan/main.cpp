//Program do porownywania skutecznosci algorytmow sortujacych
//Napisany jako projekt 1 na PROI
//Autor: Krzysztof Dabrowski

#include <iostream>
#include <ctime>
#include "test.h"
#include "generator.h"
#include "sortings.h"

using namespace std;

int main()
{
    vector<int> tablica(1000);
    Generator::fill(tablica);
    
    clock_t t1,t2;
    t1=clock();
    //code goes here
    bubbleSortV2(tablica);
    
    t2=clock();
    float diff ((float)t2-(float)t1);
    cout<<diff/CLOCKS_PER_SEC<<endl;


	return Test::autoTest();
}
