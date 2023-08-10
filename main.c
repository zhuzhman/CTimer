#include "timer.h"

int main(void) {
  time_t secs, rawtime, deadline, pre;
  t_tm* timeinfo;

  myTimeType t = { 4, 1200, 3800 };
  secs = HMsToSecs(&t);
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
      printTime(secsToHMs(pre--, &t));
  }
  // system("say taniusha popravliasia");
  return 0;
}
