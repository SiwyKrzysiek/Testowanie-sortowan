#include "timer.h"



Timer::Timer()
{
    begin = clock();
    paused = false;
    running = true;
}

void Timer::start()
{
    running = true;
    
    if (paused)
    {
        paused = false;
        begin = end;
    }
    else
        begin = clock();
}

void Timer::pause()
{
    if (!paused && running)
    {
        end = clock();
        paused = true;
        running = false;
    }
}

void Timer::stop()
{
    if (running || paused)
    {
        end = clock();
        running = false;
        paused = false;
    }
}

double Timer::getTime()
{
	if (paused)
        return (end - begin) / CLOCKS_PER_SEC;
    else
        return (clock() - begin) / CLOCKS_PER_SEC;
}
