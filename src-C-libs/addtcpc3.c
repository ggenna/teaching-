//
// File: addtcpc3.c
// Purpose:
// - client that uses select() to maximize throughput
// - uses shutdown() to avoid error when input is redirected from a file
//

#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h> // for STDIN_FILENO

#include "errlib.h"
#include "sockwrap.h"

#define MAXBUFL 255 
#define ADD_PORT 9999

#define	max(a,b) ((a) > (b) ? (a) : (b))

#ifndef FALSE
#define FALSE 0
#define TRUE (!FALSE)
#endif


char *prog;


static void add_client (int sockfd)
{
  ssize_t n;
  char sendline[MAXBUFL+1];
  char recvline[MAXBUFL+1];
  int maxfdp1;
  fd_set readset;
  int stdin_eof = FALSE;

  FD_ZERO (&readset);
  while (1)
  {
    if (stdin_eof == FALSE)
    {
      FD_SET (STDIN_FILENO, &readset);
      FD_SET (sockfd, &readset);
      maxfdp1 = max(STDIN_FILENO,sockfd) + 1;
    }
    else
    {
      FD_SET (sockfd, &readset);
      maxfdp1 = sockfd + 1;
    }

    Select (maxfdp1, &readset, NULL, NULL, NULL); // no timeout

    if (FD_ISSET(sockfd,&readset)) // socket is readable
    {
      if ( (n = Readline(sockfd,recvline,sizeof(recvline))) > 0)
        Writen (STDOUT_FILENO, recvline, n);
      else if (stdin_eof)
	return;
      else
        err_quit("(%s) error - unexpected EOF from server", prog);
    }

    if (FD_ISSET(STDIN_FILENO,&readset)) // standard input is readable
    {
      if ( (n = Readline(STDIN_FILENO,sendline,sizeof(sendline))) > 0)
        Writen (sockfd, sendline, n);
      else // EOF, perform shutdown and continue
      {
        stdin_eof = TRUE;
        Shutdown (sockfd, SHUT_WR);
	FD_CLR (STDIN_FILENO, &readset);
      }
    }
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

  Connect(sockfd, (SA*) &servaddr, sizeof(servaddr));

  // read the questions, send to server, get and display the answers

  add_client (sockfd);

  // done

  exit(0);
}
