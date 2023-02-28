#include "minishell.h"
#include "exec.h"
#include "parsing.h"
#include "builtin.h"

int	exec_builtin(t_shell *shell, char **cmd)
{
	// while (shell->parsed_input && ft_strcmp(shell->parsed_input->word, "|") != 0)
	// {
	// 	ft_open_close_dup(shell->parsed_input, fd);
	// 	shell->parsed_input = shell->parsed_input->next;
	// }
	if (ft_strcmp(cmd[0], "cd") == 0)
		return (ft_cd(cmd, shell));
	else if (ft_strcmp(cmd[0], "echo") == 0)
		return (ft_echo(cmd));
	else if (ft_strcmp(cmd[0], "env") == 0)
		return (ft_env(cmd, shell));
	else if (ft_strcmp(cmd[0], "exit") == 0)
		return (ft_exit(shell));
	else if (ft_strcmp(cmd[0], "export") == 0)
		return (ft_export(cmd, shell));
	else if (ft_strcmp(cmd[0], "pwd") == 0)
		return (ft_pwd(cmd));
	else if (ft_strcmp(cmd[0], "unset") == 0)
		return (ft_unset(cmd, shell));
	return (-1);
}