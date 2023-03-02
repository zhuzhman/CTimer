#ifndef TIMER_H
	#define TIMER_H

	#include <stdio.h>
	#include <stdlib.h>
	#include <time.h>
	#include <unistd.h>
  #include <sys/time.h>

	typedef struct s_Time
	{
		int h;
		int m;
		int s;
	} t_Time;

  typedef struct tm t_tm;

	void	putChar(char c);
	int   printNum(int n);
	void	printTime(t_Time *t);
	void	mydelay(clock_t ms);
	void	sl(void);

  void sl(void);
  void pr(int pre, struct tm* timeinfo);
  time_t  HMsToSecs(time_t h, time_t m, time_t s);
  t_Time*  secsToHMs(time_t secs, t_Time* t);
#endif
