#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <signal.h>

#include "errlib.h"

#ifndef SLEEP_TIME
#define SLEEP_TIME 30
#endif

enum {NORMAL, CLK, USR} end_status;

void sveglia (int x)
{
  /* nothing to do, just avoid being killed */
  end_status = CLK;
}


void user (int x)
{
  /* nothing to do, just avoid being killed */
   end_status = USR;
}


int main (int argc, char *argv[])
{
  long x;
  unsigned int duration, time_left, sleep_time=SLEEP_TIME;

  if (argc != 2)
    err_quit ("usage: %s duration", argv[0]);

  if (sscanf(argv[1],"%lu",&x) != 1 || x > UINT_MAX)
    err_quit ("(%s) error - '%s' is not a valid value (1...%u)", argv[0], argv[1], UINT_MAX);

  duration = x;

  signal (SIGALRM, sveglia);
  signal (SIGUSR1, user);

  printf ("Going to sleep for %u s ... ", sleep_time);
  fflush (stdout);
  end_status = NORMAL;
  alarm (duration);
  time_left = sleep(sleep_time);
  switch (end_status)
  {
  case NORMAL:
    printf ("YAWN!\nnaturally waked-up (end of sleep(%u))\n", sleep_time);
    break;
  case CLK:
    printf ("DRIIIN!\nwaked-up by the alarm-clock (SIGALRM), with %u s left before my natural wake-up\n", time_left);
    break;
  case USR:
    printf ("URGH! What do you need, Master?\nyou have summoned me %u s before my natural wake-up\n", time_left);
    break;
  default:
    err_quit ("(%s) bug - impossible 'end_status' case", argv[0]);
  }

  exit(0);
}
