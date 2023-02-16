/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburton <vburton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 15:50:54 by vburton           #+#    #+#             */
/*   Updated: 2023/02/16 19:39:54 by vburton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "minishell.h"
#include "exec.h"

t_token	*ft_get_lst_cmd(t_token	*lst)
{
	int			i;
	t_token	*lst_cmd;
	t_token *buffer;

	i = 0;
	lst_cmd = malloc(sizeof(t_token));
	while (lst)
	{
		if (lst && ft_is_operator(lst->word) != 0)
		{
			if (ft_is_operator(lst->word) == 1 && ft_strncmp(lst->word, "|", 1) == 0)
			{
				lst_cmd->next = ft_new_token(lst->word, ft_strlen(lst->word));
				lst_cmd = lst_cmd->next;
				lst = lst->next;
			}
			else
			{
				lst = lst->next;
				lst = lst->next;
			}
		}
		while (lst && ft_is_operator(lst->word) == 0)
		{
			if (i == 0)
			{
				lst_cmd->word = lst->word;
				buffer = lst_cmd;
				i++;
			}
			else
			{
				lst_cmd->next = ft_new_token(lst->word, ft_strlen(lst->word));
				lst_cmd = lst_cmd->next;
			}
			lst = lst->next;
		}
	}
	return (buffer);
}

char	***ft_get_array_cmd(t_token *lst, int nb_cmd)
{
	int i;
	int	j;
	int	nb_arg;
	char	***cmd;
	t_token	*buffer;

	i = 0;
	buffer = lst;
	cmd = malloc(sizeof(char **) * (nb_cmd + 2));
	while (i <= nb_cmd)
	{
		j = 0;
		nb_arg = 0;
		while (buffer && ft_strncmp(buffer->word, "|", 1) != 0)
		{
			nb_arg++;
			buffer = buffer->next;
		}
		if (buffer && ft_strncmp(buffer->word, "|", 1) == 0)
			buffer = buffer->next;
		cmd[i] = malloc(sizeof(char *) * (nb_arg + 1));
		while (lst && ft_strncmp(lst->word, "|", 1) != 0)
		{
			cmd[i][j] = ft_strdup(lst->word);
			lst = lst->next;
			j++;
		}
		if (lst && ft_strncmp(lst->word, "|", 1) == 0)
			lst = lst->next;
		cmd[i][j] = NULL;
		i++;
	}
	cmd[i] = NULL;
	return (cmd);
}

int	get_number_of_pipe(t_token	*lst)
{
	int	nb;

	while (lst)
	{
		if (ft_is_operator(lst->word) == 1 && ft_strncmp(lst->word, "|", 1) == 0)
			nb++;
		lst = lst->next;
	}
	return (nb);
}

// void	ft_exec(t_token *lst)
// {
// 	int	i;
// 	int	fd[2];
// 	char	*final_path;
// 	t_cmd cmd;
// 	t_token *lst_cmd;
// 	t_token *buffer_lst;
// 	t_token *buffer_lst_cmd;

// 	lst_cmd = ft_get_cmd(lst);
// 	buffer_lst = lst;
// 	buffer_lst_cmd = lst_cmd;
// 	cmd = ft_get_array_cmd(lst_cmd);
// 	if (ft_strncmp(buffer_lst->word, "<", 1))
// 	{
// 		cmd.read_fd = open(buffer_lst->next->word, O_RDONLY); 
// 		dup2(cmd.read_fd, STDIN_FILENO);
// 		close(cmd.read_fd);
// 		buffer_lst = buffer_lst->next;
// 	}
// 	while (buffer_lst && ft_strncmp(buffer_lst->word, "|", 1) != 0)
// 	{
// 		if (ft_strncmp(buffer_lst->word, ">", 1) == 0)
// 		{
// 			cmd.write_fd = open(buffer_lst->next->word, O_WRONLY);
// 			dup2(cmd.write_fd, STDOUT_FILENO);
// 			close(cmd.write_fd);
// 		}
// 		buffer_lst = buffer_lst->next;
// 	}
// 	final_path = get_
// }