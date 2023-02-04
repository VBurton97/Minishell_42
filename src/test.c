/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasha <sasha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 14:00:28 by sasha             #+#    #+#             */
/*   Updated: 2023/02/04 15:51:32 by sasha            ###   ########.fr       */
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
	/*
	char	*buffer;
	t_token	*lst;
	
	buffer = readline("Enter: ");
	lst = ft_line_to_token(buffer);
	free(buffer);
	ft_print_lst(lst);
	printf("\nsyntax error: %d\n", ft_syntax_err(lst));
	*/

	int pipefd[4];
	if (pipe(pipefd))
		write(2, "hey\n", 4);
	else
		write(2, "ok\n", 3);
	if (pipe(pipefd + 2))
		write(2, "hey\n", 4);
	else
		write(2, "ok\n", 3);
}

