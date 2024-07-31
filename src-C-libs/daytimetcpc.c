#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
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

  sockfd = Socket(AF_INET, SOCK_STREAM, 0);

  /* specify address of server to connect to */

  memset (&servaddr, 0, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_port   = htons(DAYTIME_PORT);
  Inet_pton(AF_INET, argv[1], &servaddr.sin_addr);

  /* try to connect */

  Connect (sockfd, (SA*) &servaddr, sizeof(servaddr));

  /* read the answer */

  while ( (n = Read(sockfd,buf,MAXBUFL)) > 0)
  {
    Write (STDOUT_FILENO, buf, n);
  }

  /* close the socket */

  Close (sockfd);

  /* program is over */

  return 0;
}
