//
// File: service.c
// Purpose:
// - retrieve all info about a given service
// - demonstrate use of getservbyname()
//

#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <stdlib.h>

#include "errlib.h"

char *prog;

int main (int argc, char *argv[])
{
  struct servent *servptr = NULL;
  char **pptr;

  // for libraries to know the program name

  prog = argv[0];

  // check the arguments and retrieve service info

  if (argc == 2)
  {
    if ((servptr = getservbyname(argv[1],NULL)) == NULL)
      err_quit ("(%s) error - getservbyname() failed for '%s'", prog, argv[1]);
  }
  else if (argc == 3)
  {
    if ((servptr = getservbyport(atoi(argv[1]),argv[2])) == NULL)
      err_quit ("(%s) error - getservbyport() failed for '%s over %s'", prog, argv[1], argv[2]);
  }
  else
    err_quit ("usage: %s service [ protocol ]", prog);

  // output service info

  printf ("Information available for service '%s':\n", argv[1]);

  printf ("- canonical name = '%s'\n", servptr->s_name);

  if (servptr->s_aliases[0] == NULL)
    printf ("- aliases = (none)\n");
  else
    for (pptr = servptr->s_aliases; *pptr!=NULL; pptr++)
      printf ("- alias = '%s'\n", *pptr);

  printf ("- port number = %d\n", ntohs(servptr->s_port));

  printf ("- transport protocol = %s\n", servptr->s_proto);

  // done

  return 0;
}
