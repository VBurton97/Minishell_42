#include "parsing.h"
#include "minishell.h"
#include "exec.h"
#include "builtin.h"

void	ft_exec(t_shell *shell, t_token lst, char ***cmd, int nb_pipe)
{
	if (nb_pipe == 0)
		no_pipe(shell, lst, cmd);
}

void	no_pipe(t_shell *shell, t_token lst, char ***cmd)
{
	int	input;
	int	output;

	input = 0;
	output = 1;
	if (exec_builtin(shell, cmd[0]) == 1)
		return ;
	else
	{
		while (lst)
		{
			if (ft_is_file_operator(lst.word) == 1)
				ft_open_file(lst.next->word, lst.word);
			
		}
	}
	
}

void ft_remove_elem_lst(t_token *lst)
{
	
}