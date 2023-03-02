#include "timer.h"

int main(void) {
  time_t secs;
  time_t rawtime;
  time_t deadline;
  t_tm* timeinfo;
  time_t pre;

  t_Time t = { 0, 0, 0, };

  secs = HMsToSecs(0, 0, 3);
  time(&rawtime);
  deadline = rawtime + secs;
  pre = secs - 1;
  while (rawtime < deadline) {
    sl();
    timeinfo = localtime(&rawtime);
    time(&rawtime);

    if (rawtime >= deadline - pre)
      printTime(secsToHMs(pre--, &t));
  }
  // system("say taniusha popravliasia");
  return 0;
}
