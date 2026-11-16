#include <string.h>

int ash_num_builtins();
extern char *builtin_str[];
extern int (*builtin_func[]) (char **);
int ash_launch(char **);

int ash_execute(char **args)
{
    int i;

    if (!args[0])
        return 1;
    
    for (int i = 0; i < ash_num_builtins(); i++)
    {
       if (strcmp(args[0], builtin_str[i]) == 0) 
           return (*builtin_func[i]) (args);
    }

    return ash_launch(args);
}
