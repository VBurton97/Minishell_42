/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_to_token_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsliu <hsliu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 14:25:00 by sasha             #+#    #+#             */
/*   Updated: 2023/02/10 13:37:57 by hsliu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

/*
	calling this function will return the token 
	of buffer[0 ... length - 1]
	buffer pointer will advance accordingly
	return NULL if malloc fails
*/
t_token	*ft_is_token(char **buffer, int length)
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
	examples of word:
	Hello
	"Hello"
	"He"llo
	He"llo"
	He"ll"o
	a word is delimitted by an operator or space (unquoted of course)
	this function return the length of word, quote included
	if quote is not closed, return -1 
*/
int	ft_is_word(char *buffer)
{
	int	i;
	int	quote_state;

	i = 0;
	quote_state = 0;
	while (buffer[i])
	{
		quote_state = ft_set_quote_state(buffer[i], quote_state);
		if (buffer[i] == ' ' && quote_state == 0)
			break ;
		else if (ft_is_operator(buffer + i) && quote_state == 0)
			break ;
		i++;
	}
	if (buffer[i] == '\0' && quote_state != 0)
		return (-1);
	return (i);
}

/*
    c is a char in the buffer
    quote_state is the current quote state
    should return the new quote_state
	return the same quote_state if c is not a quote
*/
int	ft_set_quote_state(char c, int quote_state)
{
	if (c == '\'' && quote_state == 0)
		quote_state = 1;
	else if (c == '\'' && quote_state == 1)
		quote_state = 0;
	else if (c == '\"' && quote_state == 0)
		quote_state = 2;
	else if (c == '\"' && quote_state == 2)
		quote_state = 0;
	return (quote_state);
}
