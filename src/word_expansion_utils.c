/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_expansion_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasha <sasha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 22:29:44 by sasha             #+#    #+#             */
/*   Updated: 2023/02/04 23:18:49 by sasha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/*
    content of envp has the form:
    key=value
    if *word has part that's quoted by single quote, no change
    otherwise, every "$key" will be replaced with "value"
    $key is delimited by space or double quote
*/
char *ft_dollar_exps(char *word, char **envp)
{
    int quote_state;
    int i;
	int	j;

    quote_state = 0;
    i = 0;
	j = 0;
    while (word[i])
    {
        //if (ft_is_dollar && quote_state != 1)
        //	strjoin everything before (start from word[j])
        //	strjoin env para
        //	advance j accordingly
        //else if meet a quote 
		//	change quote state (note: quote might be within quote)
        //else
		//  i++
    }
	//if (j < i)
	//	strjoin the rest
}