#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/tcp.h> /* for TCP_xxx defines */
#include "errlib.h"
#include "sockwrap.h"

#define DFL_PORT 9999

char *prog;

union val {
  int  i_val;
  long l_val;
  char c_val[10];
  struct linger  linger_val;
  struct timeval timeval_val;
} val;

static char strres[128];

static char *sock_str_flag(union val *ptr, int len)
{
   if (len != sizeof(int))
      snprintf(strres, sizeof(strres), "size (%d) not sizeof(int)", len);
   else
      snprintf(strres, sizeof(strres), "%s", (ptr->i_val == 0) ? "off" : "on");
   return(strres);
}

static char *sock_str_int(union val *ptr, int len)
{
   if (len != sizeof(int))
      snprintf(strres, sizeof(strres), "size (%d) not sizeof(int)", len);
   else
      snprintf(strres, sizeof(strres), "%d", ptr->i_val);
   return(strres);
}

static char *sock_str_linger(union val *ptr, int len)
{
   struct linger *lptr = &ptr->linger_val;

   if (len != sizeof(struct linger))
      snprintf(strres, sizeof(strres), "size (%d) not sizeof(struct linger)", len);
   else
      snprintf(strres, sizeof(strres), "l_onoff = %d, l_linger = %d", lptr->l_onoff, lptr->l_linger);
   return(strres);
}

#ifndef __CYGWIN__

/* no need for this in CYGWIN (Windows uses 'int' for timeouts) */

static char *sock_str_timeval(union val *ptr, int len)
{
   struct timeval *tvptr = &ptr->timeval_val;

   if (len != sizeof(struct timeval))
      snprintf(strres, sizeof(strres), "size (%d) not sizeof(struct timeval)", len);
   else
      snprintf(strres, sizeof(strres), "%ld sec, %ld usec", tvptr->tv_sec, tvptr->tv_usec);
   return(strres);
}

#endif


struct sock_opts {
  char *opt_str;
  int  opt_level;
  int  opt_name;
  char *(*opt_val_str)(union val *, int);
} sock_opts[] = {
{"SO_BROADCAST",	SOL_SOCKET,	SO_BROADCAST,	sock_str_flag},
{"SO_DEBUG",		SOL_SOCKET,	SO_DEBUG,	sock_str_flag},
{"SO_DONTROUTE",	SOL_SOCKET,	SO_DONTROUTE,	sock_str_flag},
{"SO_ERROR",		SOL_SOCKET,	SO_ERROR,	sock_str_int},
{"SO_KEEPALIVE",	SOL_SOCKET,	SO_KEEPALIVE,	sock_str_flag},
{"SO_LINGER",		SOL_SOCKET,	SO_LINGER,	sock_str_linger},
{"SO_OOBINLINE",	SOL_SOCKET,	SO_OOBINLINE,	sock_str_flag},
{"SO_RCVBUF",		SOL_SOCKET,	SO_RCVBUF,	sock_str_int},
{"SO_SNDBUF",		SOL_SOCKET,	SO_SNDBUF,	sock_str_int},
{"SO_RCVLOWAT",		SOL_SOCKET,	SO_RCVLOWAT,	sock_str_int},
{"SO_SNDLOWAT",		SOL_SOCKET,	SO_SNDLOWAT,	sock_str_int},
#ifdef __CYGWIN__
{"SO_RCVTIMEO",		SOL_SOCKET,	SO_RCVTIMEO,	sock_str_int},
{"SO_SNDTIMEO",		SOL_SOCKET,	SO_SNDTIMEO,	sock_str_int},
#else
{"SO_RCVTIMEO",		SOL_SOCKET,	SO_RCVTIMEO,	sock_str_timeval},
{"SO_SNDTIMEO",		SOL_SOCKET,	SO_SNDTIMEO,	sock_str_timeval},
#endif
{"SO_REUSEADDR",		SOL_SOCKET,	SO_REUSEADDR,	sock_str_flag},
#ifdef	SO_REUSEPORT
{"SO_REUSEPORT",		SOL_SOCKET,	SO_REUSEPORT,	sock_str_flag},
#else
{"SO_REUSEPORT",		0,		0,		NULL},
#endif
{"SO_TYPE",		SOL_SOCKET,	SO_TYPE,	sock_str_int},
{"SO_USELOOPBACK",	SOL_SOCKET,	SO_USELOOPBACK,	sock_str_flag},
{"IP_TOS",		IPPROTO_IP,	IP_TOS,		sock_str_int},
{"IP_TTL",		IPPROTO_IP,	IP_TTL,		sock_str_int},
{"TCP_MAXSEG",		IPPROTO_TCP,    TCP_MAXSEG,	sock_str_int},
{"TCP_NODELAY",		IPPROTO_TCP,    TCP_NODELAY,	sock_str_flag},
{NULL,			0,		0,		NULL}
};


void print_sockopts (int fd)
{
   int len;
   struct sock_opts *ptr;

   for (ptr = sock_opts; ptr->opt_str != NULL; ptr++)
   {
      printf("%s: ", ptr->opt_str);
      if (ptr->opt_val_str == NULL)
         printf("(undefined)\n");
      else
      {
      	 len = sizeof(val);
      	 if (getsockopt(fd, ptr->opt_level, ptr->opt_name, &val, &len) == -1)
            err_ret("getsockopt error");
         else
           printf("default = %s\n", (*ptr->opt_val_str)(&val, len));
      }
   }
}


int main(int argc, char *argv[])
{
   int fd;
   struct sockaddr_in servaddr;
   unsigned long port;
   char *endptr;

   prog = argv[0];

   /* test for a datagram socket */

   fd = Socket(AF_INET, SOCK_DGRAM, 0);
   puts ("\n--- DATAGRAM SOCKET ---\n");
   print_sockopts (fd);
   Close (fd);

   /* test for stream unconnected socket */

   fd = Socket(AF_INET, SOCK_STREAM, 0);
   memset (&servaddr, 0, sizeof(servaddr));
   servaddr.sin_family = AF_INET;
   servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
   servaddr.sin_port = htons(DFL_PORT);
   Bind (fd, (SA*) &servaddr, sizeof(servaddr));
   puts ("\n--- STREAM SOCKET (SERVER) ---\n");
   print_sockopts (fd);
   Close (fd);

   /* test for stream connected socket */

   if (argc != 3)
      err_quit ("usage: %s IP port", prog);
   if ( ((port=strtoul(argv[2],&endptr,10)) == 0) || *endptr)
      err_quit ("port is not a positive integer");
   if (port<1 || port>65535)
      err_quit ("port out of range [1..65535]");

   fd = Socket(AF_INET, SOCK_STREAM, 0);
   memset (&servaddr, 0, sizeof(servaddr));
   servaddr.sin_family = AF_INET;
   servaddr.sin_port = htons((unsigned short)port);
   Inet_pton (AF_INET, argv[1], &servaddr.sin_addr);
   Connect(fd, (SA*) &servaddr, sizeof(servaddr));

   puts ("\n--- STREAM SOCKET (CONNECTED) ---\n");
   print_sockopts (fd);
   Close (fd);

   return 0;
}
