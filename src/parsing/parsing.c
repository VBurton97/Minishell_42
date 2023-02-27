/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsliu <hsliu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 22:41:29 by sasha             #+#    #+#             */
/*   Updated: 2023/02/27 16:59:46 by hsliu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

/*
    return 0
    return 1 when err
*/
int	ft_parsing(char *buffer, t_shell *shell)
{
	t_token	*lst;
	t_cmd	*cmd;

	lst = ft_line_to_token(buffer);
	if (!lst || ft_syntax_err(lst))
	{
		return (ft_delete_lst(&lst), 1);
	}
	if (ft_exps_and_split(&lst, shell->env_lst))
	{
		return (ft_delete_lst(&lst), 1);
	}
	cmd = ft_get_cmd(lst, &(shell->cmd_size));
	if (cmd == NULL)
	{
		return (ft_delete_lst(&lst), 1);
	}
	ft_redirect(&lst, cmd, shell->cmd_size);
	if (ft_init_command(lst, cmd, shell->cmd_size))
	{
		ft_free_cmd(cmd, shell->cmd_size);
		return (ft_delete_lst(&lst), 1);
	}
	shell->cmd = cmd;
	return (ft_delete_lst(&lst), 0);
}

void	ft_free_cmd(t_cmd *cmd, int size)
{
	int	i;
	int	j;

	if (cmd == NULL)
		return ;
	i = 0;
	while (i < size)
	{
		if (cmd[i].command == NULL)
			;
		else
		{
			j = 0;
			while (cmd[i].command[j])
			{
				free(cmd[i].command[j]);
				j++;
			}
			free(cmd[i].command);
		}
		i++;
	}
	free(cmd);
}
