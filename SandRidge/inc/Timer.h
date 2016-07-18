#ifndef _TIMER_H_
#define _TIMER_H_

#include <SDL.h>

class Timer
{
public:
	
	//Initialize variables
	Timer();

	//Various clock actions
	void start();
	void stop();
	void pause();
	void unpause();

	//Get the timers time
	Uint32 getTicks();

	//Check the status of the timer
	bool isStarted();
	bool isPaused();

private:
	//The clock time when the timer started
	Uint32 mStartTicks;

	//The ticks stored when the timer is paused
	Uint32 mPausedTicks;

	//The timer status
	bool mPaused;
	bool mStarted;

};
#endif //!_TIMER_H_