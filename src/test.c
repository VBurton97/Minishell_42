/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasha <sasha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 14:00:28 by sasha             #+#    #+#             */
/*   Updated: 2023/02/04 22:24:29 by sasha            ###   ########.fr       */
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
	extern char **environ;
	t_shell		shell;

	shell.env = environ;
	
	char		*buffer;

	buffer = readline("Enter: ");
	if (ft_parsing(buffer, &shell))
	{
		return (0);
	}
	free(buffer);
	ft_print_lst(shell.parsed_input);
	printf("\n");
}

