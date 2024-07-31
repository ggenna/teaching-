#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdlib.h>

#include "errlib.h"
#include "sockwrap.h"

#define MAXBUFL 255 
#define ADD_PORT 9999

char *prog;


static void add_client (int sockfd)
{
  ssize_t n;
  char buf[MAXBUFL+1];

  while ( (n = Readline(0,buf,sizeof(buf))) > 0)
  {
    Writen (sockfd, buf, n);
    if ( (n = Readline(sockfd,buf,sizeof(buf))) > 0)
      Writen (1, buf, n);
    else
      err_quit("(%s) error - unexpected EOF from server", prog);
  }
}


int main (int argc, char *argv[])
{
  int sockfd;
  struct sockaddr_in servaddr;

  // for libraries to know the program name

  prog = argv[0];

  // check the arguments

  if (argc != 2)
    err_quit ("usage: %s IPaddress_of_server", prog);

  // create socket

  sockfd = Socket(AF_INET, SOCK_STREAM, 0);

  // specify address of server to connect to

  memset (&servaddr, 0, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_port   = htons(ADD_PORT);
  Inet_pton (AF_INET, argv[1], &servaddr.sin_addr);

  // try to connect

  Connect (sockfd, (SA*) &servaddr, sizeof(servaddr));

  // read the questions, send to server, get and display the answers

  add_client (sockfd);

  // done

  exit(0);
}
