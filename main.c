#include "timer.h"

int main(void)
{
	time_t secs, rawtime, deadline, pre;
	t_tm* timeinfo;

	t_Time	t2 = { 0, 0, 1, NULL };
	t_Time	t1 = { 0, 0, 2, &t2 };
	t_Time	t0 = { 0, 0, 3, &t1 };
	t_Time*	timeArray[3] = {&t0, &t1, &t2};


	asterisk();

	ttimer(&t0, &rawtime);
	// for (int i = 0; i< 3; i++)
	// {
	// 	// secs = HMsToSecs(&t);
	// 	secs = HMsToSecs(timeArray[i]);
	// 	time(&rawtime);
	// 	deadline = rawtime + secs;
	// 	pre = secs - 1;
	// 	while (rawtime < deadline) {
	// 		sl();
	// 		timeinfo = localtime(&rawtime);
	// 		time(&rawtime);
	// 		if (rawtime >= deadline - pre)
	// 			// printTime(secsToHMs(pre--, &t));
	// 			printTime(secsToHMs(pre--, timeArray[i]));
	// 	}
	// 	system("say listo");
	// }
	// // system("say taniusha popravliasia");
	return 0;
}

void	ttimer(t_Time* t, time_t* rawtime)
{
	if (!t)
        return;

	t_Time* temp = t;
	while (temp)
	{
		listo(temp, rawtime);
		temp = temp->next;
	}
}

void	asterisk(void)
{
	write(1, "********************************\n", 34);
	write(1, "********************************\n", 34);
	write(1, "********************************\n", 34);
	write(1, "********************************\n", 34);
	write(1, "********************************\n", 34);
}

void	listo(t_Time* t, time_t* rawtime)
{
	time_t deadline, pre;
	t_tm* timeinfo;

	t->s = HMsToSecs(t);
	time(rawtime);
	deadline = *rawtime + t->s;
	pre = t->s - 1;
	while (*rawtime < deadline)
	{
		sl();
		timeinfo = localtime(rawtime);
		time(rawtime);
		if (*rawtime >= deadline - pre)
			printTime(secsToHMs(pre--, t));
	}
	system("say listo");
}
