#include "pipe_x.h"

int	main(int c, char **v, char **envp)
{
    if (c == 0 && v)
        return (0);
    char *argv[] = {"pipex", "infile", "cat", "wc -l", "outfile"};
	return (pipe_x(5, argv, envp, true));
}