/*

module: datasize.c

purpose: print length of basic data types

*/

#include <stdio.h>

int main ()
{
  printf ("|char | = %d byte\n", sizeof(char));
  printf ("|short| = %d byte\n", sizeof(short));
  printf ("|int  | = %d byte\n", sizeof(int));
  printf ("|long | = %d byte\n", sizeof(long));
  printf ("|void*| = %d byte\n", sizeof(void*));
  return 0;
}
