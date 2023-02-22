#include "parsing.h"
#include "minishell.h"
#include "exec.h"
#include "builtin.h"

void	childs(t_shell *shell, char **cmd, int fd[2]);

int	first_cmds(t_shell *shell, char **cmd, int fd[2])
{
	if (pipe(fd) == -1)
		perror("An error as occured while creating the pipe");
	while (shell->parsed_input && ft_strcmp(shell->parsed_input->word, "|") != 0)
	{
		ft_open_close_dup(shell->parsed_input, fd);
		shell->parsed_input = shell->parsed_input->next;
	}
	if (shell->i < shell->nb_pipe)	
		shell->parsed_input = shell->parsed_input->next;
	shell->path_cmd = ft_final_path(cmd, shell->env);
	shell->pid[shell->i] = fork();
	if (shell->pid[shell->i] == -1)
		perror(": fork failed\n");
	childs(shell, cmd, fd);
	shell->i++;
	return (0);
}

void	childs(t_shell *shell, char **cmd, int fd[2])
{
	if (shell->pid[shell->i] == 0)
	{
		close(fd[0]);
		if (dup2(fd[1], STDOUT_FILENO) == -1)
			ft_printf("Error while duplicating et i = %d\n", shell->i);
		close(fd[1]);
		execve(shell->path_cmd, cmd, NULL);
		exit(0);
	}
	else
	{
		close(fd[1]);
		if (dup2(fd[0], STDIN_FILENO) == -1)
			ft_printf("Error while duplicatinget i = %d\n", shell->i);
		close(fd[0]);
		if (shell->path_cmd != NULL)
			free(shell->path_cmd);
	}
}