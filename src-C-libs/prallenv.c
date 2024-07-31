#include <stdio.h>
#include <string.h>

#define SEPARATOR "="

int main (int argc, char *argv[], char *envp[])
{
  int i;
  char *token;

  printf ("List of defined environment variables:\n");

  for (i=0; envp[i]!=NULL; i++) {

    /* name of environment variable */

    if ((token = strtok (envp[i], SEPARATOR)) == NULL) {
      fprintf(stderr, "(%s) envp[] bug - name of env var is null", argv[0]);
      return 1;
    }
    printf ("- %s = ", token);

    /* value of environment variable */

    if ((token = strtok (NULL, SEPARATOR)) != NULL)
      printf ("%s\n", token);
    else
      putchar ('\n');
  }
  return 0;
}
