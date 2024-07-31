//
// File: myself.c
// Purpose:
// - retrieve all info about the current node
// - demonstrate use of uname()
//

#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <netdb.h>
#include <sys/utsname.h>

#include "errlib.h"

char *prog;

int main (int argc, char *argv[])
{
  struct utsname myself;
  struct hostent *hptr;
  char **pptr;

  // for libraries to know the program name

  prog = argv[0];

  // identify myself

  if (uname(&myself) < 0)
    err_quit ("(%s) error - uname() failed", prog);

  printf ("Hello! Let me introduce myself:\n");
  printf ("- name = %s\n", myself.nodename);
  printf ("- OS   = %s\n", myself.sysname);
  printf ("- rel  = %s\n", myself.release);
  printf ("- ver  = %s\n", myself.version);
  printf ("- hw   = %s\n", myself.machine);

  // retrieve host info

  if ((hptr = gethostbyname(myself.nodename)) == NULL)
    err_quit ("(%s) error - gethostbyname() failed for '%s' : %s",
      prog, myself.nodename, hstrerror(h_errno));

  // output detailed info

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
    //puts ("IPv6");
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
