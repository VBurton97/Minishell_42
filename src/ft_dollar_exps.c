/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dollar_exps.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasha <sasha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 22:29:44 by sasha             #+#    #+#             */
/*   Updated: 2023/02/05 18:07:43 by sasha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

/*
    content of envp has the form:
    key=value
    if *word has part that's quoted by single quote, no change
    otherwise, every "$key" will be replaced with "value"
    $key is delimited by space or double quote
*/
char *ft_dollar_exps(char *word, char **envp)
{
    int 	quote_state;
    int 	i;
	char	*new_word;

    quote_state = 0;
    i = 0;
    while (*word)
    {
        //if (ft_is_dollar && quote_state != 1)
        //	strjoin everything before (start from word[j])
        //	strjoin env para
        //	advance j accordingly
        //else if meet a quote 
		//	change quote state (note: quote might be within quote)
        //else
		//  word++;
    }
	//if word[i] is not \0
	//	strjoin the rest
}


/*
    return new string, which concatenate new with old
    old string have size n
*/
char    *ft_strjoin_exps(char *new, char *old, int n)
{
    
}
