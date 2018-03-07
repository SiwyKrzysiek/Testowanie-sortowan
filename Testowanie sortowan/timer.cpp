#include "timer.h"

Timer::Timer()
{
    begin = clock();
    paused = false;
    stoped = false;
}

void Timer::start()
{
    stoped = false;
    
    if (paused)
        paused = false;
    else
        begin = clock();
}

void Timer::pause()
{
    if (!paused && !stoped)
    {
        end = clock();
        paused = true;
    }
}

void Timer::stop()
{
    end = clock();
    stoped = true;
    paused = false;
}

double Timer::getTime() const
{
	if (paused || stoped)
        return (end - begin);
    else
        return (clock() - begin);
}

double Timer::getTimeInTicks() const
{
    return getTime();
}

double Timer::getTimeInSeconds() const
{
        return getTime() / CLOCKS_PER_SEC;
}

double Timer::getTimeInMinutes() const
{
    return getTimeInSeconds() / 60.0;
}

double Timer::getTimeInHours() const
{
    return getTimeInMinutes() / 60.0;
}

double Timer::timeOfSorting(Algorythm algorythm, std::vector<int> tab)
{
    //Timer
}
