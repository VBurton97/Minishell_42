/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exps_and_split.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsliu <hsliu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 12:43:52 by hsliu             #+#    #+#             */
/*   Updated: 2023/02/09 13:08:08 by hsliu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	ft_exps_and_split(t_token *lst, t_token *env_lst)
{
    if (ft_dollar_exps_lst(lst, env_lst))
    {
        write(2, "exps fails\n", 11);
	   return (1);
    }
	if (ft_tilde_exps_lst(lst, env_lst))
    {
        write(2, "exps fails\n", 11);
	   return (1);
    }
    return (0);
}