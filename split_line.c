#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ASH_TOK_BUFSIZE 64
#define ASH_TOK_DELIM " \t\r\n\a"

char **ash_split_line(char *line)
{
      int bufsize = ASH_TOK_BUFSIZE, position = 0;
      char **tokens = malloc(sizeof(char *) * bufsize);
      char *token;

      if (!tokens)
      {
            fprintf(stderr, "ash: allocation error\n");
            exit(1);
      }

      token = strtok(line, ASH_TOK_DELIM);
      while (token != NULL)
      {
            tokens[position] = token;
            position++;

            // reallocating a bigger buffer if current one is filled
            if (position >= bufsize)
            {
                  bufsize += ASH_TOK_BUFSIZE;
                  tokens = realloc(tokens, bufsize);

                  if (!tokens)
                  {
                        fprintf(stderr, "ash: allocation error\n");
                        exit(1);
                  }
            }

            token = strtok(NULL, ASH_TOK_DELIM);
      }

      tokens[position] = NULL;
      return tokens;
}