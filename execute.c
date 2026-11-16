#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>

int lsh_launch(char **args)
{
      pid_t pid, wpid;
      int status;

      pid = fork();
      if (pid == 0)
      {
            // child process
            if (execvp(args[0], args) == -1)
            {
                  perror("ash");
            }
            exit(1);
      }
      else if (pid < 0)
      {
            // error occured while forking
            perror("ash");
      }
      else
      {
            // parent process
            do
            {
                  wpid = waitpid(pid, &status, WUNTRACED);
            } while (!WIFEXITED(status) && !WIFSIGNALED(status));
      }
}