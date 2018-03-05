#ifndef TIMER_H
#define TIMER_H

class Timer
{
private:


public:
	Timer();

	void start();
	void pause();
	void stop();

	double getTime();
};

#endif // TIMER_H
