#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[])
{ 
  char *envvar;

  if (argc<2)
  {
    fprintf (stderr, "Usage: %s env_var_name\n", argv[0]);
    exit (1);	    			
  } 
  if ((envvar=getenv(argv[1])) == NULL)
  {
    printf ("Undefined environment variable '%s'\n", argv[1]);
    exit (2);	    			
  }
  printf ("Environment variable:\n");
  printf ("- NAME: %s\n- VALUE: %s\n", argv[1], envvar);
  exit (0);
}
