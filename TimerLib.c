#include "timer.h"

void	putChar(char c)
{
	write(1, &c, 1);
}

void	printNum(time_t n)
{
	if (n < 0)
		putChar('-');
	if (n > 9)
		printNum((n / 10));
	putChar((n % 10) + '0');
}

void	printTime(t_Time* t)
{
	// system("clear");
	for (int i = 0; i < 5; i++)
	  write(1, "\x1b[A\33[2K\r", 9);
	write(1, "********************************\n", 34);
	write(1, "*                              *\n", 34);
	write(1, "*         ", 11);
	// printNum(t->h);
	pr(t->h);
	write(1, "H:", 3);
	// printNum(t->m);
	pr(t->m);
	write(1, "M:", 3);
	// printNum(t->s);
	pr(t->s);
	putChar('s');
	write(1, "          *", 12);
	putChar('\n');
	write(1, "*                              *\n", 34);
	write(1, "********************************\n", 34);
}

void	sl(void)
{
	if (nanosleep((const struct timespec[]){{0, 10000000L}}, NULL) < 0)
		printf("Nano sleep system call failed \n");
}

t_Time*	secsToHMs(time_t secs, t_Time* t)
{
	t->h = (secs / 3600);
	t->m = (secs - (3600 * t->h)) / 60;
	t->s = (secs - (3600 * t->h) - (60 * t->m));
	return (t);
}

time_t	HMsToSecs(t_Time* t)
{
	return (t->h * 60 * 60 + t->m * 60 + t->s);
}

void	pr(time_t n)
{
	if(n < 10)
		putChar('0');
	printNum(n);
}