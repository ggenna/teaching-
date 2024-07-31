#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <time.h> // needed to know the current date and time

#include "errlib.h"
#include "sockwrap.h"

#define MAXBUFL 255
#define LISTENQ 15
#define DAYTIME_PORT 13

char *prog;

int main (int argc, char *argv[])
{
  int listenfd, connfd;
  struct sockaddr_in servaddr, cliaddr;
  socklen_t cliaddrlen = sizeof(cliaddr);
  char buf[MAXBUFL];
  time_t ticks;

  prog = argv[0];

  listenfd = Socket (AF_INET, SOCK_STREAM, 0);

  memset (&servaddr, 0, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
  servaddr.sin_port = htons(DAYTIME_PORT);

  Bind (listenfd, (SA*) &servaddr, sizeof(servaddr));

  Listen (listenfd, LISTENQ);

#ifdef TRACE
  printf ("(%s) socket created, waiting for connections ...\n", prog);
#endif

  for ( ; ; )
  {
    connfd = Accept (listenfd, (SA*) &cliaddr, &cliaddrlen);
#ifdef TRACE
    printf ("(%s) - new connection from client %s:%u\n", prog, inet_ntoa(cliaddr.sin_addr), ntohs(cliaddr.sin_port));
#endif

    ticks = time (NULL);
    snprintf (buf, sizeof(buf)-1, "%.24s\r\n", ctime(&ticks));

    Writen (connfd, buf, strlen(buf));

    Close (connfd);
  }
  return 0;
}
