/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tilde_exps.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsliu <hsliu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 12:52:44 by hsliu             #+#    #+#             */
/*   Updated: 2023/02/10 12:13:40 by hsliu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

/*
    do not expand if it is an heredoc
    return 1 when error, the calling fun then should delete the lst
*/
int ft_tilde_exps_lst(t_token *lst, t_token *env_lst)
{
    char    *new_word;
    
    while(lst)
    {
        if (*(lst->word) == '~')
        {
            if (lst->prev && ft_strncmp(lst->prev->word, "<<", 3) == 0)
				;
			else
			{
				new_word = ft_tilde_exps(lst->word, env_lst);
				if (!new_word)
				{
					return (1);
				}
            	free(lst->word);
            	lst->word = new_word;
			}
		}
        lst = lst->next;
    }
    return (0);
}
