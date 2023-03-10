/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsliu <hsliu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 17:58:31 by sasha             #+#    #+#             */
/*   Updated: 2023/02/27 16:25:31 by hsliu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

void	ft_exit(t_shell *shell)
{
	clear_history();
	ft_free_cmd(shell->cmd, shell->cmd_size);
	exit(0);
}
