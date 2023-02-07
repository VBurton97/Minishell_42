/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dollar_exps.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasha <sasha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 22:29:44 by sasha             #+#    #+#             */
/*   Updated: 2023/02/07 14:40:33 by sasha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

/*
    content of envp has the form:
    key=value
    if *word has part that's quoted by single quote, no change
    otherwise, every "$key" will be replaced with "value"
    $key is delimited by space or double quote

	the calling function should free word and replace 
	it with the returned new_word
*/
char *ft_dollar_exps(char *word, t_token *env_lst)
{
    int 	quote_state;
    int 	i;
	char	*new_word;

    i = 0;
	quote_state = ft_set_quote_state(word[i], 0);
	new_word = malloc(sizeof(char));
	if (!new_word)
		return (NULL);
	*new_word = '\0';
    while (word[i])
    {
        if (word[i] == '$' && word[i + 1] && quote_state != 1)
        {
            new_word = ft_strjoin_1(new_word, &word, i - 1);
			//printf("hey\n");
            if (!new_word)
                return (NULL);
            new_word = ft_strjoin_2(new_word, &word, env_lst);
			//printf("yo\n");
            if (!new_word)
                return (NULL);
        }
		else
			i++;
		quote_state = ft_set_quote_state(word[i], quote_state);
    }
	new_word = ft_strjoin_1(new_word, &word, i - 1);
	if (!new_word)
        return (NULL);
	return (new_word);
}
