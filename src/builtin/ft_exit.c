/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasha <sasha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 17:58:31 by sasha             #+#    #+#             */
/*   Updated: 2023/02/15 19:05:11 by sasha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

void	ft_exit(t_shell *shell)
{
	ft_delete_lst(&(shell->env_lst));
	ft_delete_lst(&(shell->parsed_input));
	//delete cmd?
	exit(0);
}
