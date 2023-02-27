/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburton <vburton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 14:00:28 by sasha             #+#    #+#             */
/*   Updated: 2023/02/27 14:40:37 by vburton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "minishell.h"
#include "exec.h"

void	ft_print_lst(t_token *lst)
{
	if (!lst)
	{
		printf("lst empty\n");
	}
	while (lst)
	{
		printf("%s -> ", lst->word);
		lst = lst->next;
	}
}

void	ft_print_cmd(t_cmd *cmd, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		printf("\ncmd %d: ", i);
		j = 0;
		while (cmd[i].command && cmd[i].command[j])
		{
			printf("%s ", cmd[i].command[j]);
			j++;
		}
		i++;
	}
}


int main()
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
		    write(2, "parsing fails\n", 14);
        else
        {
            add_history(buffer);
			ft_print_cmd(shell.cmd, shell.cmd_size);
        }
        //delete cmd
        *buffer = '\0';
        free(buffer);
    }
    ft_exit(&shell);
    return (1);
}

