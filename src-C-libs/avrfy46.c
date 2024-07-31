/*

module: avrfy46.c

purpose: test if valid IPv4/IPv6 address provided

*/

#include <stdio.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include "errlib.h"

#define USE_IPv6 0

char* prog;

int main (int argc, char *argv[])
{
  int status;

  prog = argv[0];
  
  if (argc != 2)
    err_quit ("usage: %s address", prog);

  {
  struct in_addr a4;
  status = inet_pton (AF_INET, argv[1], &a4);
  if (status == -1)
    err_msg ("(%s) error - IPv4 addresses not supported", prog);
  else if (status == 0)
    err_msg ("(%s) %s is not a valid IPv4 address", prog, argv[1]);
  else
    err_msg ("(%s) %s is a valid IPv4 address", prog, argv[1]);
  }

#if USE_IPv6
  {
  struct in6_addr a6;
  status = inet_pton (AF_INET6, argv[1], &a6);
  if (status == -1)
    err_msg ("(%s) error - IPv6 addresses not supported", prog);
  else if (status == 0)
    err_msg ("(%s) %s is not a valid IPv6 address", prog, argv[1]);
  else
    err_msg ("(%s) %s is a valid IPv6 address", prog, argv[1]);
  }
#endif

  return 0;
}
