/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsliu <hsliu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 13:55:13 by hsliu             #+#    #+#             */
/*   Updated: 2023/02/23 14:15:50 by hsliu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

/*
    return 1 when err
    normally never return
*/
int loop(void)
{
    t_shell shell;
    char    *buffer;

    if (ft_get_env(&(shell.env_lst)))
	{
		return (1);
	}
    while (1)
    {
        buffer = readline("minishell-> ");
        if (buffer == NULL)
            break ;
        if (ft_parsing(buffer, &shell))
	    {
		    ft_delete_lst(&(shell.env_lst));
		    write(2, "parsing fails\n", 14);
	    }
        else
        {
            add_history(buffer);
            //exec
        }
        *buffer = '\0';
        free(buffer);
    }
    ft_exit(&shell);
    return (1);
}