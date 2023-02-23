#include "exec.h"
#include "minishell.h"
#include "parsing.h"

void	ft_open_close_dup(t_token *lst, t_shell *shell, int **fd)
{
	if (ft_strcmp(lst->word, "<") == 0 || ft_strcmp(lst->word, "<<") == 0)
	{
		fd[shell->i][0] = ft_read_file(lst, lst->word);
		dup2(fd[shell->i][0], STDIN_FILENO);
		close(fd[shell->i][0]);
	}
	if (ft_strcmp(lst->word, ">") == 0 || ft_strcmp(lst->word, ">>") == 0)
	{
		fd[shell->i][1] = ft_write_file(lst, lst->word);
		dup2(fd[shell->i][1], STDOUT_FILENO);
		close(fd[shell->i][1]);
	}
}

int	**ft_init_fd(int nb_pipe)
{
	int	i;
	int	**fd;

	i = 0;
	fd = malloc(sizeof(int *) * (nb_pipe + 1));
	if (!fd)
		return (NULL);
	while (i < nb_pipe + 1)
	{
		fd[i] = malloc(sizeof(int) * 2);
		i++;
	}
	i = 0;
	while (i < nb_pipe + 1)
	{
		fd[i][0] = 0;
		fd[i][1] = 1;
		i++;
	}
	return (fd);
}

void	ft_close_fd(int **fd, t_shell *shell)
{
	int	i;

	i = 0;
	while (i < shell->i)
	{
		close(fd[i][0]);
		close(fd[i][1]);
		i++;
	}
	if (i == shell->nb_pipe)
	{
		close(fd[i][0]);
		close(fd[i][1]);
	}
}