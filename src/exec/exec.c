#include "parsing.h"
#include "minishell.h"
#include "exec.h"
#include "builtin.h"

void	no_pipe(t_shell *shell, t_token *lst, char ***cmd, int fd[2]);

void	ft_exec(t_shell *shell, t_token *lst, char ***cmd)
{
	int	fd[2];
	int	save_stdout;
	int	save_stdin;

	fd[0] = 0;
	fd[1] = 1;
	shell->i = 0;
	save_stdout = dup(STDOUT_FILENO);
	save_stdin = dup(STDIN_FILENO);
	if (shell->nb_pipe == 0)
	{
		while (shell->parsed_input)
		{
			ft_open_close_dup(shell->parsed_input, fd);
			shell->parsed_input = shell->parsed_input->next;
		}
		if (dup2(fd[1], STDOUT_FILENO) == -1)
			ft_printf("Error while duplicating et i = %d\n", shell->i);
		if (dup2(fd[0], STDIN_FILENO) == -1)
			ft_printf("Error while duplicatinget i = %d\n", shell->i);
		no_pipe(shell, lst, cmd, fd);
		close(fd[1]);
		close(fd[0]);
	}
	else
	{
		shell->pid = malloc(sizeof(int) * shell->nb_pipe);
		while (shell->i <= shell->nb_pipe)
			first_cmds(shell, cmd[shell->i], fd);
		shell->i = 0;
		while (shell->i < shell->nb_pipe)
		{
			waitpid(shell->pid[shell->i], NULL, 0);
			shell->i++;
		}
	}
	dup2(save_stdout, STDOUT_FILENO);
	dup2(save_stdin, STDIN_FILENO);
	close(save_stdout);
	close(save_stdin);
}

void	no_pipe(t_shell *shell, t_token *lst, char ***cmd, int fd[2])
{
	char	*cmd_path;

	cmd_path = NULL;
	if (exec_builtin(shell, cmd[0]) == 1)
		return ;
	else
	{
		while (lst)
		{
			ft_open_close_dup(lst, fd);
			cmd_path = ft_final_path(cmd[0], shell->env);
			if (cmd_path == NULL)
				return ;
			lst = lst->next;
		}
		execve(cmd_path, cmd[0], NULL);
		exit(0);
	}
}
