#include <stdio.h>
#include <stdlib.h>
#define ASH_RL_BUFSIZE 1024

char *ash_read_line()
{
      int bufsize = ASH_RL_BUFSIZE;
      int position = 0;
      char *buffer = malloc(sizeof(char) * bufsize);
      int c;

      if (!buffer)
      {
            fprintf(stderr, "ash: allocation error\n");
            exit(1);
      }

      while (1)
      {
            c = getchar();

            if (c == EOF || c == '\n')
            {
                  buffer[position] = '\0';
                  return buffer;
            }
            else
            {
                  buffer[position] = c;
            }
            position++;

            if (position >= bufsize)
            {
                  bufsize += ASH_RL_BUFSIZE;
                  buffer = realloc(buffer, bufsize);
                  if (!buffer)
                  {
                        fprintf(stderr, "ash: allocation error\n");
                        exit(1);
                  }
            }
      }
}