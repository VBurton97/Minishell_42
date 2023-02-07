/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasha <sasha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 14:00:28 by sasha             #+#    #+#             */
/*   Updated: 2023/02/07 15:53:10 by sasha            ###   ########.fr       */
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
		return (0);
	}
	free(buffer);
	ft_print_lst(shell.parsed_input);
	printf("\n");
	if (ft_dollar_exps_lst(shell.parsed_input, shell.env_lst))
		write(2, "exps fails\n", 11);
	ft_print_lst(shell.parsed_input);
	printf("\n");
	ft_delete_lst(&(shell.parsed_input));
}
