/*

module: avrfy.c

purpose: test if valid address provided

*/

#include <stdio.h>
#include <arpa/inet.h>
#include "errlib.h"

int main (int argc, char *argv[])
{
  struct in_addr x;

  if (argc != 2)
    err_quit ("usage: %s address", argv[0]);

  if (inet_aton (argv[1], &x) != 0)
    printf ("%s = %lu\n", argv[1], (unsigned long)x.s_addr);
  else
    err_quit ("(%s) error - illegal address '%s'\n", argv[0], argv[1]);

  return 0;
}
