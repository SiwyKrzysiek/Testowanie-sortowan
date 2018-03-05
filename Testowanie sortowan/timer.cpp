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

double Timer::getTime()
{
	if (paused || stoped)
        return (end - begin);
    else
        return (clock() - begin);
}

double Timer::getTimeInTicks()
{
    return getTime();
}

double Timer::getTimeInSeconds()
{
        return getTime() / CLOCKS_PER_SEC;
}

double Timer::getTimeInMinutes()
{
    return getTimeInSeconds() / 60.0;
}

double Timer::getTimeInHours()
{
    return getTimeInMinutes() / 60.0;
}
