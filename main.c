#include "timer.h"

int main(void)
{
	time_t secs, rawtime, deadline, pre;
	t_tm* timeinfo;

	t_Time	t0 = { 0, 0, 3 };
	t_Time	t1 = { 0, 0, 2 };
	t_Time	t2 = { 0, 0, 1 };
	t_Time*	timeArray[3] = {&t0, &t1, &t2};

	for (int i = 0; i< 1; i++)
	{
		// secs = HMsToSecs(&t);
		secs = HMsToSecs(timeArray[i]);
		time(&rawtime);
		deadline = rawtime + secs;
		pre = secs - 1;
		// write(1, "\n\n\n", 3);
		write(1, "********************************\n", 34);
		write(1, "********************************\n", 34);
		write(1, "********************************\n", 34);
		write(1, "********************************\n", 34);
		write(1, "********************************\n", 34);
		while (rawtime < deadline) {
			sl();
			timeinfo = localtime(&rawtime);
			time(&rawtime);
			if (rawtime >= deadline - pre)
				// printTime(secsToHMs(pre--, &t));
				printTime(secsToHMs(pre--, timeArray[i]));
		}
		system("say listo");
	}
	// system("say taniusha popravliasia");
	return 0;
}
