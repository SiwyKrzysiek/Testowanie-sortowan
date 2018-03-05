#include "sortings.h"

void stupidBubbleSort(std::vector<int>& tab)
{
    int i = 0;
    do
    {
        if(tab[i] > tab[i+1])
        {
            std::swap(tab[i], tab[i+1]);
            i = 0;
            continue;
        }
        i++;
    } while(i < tab.size()-1);
}

void bubbleSortV1(std::vector<int>& tab)
{
    int size = tab.size();
    
    for(int i = 0; i < size - 1; i++)
        for(int j = 0; j < size - 1; j++)
            if(tab[i] > tab[i + 1]) std::swap(tab[i], tab[i + 1]);
}

void bubbleSortV2(std::vector<int>& tab)
{
    int size = tab.size();
    
    for(int i = size-1; i > 0; i--)
        for(int j = 0; j < i; j++)
            if(tab[i] > tab[i + 1]) std::swap(tab[i], tab[i + 1]);
}

void bubbleSortV3(std::vector<int>& tab)
{
    int size = tab.size();
    
    for(int i = size-1; i > 0; i--)
    {
        bool posortowane = true;
        
        for(int j = 0; j < i; j++)
            if(tab[i] > tab[i + 1])
            {
                std::swap(tab[i], tab[i + 1]);
                posortowane = false;
            }
        
        if (posortowane) break;
    }
}

void quickSot(std::vector<int>& tab)
{
    std::sort(tab.begin(), tab.end());
}


















