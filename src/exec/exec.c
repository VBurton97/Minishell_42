#include "parsing.h"
#include "minishell.h"
#include "exec.h"
#include "builtin.h"

void	no_pipe(t_shell *shell);

void	ft_exec(t_shell *shell)
{
	int		*fd;
	int		i;
	t_cmd	*cmd;
	
	// fd = ft_malloc_pipe(shell->nb_pipe);
	/*Ecire une fonction qui met a jour ls tableau des commandes avec les paths des fontion a fournir a execve
	+ verifier si builtin ou pas*/
	cmd = shell->cmd;
	// ft_set_pipe(cmd, shell->nb_pipe, fd);
	i = 0;
	if (cmd->size == 1 && exec_builtin(shell, cmd->args) != -1)
		return ;
	while (i < cmd->size)
	{
		ft_open_close_dup(cmd + i);
		first_cmds(cmd + i, shell->env);
		i++;
	}
	ft_printf("%s\n", cmd->args[0]);
}
