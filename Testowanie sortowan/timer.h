#ifndef TIMER_H
#define TIMER_H

#include <ctime>
#include <vector>

#include "algorythm.h"
#include "parameters.h"

class Timer
{
private:
    clock_t begin, end;
    bool paused, stoped;
    
    double getTime() const;
public:
	Timer();

	void start();
	void pause();
	void stop();

    double getTimeInTicks() const;
	double getTimeInSeconds() const;
    double getTimeInMinutes() const;
    double getTimeInHours() const;
    static double timeOfSorting(Algorythm& algorythm, std::vector<int> tab);
};

#endif // TIMER_H
