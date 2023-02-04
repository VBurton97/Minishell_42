/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasha <sasha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 22:41:29 by sasha             #+#    #+#             */
/*   Updated: 2023/02/04 23:07:43 by sasha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

/*
    return 0
    return 1 when err
*/
int ft_parsing(char *buffer, t_shell *shell)
{
	t_token *lst;
	t_cmd	*cmd;

	lst = ft_line_to_token(buffer);
	if (!lst || ft_syntax_err(lst))
	{
		//delete lst
		return (1);
	}
	cmd = ft_get_cmd(lst);
	if (cmd == NULL)
	{
		//delete lst
		return (1);
	}
	//redirection
	//word expansion(tild; env para; splitting; wild card; rm quote)
	//finish init cmd
	shell->parsed_input = lst;
	shell->cmd = cmd;
	return (0);
}