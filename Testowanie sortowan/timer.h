#ifndef TIMER_H
#define TIMER_H

#include <ctime>

class Timer
{
private:
    clock_t begin, end;
    bool paused, running;

public:
	Timer();

	void start();
	void pause();
	void stop();

	double getTime();
};

#endif // TIMER_H
