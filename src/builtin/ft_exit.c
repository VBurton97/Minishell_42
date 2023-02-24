/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor <victor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 17:58:31 by sasha             #+#    #+#             */
/*   Updated: 2023/02/24 12:48:50 by victor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

void	ft_exit(t_shell *shell)
{
	ft_delete_lst(&(shell->env_lst));
	ft_delete_lst(&(shell->parsed_input));
	clear_history();
	//delete cmd?
	exit(0);
}
