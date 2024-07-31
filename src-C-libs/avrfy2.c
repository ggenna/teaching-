/*

module: avrfy2.c

purpose: test if valid address provided (v2)

*/

#include <stdio.h>
#include <arpa/inet.h> // for inet_... functions
#include <sys/types.h> // for uint_t types
#include <netinet/in.h> // for ntoh / hton functions
#include "errlib.h"

int main (int argc, char *argv[])
{
  struct in_addr x;
  uint32_t num_addr;

  if (argc != 2)
    err_quit ("usage: %s address", argv[0]);

  if (inet_aton (argv[1], &x) != 0)
  {
    num_addr = ntohl (x.s_addr);
    printf ("%s = %lu\n", argv[1], (unsigned long)num_addr);
  }
  else
    err_quit ("(%s) error - illegal address '%s'", argv[0], argv[1]);

  return 0;
}
