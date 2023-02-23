/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburton <vburton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 14:00:28 by sasha             #+#    #+#             */
/*   Updated: 2023/02/23 15:22:35 by vburton          ###   ########.fr       */
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
	// int		i;
	// int		j;
	t_shell	shell;
	t_token	*lst_cmd;
	t_cmd	cmd;
	
	// i = 0;
	loop();
	shell.nb_pipe = 0;
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
	// ft_printf("parsed: ");
	// ft_print_lst(shell.parsed_input);
	// ft_printf("\n");
	lst_cmd = ft_get_lst_cmd(shell.parsed_input);
	shell.nb_pipe = get_number_of_pipe(shell.parsed_input);
	shell.env = get_array_env(shell.env_lst);
	cmd.command = ft_get_array_cmd(shell.parsed_input, shell.nb_pipe);
	// int	g = 0;
	// while (cmd.command[g])
	// {
	// 	int	h = 0;
	// 	while (cmd.command[g][h])
	// 	{
	// 		ft_printf("g = %d et cmd = %s\n", g, cmd.command[g][h]);
	// 		h++;
	// 	}
	// 	g++;
	// }

	// ft_print_lst(lst_cmd);
	// i = 0;
	// while (cmd.command[i])
	// {
	// 	j = 0;
	// 	while (cmd.command[i][j])
	// 	{
	// 		ft_printf("%s ", cmd.command[i][j]);
	// 		j++;
	// 	}
	// 	ft_printf("\n");
	// 	i++;
	// }
	// rl_clear_history();
	// printf("\n");
	// ft_get_env(&shell.env_lst);
	// int	i = 0;
	// while (shell.env_lst[i])
	// {
	// 	int y= 0;
	// 	while (shell.env[i][y])
	// 	{
	// 		ft_printf("%s\n", shell.env[i][y]);
	// 		y++;
	// 	}
	// 	i++;
	// }
	ft_exec(&shell, lst_cmd, cmd.command);

	// ft_print_lst(shell.env_lst);
	// i = 0;
	// while (shell.env_lst)
	// {
	// 	ft_printf("%s\n", shell.env_lst->word);
	// 	shell.env_lst = shell.env_lst->next;
	// }
	// ft_print_lst(shell.parsed_input);
	ft_delete_lst(&(shell.parsed_input));
	ft_delete_lst(&(shell.env_lst));
}

