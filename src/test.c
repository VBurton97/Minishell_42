/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasha <sasha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 14:00:28 by sasha             #+#    #+#             */
/*   Updated: 2023/02/03 16:10:31 by sasha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	ft_print_lst(t_token *lst)
{
	while (lst)
	{
		printf("%s -> ", lst->word);
		lst = lst->next;
	}
}

int main()
{
	char	*buffer;
	t_token	*lst;
	
	buffer = readline("Enter: ");
	lst = ft_line_to_token(buffer);
	ft_print_lst(lst);
	free(buffer);
}

