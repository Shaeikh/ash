#include <stdio.h>
#include <stdlib.h>

void ash_loop();

char *ash_read_line();
char **ash_split_line(char *line);
int ash_execute(char **args);

int main(int argc, char **argv)
{
      ash_loop();

      return 0;
}

void ash_loop()
{
      char *line;
      char **args;
      int status;

      do
      {
            printf("ASH > ");
            line = ash_read_line();
            args = ash_split_line(line);
            status = ash_execute(args);

            free(line);
            free(args);
      } while (status);
}
