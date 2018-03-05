#ifndef TIMER_H
#define TIMER_H

#include <ctime>

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
};

#endif // TIMER_H
