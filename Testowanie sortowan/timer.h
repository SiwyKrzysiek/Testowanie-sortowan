#ifndef TIMER_H
#define TIMER_H

#include <ctime>

class Timer
{
private:
    clock_t begin, end;
    bool paused, stoped;
    
    double getTime();
public:
	Timer();

	void start();
	void pause();
	void stop();

    double getTimeInTicks();
	double getTimeInSeconds();
    double getTimeInMinutes();
    double getTimeInHours();
};

#endif // TIMER_H
