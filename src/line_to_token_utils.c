/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_to_token_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasha <sasha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 14:25:00 by sasha             #+#    #+#             */
/*   Updated: 2023/02/03 16:20:55 by sasha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

/*
	calling this function will return the token 
	of buffer[0 ... length - 1]
	buffer pointer will advance accordingly
	return NULL if malloc fails
*/
t_token	*ft_get_token(char **buffer, int length)
{
	t_token	*token;

	token = ft_new_token(*buffer, length);
	(*buffer) = (*buffer) + length;
	return (token);
}

/*
    return 0 if it's not an operator
	return 1 if it's an operator of length 1
	return 2 if it's an operator of length 2
*/
int	ft_is_operator(char *buffer)
{
	if (ft_strncmp(buffer, "<<", 2) == 0)
		return (2);
    if (ft_strncmp(buffer, ">>", 2) == 0)
		return (2);
	if (ft_strncmp(buffer, "<", 1) == 0)
		return (1);
	if (ft_strncmp(buffer, ">", 1) == 0)
		return (1);
	if (ft_strncmp(buffer, "|", 1) == 0)
		return (1);
	return (0);
}

/*
	return 0 if the first char is not a quote
	if buffer = "12345"
	the function will return 7 (12345 plus the two quote)
	return -1 if the quote is not closed
*/
int	ft_is_quote(char *buffer)
{
	int	i;

	i = 1;
	if (buffer[0] == '\'')
	{
		while (buffer[i] && buffer[i] != '\'')	
			i++;
		if (buffer[i] == '\0')
			return (-1);
		return (i + 1);
	}
	if (buffer[0] == '\"')
	{
		while (buffer[i] && buffer[i] != '\"')	
			i++;
		if (buffer[i] == '\0')
			return (-1);
		return (i + 1);
	}
	return (0);
}

/*
	if the token is neither an operator, a quote, a space
	then it is a word
	from the start of the buffer, the function will advance
	until it meet a an operator, a quote, or a space
	and then return the length of word
*/
int	ft_is_word(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i] && buffer[i] != ' ' && 
		!ft_is_operator(buffer + i) && !ft_is_quote(buffer + i))
	{
		i++;
	}
	return (i);
}
