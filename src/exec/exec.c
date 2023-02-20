#include "parsing.h"
#include "minishell.h"
#include "exec.h"
#include "builtin.h"

void	no_pipe(t_shell *shell, t_token *lst, char ***cmd);

void	ft_exec(t_shell *shell, t_token *lst, char ***cmd, int nb_pipe)
{
	if (nb_pipe == 0)
		no_pipe(shell, lst, cmd);
}

void	no_pipe(t_shell *shell, t_token *lst, char ***cmd)
{
	int		input;
	int		output;
	char	*cmd_path;

	input = 0;
	output = 1;
	if (exec_builtin(shell, cmd[0]) == 1)
		return ;
	else
	{
		while (lst)
		{
			if (ft_strcmp(lst->word, "<") == 0 || ft_strcmp(lst->word, "<<"))
			{
				input = ft_read_file(lst, lst->word);
				dup2(input, STDIN_FILENO);
				close(input);
			}
			else if (ft_strcmp(lst->word, ">") == 0 || ft_strcmp(lst->word, ">>"))
			{
				output = ft_write_file(lst, lst->word);
				dup2(output, STDOUT_FILENO);
				close(output);
			}
			cmd_path = ft_final_path(cmd[0], shell->env);
			if (cmd_path == NULL)
				return ;
		}
		execve(cmd_path, cmd[0], NULL);
		exit(0);
	}
	
}

// void ft_remove_elem_lst(t_token *lst)
// {
	
// }