/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsliu <hsliu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 14:00:28 by sasha             #+#    #+#             */
/*   Updated: 2023/02/09 13:28:55 by hsliu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

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
	t_shell		shell;
	
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
		ft_delete_lst(&(shell.parsed_input));
		ft_delete_lst(&(shell.env_lst));
		return (0);
	}
	free(buffer);
	rl_clear_history();
	ft_print_lst(shell.parsed_input);
	printf("\n");
	ft_delete_lst(&(shell.parsed_input));
	ft_delete_lst(&(shell.env_lst));
}

