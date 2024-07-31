#include <stdio.h>
#include "errlib.h"

int main (int argc, char *argv[])
{
  FILE *f1, *f2;
  int c;

  if (argc != 3)
    err_quit ("usage: %s file1 file2", argv[0]);

  if ((f1=fopen(argv[1],"rb")) == NULL)
    err_sys ("(%s) error - can't open file '%s'", argv[0], argv[1]);
  if ((f2=fopen(argv[2],"wb")) == NULL)
    err_sys ("(%s) error - can't create file '%s'", argv[0], argv[2]);

  while ((c=fgetc(f1)) != EOF)
    if (fputc (c, f2) == EOF)
      err_sys ("(%s) error - fputc() to file '%s' failed", argv[0], argv[2]);

  if (fclose(f1))
   err_msg ("(%s) warning - can't close file '%s'", argv[0], argv[1]);
  if (fclose(f2))
   err_quit ("(%s) error - can't close file '%s'", argv[0], argv[2]);

  return 0;
}
