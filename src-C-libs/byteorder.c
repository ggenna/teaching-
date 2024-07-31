/*

module: byteorder.c

purpose: to find out if a node is big-endian or little-endian

reference: Stevens, Unix network programming (2ed), p.67 

*/

#include <stdio.h>

int main ()
{
  union {
    short s;
    char c [ sizeof(short) ];
  } u;

  u.s = 0x0102;

  if (sizeof(short) == 2)
  {
    if (u.c[0]==0x01 && u.c[1]==0x02)
      puts ("big-endian");
    else if (u.c[0]==0x02 && u.c[1]==0x01)
      puts ("little-endian");
    else
      puts ("unknown");
  }
  else
    printf ("can't perform my duty: sizeof(short) = %d != 2\n", sizeof(short));

  return 0;
}
