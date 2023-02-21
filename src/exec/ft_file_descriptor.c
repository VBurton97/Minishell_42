#include "exec.h"
#include "minishell.h"
#include "parsing.h"

void	ft_open_close_dup(t_token *lst, int fd[2])
{
	if (ft_strcmp(lst->word, "<") == 0 || ft_strcmp(lst->word, "<<") == 0)
	{
		fd[0] = ft_read_file(lst, lst->word);
		// dup2(fd[0], STDIN_FILENO);
		// close(fd[0]);
	}
	else if (ft_strcmp(lst->word, ">") == 0 || ft_strcmp(lst->word, ">>") == 0)
	{
		fd[1] = ft_write_file(lst, lst->word);
		// dup2(fd[1], STDOUT_FILENO);
		// close(fd[1]);
	}
}
