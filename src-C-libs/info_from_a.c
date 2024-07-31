//
// File: info_from_a.c
// Purpose:
// - retrieve all info about a host, given its address
// - demonstrate use of gethostbyaddr()
//

#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <netdb.h>

#include "errlib.h"

char *prog;

int main (int argc, char *argv[])
{
  struct in_addr addr;
  struct hostent *hptr;
  char **pptr;

  // for libraries to know the program name

  prog = argv[0];

  // check the arguments

  if (argc != 2)
    err_quit ("usage: %s host_address", prog);

  if (inet_pton(AF_INET,argv[1],&addr) == 0)
    err_quit ("(%s) error - invalid address '%s'", prog, argv[1]);

  // retrieve host info

  if ((hptr = gethostbyaddr((char *)&addr, 4, AF_INET)) == NULL)
    err_quit ("(%s) error - gethostbyaddr() failed for '%s' : %s",
      prog, argv[1], hstrerror(h_errno));

  // output host info

  printf ("Information available about node '%s':\n", argv[1]);

  printf ("- canonical name = '%s'\n", hptr->h_name);

  if (hptr->h_aliases[0] == NULL)
    printf ("- aliases = (none)\n");
  else
    for (pptr = hptr->h_aliases; *pptr!=NULL; pptr++)
      printf ("- alias = '%s'\n", *pptr);

  printf ("- address type = ");
  if (hptr->h_addrtype == AF_INET)
    puts ("IPv4");
//else if (hptr->h_addrtype == AF_INET6)
//  puts ("IPv6");
  else
    puts ("(unknown)");

  if (hptr->h_addr_list[0] == NULL)
    printf ("- addresses = (none)\n");
  else {
    for (pptr = hptr->h_addr_list; *pptr!=NULL; pptr++) {
      printf ("- address = %s\n", inet_ntoa(**((struct in_addr**)pptr)));
    }
  }

  // done

  return 0;
}
