#include "exec.h"
#include "minishell.h"
#include "parsing.h"

int	ft_here_doc(t_pipex *pipex)
{
	int		fd[2];
	int		pid;

	if (pipe(fd) == -1)
		return (1);
	pid = fork();
	if (pid == -1)
		perror("An error as occured while attempting to fork");
	if (pid == 0)
		fils_here_doc(pipex, fd);
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		waitpid(pid, NULL, 0);
	}
	return (0);
}

void	fils_here_doc(t_pipex *pipex, int	*fd)
{
	char	*next_line;

	close (fd[0]);
	write(1, "pipe heredoc>", 13);
	while (1)
	{
		next_line = get_next_line(STDIN_FILENO);
		if (!next_line || ft_strcmp(next_line, pipex->limiter) == 0)
		{
			free(next_line);
			close (fd[1]);
			break ;
		}
		write(1, "pipe heredoc>", 13);
		write(fd[1], next_line, ft_strlen(next_line));
		write(fd[1], "\n", 1);
		free(next_line);
	}
	free(pipex->limiter);
	pipex->limiter = NULL;
	close (fd[1]);
	exit(0);
}
