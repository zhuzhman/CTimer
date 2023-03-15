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
 
 void		putChar(char c);
 void		printNum(time_t n);
 void		printTime(t_Time *t);
 
 void		sl(void);
 time_t		HMsToSecs(t_Time* t);
 t_Time*	secsToHMs(time_t secs, t_Time* t);
 void		pr(time_t n);
#endif
