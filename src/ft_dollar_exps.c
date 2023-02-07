/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dollar_exps.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasha <sasha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 22:29:44 by sasha             #+#    #+#             */
/*   Updated: 2023/02/07 16:01:55 by sasha            ###   ########.fr       */
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
char	*ft_dollar_exps(char *word, t_token *env_lst)
{
	int		quote_state;
	int		i;
	char	*new_word;

	i = 0;
	quote_state = ft_set_quote_state(word[i], 0);
	new_word = ft_calloc(1, sizeof(char));
	if (!new_word)
		return (NULL);
	while (word[i])
	{
		if (word[i] == '$' && word[i + 1] && quote_state != 1)
		{
			new_word = ft_strjoin_1(new_word, &word, i - 1);
			if (!new_word)
				return (NULL);
			new_word = ft_strjoin_2(new_word, &word, env_lst);
			if (!new_word)
				return (NULL);
			i = 0;
		}
		else
			i++;
		quote_state = ft_set_quote_state(word[i], quote_state);
	}
	return (ft_strjoin_1(new_word, &word, i - 1));
}

/*
	iterate through the lst and apply word expansion to all token
	in case of error, return 1
	the calling function should delete the list
*/
int	ft_dollar_exps_lst(t_token *lst, t_token *env_lst)
{
	char	*exp_word;
	
	while (lst)
	{
		exp_word = ft_dollar_exps(lst->word, env_lst);
		if (!exp_word)
		{
			return (1);
		}
		free(lst->word);
		lst->word = exp_word;
		lst = lst->next;
	}
	return (0);
}