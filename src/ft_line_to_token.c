/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line_to_token.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasha <sasha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 12:36:25 by sasha             #+#    #+#             */
/*   Updated: 2023/02/04 15:41:52 by sasha            ###   ########.fr       */
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
	check the lst for syntax error
	for example:
	cmd1 | cmd2 | (missing cmd)
	| cmd1 | cmd2 (missing cmd)
	cmd > (missing outfput file)
	cmd < (missing input file)
	the function will check the token after the operator,
	if the token after is also an operator,
	then there's an syntax error
	otherwise, the word will be taken as filename or cmd
	Note: command like
	cmd | cmd | > outfile 
	is valid in bash
*/
int	ft_syntax_err(t_token *lst)
{
	if (!lst)
		return (0);
	if (ft_strncmp(lst->word, "|", 2) == 0)
	{
		write(2, "syntax error\n", 13);
		return (1);
	}
	while (lst->next)
	{
		if (ft_is_operator(lst->word) && ft_is_operator(lst->next->word))
		{
			write(2, "syntax error\n", 13);
			return (1);
		}
		lst = lst->next;
	}
	if (ft_is_operator(lst->word))
	{
		write(2, "syntax error\n", 13);
		return (1);
	}
	return (0);
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
