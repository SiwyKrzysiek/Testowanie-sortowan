//Program do porownywania skutecznosci algorytmow sortujacych
//Napisany jako projekt 1 na PROI
//Autor: Krzysztof Dabrowski

#include <iostream>
#include <ctime>
#include "test.h"

using namespace std;

int main()
{
    clock_t t1,t2;
    t1=clock();
    //code goes here
    
    for (int i=0; i<9999; i++)
    {
        cout << 'a' << endl;
    }
    
    t2=clock();
    float diff ((float)t2-(float)t1);
    cout<<diff<<endl;


	return Test::autoTest();
}
