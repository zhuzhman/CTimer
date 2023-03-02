#include "timer.h"

void	putChar(char c)
{
	write(1, &c, 1);
}

int	printNum(int n)
{
	if (n < 0)
		return (1);
	if (n > 9)
		printNum((n / 10));
	putChar((n % 10) + '0');
	return (0);
}

void	printTime(t_Time* t)
{
  system("clear");
  write(1, "********************************\n", 34);
  write(1, "          ", 11);
	printNum(t->h);
	write(1, "H :", 4);
	printNum(t->m);
	write(1, "M :", 4);
	printNum(t->s);
	putChar('s');
	putChar('\n');
  write(1, "********************************\n", 34);
}

void	mydelay(clock_t ms)
{
	clock_t timeDelay;
	
	timeDelay = ms + clock();
	while (timeDelay > clock());
}

void sl(void) {
  if (nanosleep((const struct timespec[]){{0, 10000000L}}, NULL) < 0)
    printf("Nano sleep system call failed \n");
  //   printf ("Nano sleep successfull\n\n");
}

void pr(int pre, struct tm* timeinfo) {
  char buffer[64];
  // for (int i = 0; i < 2; i++)
        // printf("\x1b[A\33[2K\r");
  // printf("Current local time and date: %s", asctime(timeinfo));
  // printf("%.*s\n", 4, asctime(timeinfo) + 16);
  // printf("Deadline is: %s\t\t\n", asctime(localtime(&deadline)));
  // printf("%ld\t%ld\n", pre, timeinfo);
  // printf("%ld\t%s", pre, asctime(timeinfo));
  strftime (buffer, sizeof buffer, "%T\n", timeinfo);
  printf("%ld\t%s", pre, buffer);
}

t_Time*  secsToHMs(time_t secs, t_Time* t)
{
  t->h = (secs / 3600);
	t->m = (secs - (3600 * t->h)) / 60;
	t->s = (secs - (3600 * t->h) - (60 * t->m));
  return (t);
}

time_t  HMsToSecs(time_t h, time_t m, time_t s)
{
  return (h * 60 * 60 + m * 60 + s);
}