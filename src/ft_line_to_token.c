/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line_to_token.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasha <sasha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 12:36:25 by sasha             #+#    #+#             */
/*   Updated: 2023/02/03 16:23:53 by sasha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

t_token	*ft_line_to_token(char *buffer)
{
	t_token	*lst;
	t_token	*token;

	lst = NULL;
	while (*buffer)
	{
		while (*buffer == ' ')
			buffer++;
		if (*buffer == '\0')
			break;
		token = ft_is_token(&buffer);
		if (!token)
		{
			return (ft_delete_lst(&lst), NULL);
		}
		ft_add_token(&lst, token);
	}
	return (lst);
}

/*
	return the next token
	In case of error return NULL, ex:
    if malloc fails
    if quote not enclosed
*/
t_token *ft_is_token(char **buffer)
{
	t_token	*token;
	int		length;

	if (ft_is_operator(*buffer))
	{
		length = ft_is_operator(*buffer);
		token = ft_get_token(buffer, length);
	}
	else if (ft_is_quote(*buffer))
	{
		length = ft_is_quote(*buffer);
		if (length == -1)
		{
			write(2, "quote not enclosed\n", 19);
			return (NULL);
		}
		token = ft_get_token(buffer, length);
	}
    else if (ft_is_word(*buffer))
	{
		length = ft_is_word(*buffer);
		token = ft_get_token(buffer, length);
	}
	return (token);
}
