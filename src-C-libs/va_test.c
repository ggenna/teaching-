#include <stdio.h>
#include <stdarg.h>

void my_printf (const char *fmt, ...)
{
  va_list ap;

  printf ("(MY_PRINTF) ");
  va_start (ap, fmt);
  vprintf (fmt, ap);
  va_end (ap);
  fflush (stdout);
}

int main ()
{
  int x = 100;
  float y = 12.34;

  my_printf ("%d + %f = %f\n", x, y, x+y);

  return 0;
}
