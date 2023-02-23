/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsliu <hsliu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 13:55:13 by hsliu             #+#    #+#             */
/*   Updated: 2023/02/23 16:53:15 by hsliu            ###   ########.fr       */
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
    t_token	*lst_cmd;
	t_cmd	cmd;
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
        if (*buffer == '\0')
            ;
        else if (ft_parsing(buffer, &shell))
		    write(2, "parsing fails\n", 14);
        else
        {
            add_history(buffer);
            lst_cmd = ft_get_lst_cmd(shell.parsed_input);
	        shell.nb_pipe = get_number_of_pipe(shell.parsed_input);
	        shell.env = get_array_env(shell.env_lst);
	        cmd.command = ft_get_array_cmd(shell.parsed_input, shell.nb_pipe);
            ft_exec(&shell, lst_cmd, cmd.command);
            ft_delete_lst(&lst_cmd);
        }
        ft_delete_lst(&shell.parsed_input);
        *buffer = '\0';
        free(buffer);
    }
    ft_exit(&shell);
    return (1);
}