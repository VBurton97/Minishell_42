/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tilde_exps.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsliu <hsliu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 12:52:44 by hsliu             #+#    #+#             */
/*   Updated: 2023/02/09 13:06:50 by hsliu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int ft_tilde_exps_lst(t_token *lst, t_token *env_lst)
{
    char    *new_word;
    
    while(lst)
    {
        if (*(lst->word) == '~')
        {
            new_word = ft_tilde_exps(lst->word, env_lst);
            if (!new_word)
            {
                return (1);
            }
            free(lst->word);
            lst->word = new_word;
        }
        lst = lst->next;
    }
    return (0);
}