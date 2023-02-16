/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburton <vburton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 14:00:28 by sasha             #+#    #+#             */
/*   Updated: 2023/02/16 20:24:19 by vburton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "minishell.h"
#include "exec.h"

void	ft_print_lst(t_token *lst)
{
	if (!lst)
	{
		printf("lst empty\n");
	}
	while (lst)
	{
		printf("%s -> ", lst->word);
		lst = lst->next;
	}
}


int main()
{
	int		i;
	int		j;
	int		nb_cmd;
	t_shell	shell;
	t_token	*lst_cmd;
	t_token *lst_buffer;
	t_cmd	cmd;
	
	i = 0;
	nb_cmd = 0;
	shell.env_lst = NULL;
	if (ft_get_env(&(shell.env_lst)))
	{
		return (0);
	}
	
	char		*buffer;
	buffer = readline("Enter: ");
	if (ft_parsing(buffer, &shell))
	{
		free(buffer);
		ft_delete_lst(&(shell.env_lst));
		write(2, "parsing fails\n", 14);
		return (0);
	}
	free(buffer);
	lst_cmd = ft_get_lst_cmd(shell.parsed_input);
	lst_buffer = ft_get_lst_cmd(shell.parsed_input);
	while (lst_buffer)
	{
		if (ft_strncmp(lst_buffer->word, "|", 1) == 0)
			nb_cmd++;
		ft_printf("%s ", lst_buffer->word);
		lst_buffer = lst_buffer->next;
	}
	cmd.command = ft_get_array_cmd(lst_cmd, nb_cmd);
	ft_print_lst(lst_cmd);
	i = 0;
	while (cmd.command[i])
	{
		j = 0;
		while (cmd.command[i][j])
		{
			ft_printf("%s ", cmd.command[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
	//rl_clear_history();
	printf("\n");
	ft_print_lst(shell.parsed_input);
	ft_delete_lst(&(shell.parsed_input));
	ft_delete_lst(&(shell.env_lst));
}

