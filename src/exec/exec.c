#include "parsing.h"
#include "minishell.h"
#include "exec.h"
#include "builtin.h"

void	no_pipe(t_shell *shell, t_token *lst, char ***cmd);

void	ft_exec(t_shell *shell, t_token *lst, char ***cmd)
{
	int	**fd;

	ft_printf("nb_pipe = %d\n", shell->nb_pipe);
	fd = ft_init_fd(shell->nb_pipe);
	shell->i = 0;
	if (shell->nb_pipe == 0)
	{
		while (shell->parsed_input)
		{
			ft_open_close_dup(shell->parsed_input, shell, fd);
			shell->parsed_input = shell->parsed_input->next;
		}
		no_pipe(shell, lst, cmd);
	}
	else
	{
		shell->pid = malloc(sizeof(int) * shell->nb_pipe);
		while (shell->i <= shell->nb_pipe)
		{
			first_cmds(shell, cmd[shell->i], fd);
			ft_close_fd(fd, shell);
			shell->i++;
		}
		shell->i = 0;
		while (shell->i < shell->nb_pipe)
		{
			waitpid(shell->pid[shell->i], NULL, 0);
			shell->i++;
		}
	}
	// ft_close_fd(fd, shell);
}

void	no_pipe(t_shell *shell, t_token *lst, char ***cmd)
{
	char	*cmd_path;

	cmd_path = NULL;
	if (exec_builtin(shell, cmd[0]) == 1)
		return ;
	else
	{
		while (lst)
		{
			cmd_path = ft_final_path(cmd[0], shell->env);
			if (cmd_path == NULL)
				return ;
			lst = lst->next;
		}
		execve(cmd_path, cmd[0], NULL);
		exit(0);
	}
}
