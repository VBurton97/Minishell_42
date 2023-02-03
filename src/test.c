/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasha <sasha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 14:00:28 by sasha             #+#    #+#             */
/*   Updated: 2023/02/03 14:19:04 by sasha            ###   ########.fr       */
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
    int     i;
    t_token *token;
    t_token	*lst;
	
    i = 0;
    lst = NULL;
	while (i < 10)
    {
		token = ft_new_token("Hey", 3);
		ft_add_token(&lst, token);
        i++;
    }
	ft_print_lst(lst);
	ft_delete_lst(&lst);
	if (!lst)
	{
		printf("\nlst empty\n");
	}
}

