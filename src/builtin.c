#include <stdio.h>
#include <unistd.h>

int ash_cd(char **args);
int ash_help(char **args);
int ash_exit(char **args);

char *builtin_str[] = {
    "cd",
    "help",
    "exit"
};

int (*builtin_func[]) (char **) = {
    &ash_cd,
    &ash_help,
    &ash_exit
};

int ash_num_builtins()
{
    return sizeof(builtin_str) / sizeof(char *);
}

/*
  function implementations
*/

int ash_cd(char **args)
{
    if (!args[1])
    {
        fprintf(stderr, "ash: expected argument to \"cd\"\n");
    } 
    else 
    {
        if (chdir(args[1]) != 0) 
        {
            perror("ash");
        }
    }
    return 1;
}

int ash_help(char **args)
{
    int i;
    printf("Shaeikh's ASH\n");
    printf("Type program names and arguments, and hit enter.\n");
    printf("The following are built in:\n");


    for (i = 0; i < ash_num_builtins(); i++) {
      printf("  %s\n", builtin_str[i]);
    }

    printf("Use the man command for information on other programs.\n");
    return 1;
}

int ash_exit(char **args)
{
    return 0;
}
