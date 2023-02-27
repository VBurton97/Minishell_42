/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsliu <hsliu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 22:41:29 by sasha             #+#    #+#             */
/*   Updated: 2023/02/27 13:52:34 by hsliu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static void	ft_free_cmd(t_cmd *cmd, int size);

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
		ft_delete_lst(&lst);
		return (1);
	}
	if (ft_exps_and_split(&lst, shell->env_lst))
	{
		ft_delete_lst(&lst);
		return (1);
	}
	cmd = t_get_cmd(lst, &(shell->cmd_size));
	ft_redirect(&lst, cmd, shell->cmd_size);
	if (ft_init_command(lst, cmd, shell->cmd_size))
	{
		ft_free_cmd(cmd, shell->cmd_size);
		ft_delete_lst(&lst);
		return (1);
	}
	ft_delete_lst(&lst);
	shell->cmd = cmd;
	return (0);
}

static void	ft_free_cmd(t_cmd *cmd, int size)
{
	int	i;
	int	j;

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
}
