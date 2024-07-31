#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <time.h> // needed to know the current date and time

#include "errlib.h"
#include "sockwrap.h"

#define MAXBUFL 255 
#define DAYTIME_PORT 13

char *prog;

int main(int argc, char *argv[])
{
  int sockfd, n;
  char buf[MAXBUFL+1];
  struct sockaddr_in servaddr, cliaddr;
  socklen_t clilen;
  time_t ticks;

  /* for errlib to know the program name */

  prog = argv[0];

  /* create socket */

  sockfd = Socket(AF_INET, SOCK_DGRAM, 0);

  /* specify address to bind to */

  memset (&servaddr, 0, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_port   = htons(DAYTIME_PORT);
  servaddr.sin_addr.s_addr = htonl(INADDR_ANY);

  Bind (sockfd, (SA*) &servaddr, sizeof(servaddr));

#ifdef TRACE
  printf ("(%s) socket created\n", prog);
#endif

  while (1)
  {
    /* get the request */

#ifdef TRACE
    printf ("(%s) waiting for requests ...\n", prog);
#endif
    clilen = sizeof(cliaddr);
    n = Recvfrom (sockfd, buf, MAXBUFL, 0, (SA*) &cliaddr, &clilen);

#ifdef TRACE
    printf ("(%s) - new request from client %s:%u\n", prog, inet_ntoa(cliaddr.sin_addr), ntohs(cliaddr.sin_port));
#endif

    /* get and format date and time */

    ticks = time (NULL);
    n = snprintf (buf, sizeof(buf), "%.24s\r\n", ctime(&ticks));

    /* send the answer */

    Sendto (sockfd, buf, n, 0, (SA*) &cliaddr, clilen);
  }

  exit(0);
}
