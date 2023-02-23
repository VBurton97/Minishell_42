/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsliu <hsliu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 17:58:31 by sasha             #+#    #+#             */
/*   Updated: 2023/02/23 14:14:32 by hsliu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

void	ft_exit(t_shell *shell)
{
	ft_delete_lst(&(shell->env_lst));
	ft_delete_lst(&(shell->parsed_input));
	rl_clear_history();
	//delete cmd?
	exit(0);
}
