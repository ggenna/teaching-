#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>

#include "errlib.h"
#include "sockwrap.h"

#define MAXBUFL 255 
#define DAYTIME_PORT 13

char *prog;

int main (int argc, char *argv[])
{
  int sockfd, n;
  char buf[MAXBUFL+1];
  struct sockaddr_in servaddr;

  /* for errlib to know the program name */

  prog = argv[0];

  /* check the arguments */

  if (argc != 2)
    err_quit ("usage: %s IPaddress_of_daytime_server", prog);

  /* create socket */

  sockfd = Socket (AF_INET, SOCK_DGRAM, 0);
  
  /* specify address of server to speak to */

  memset (&servaddr, 0, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_port   = htons(DAYTIME_PORT);
  Inet_pton (AF_INET, argv[1], &servaddr.sin_addr);

  /* send the request and read the answer */

  buf[0] = 'x';
  Sendto (sockfd, buf, 1, 0, (SA*) &servaddr, sizeof(servaddr));

  n = Recvfrom (sockfd, buf, MAXBUFL, 0, NULL, NULL);

  /* display the answer and quit */

  buf[n++] = '\n';
  Write (1, buf, n);

  return 0;
}
