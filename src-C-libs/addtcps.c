#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <sys/wait.h>

#include "errlib.h"
#include "sockwrap.h"

#define MAXBUFL 255
#define LISTENQ 15
#define ADD_PORT 9999

char *prog;

void sigchld_h (int signum)
{
  pid_t pid;
  int status;
  while ( (pid = waitpid(-1,&status,WNOHANG)) > 0)
#ifdef TRACE
    err_msg ("(%s) info - figlio %d terminato con status %d", prog, pid, status)
#endif
  ; // occhio a questo punto e virgola
}

static void add_server (int connfd)
{
  char buf[MAXBUFL];
  size_t n;

  while ((n = Readline (connfd, buf, sizeof(buf)-1)) > 0)
  {
    long a, b;
    buf[n] = '\0';
    if (sscanf(buf,"%ld %ld",&a,&b) != 2)
      snprintf (buf, sizeof(buf), "data error\r\n");
    else
      snprintf (buf, sizeof(buf), "%ld\r\n", a+b);
    Writen (connfd, buf, strlen(buf));
  }
}

int main (int argc, char *argv[])
{
  int listenfd, connfd;
  struct sockaddr_in servaddr, cliaddr;
  socklen_t cliaddrlen;
  pid_t pid;

  prog = argv[0];

  listenfd = Socket (AF_INET, SOCK_STREAM, 0);

  memset (&servaddr, 0, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
  servaddr.sin_port = htons(ADD_PORT);

  Bind (listenfd, (SA*) &servaddr, sizeof(servaddr));

  Listen (listenfd, LISTENQ);

#ifdef TRACE
  err_msg ("(%s) info - socket created, waiting for connections ...\n", prog);
#endif

  signal (SIGCHLD, sigchld_h);

  while (1)
  {
    cliaddrlen = sizeof(cliaddr);
    connfd = Accept (listenfd, (SA*) &cliaddr, &cliaddrlen);
#ifdef TRACE
    err_msg ("(%s) info - new connection from client %s:%u", prog, inet_ntoa(cliaddr.sin_addr), ntohs(cliaddr.sin_port));
#endif
    if ((pid = fork()) == 0) // this is the child
    {
      Close (listenfd);
      add_server (connfd);
      Close (connfd);
      exit (0);
    }
    else // this is the parent
    {
      Close (connfd);
#ifdef TRACE
      err_msg ("(%s) info - child %d spawned", prog, pid);
#endif
    }
  }
  return 0;
}
