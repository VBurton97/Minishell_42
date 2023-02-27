/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsliu <hsliu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 12:19:25 by hsliu             #+#    #+#             */
/*   Updated: 2023/02/27 14:18:45 by hsliu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

/*
	cmd is an array of length 'size' 
*/
void	ft_redirect(t_token **lst, t_cmd *cmd, int size)
{
	int		i;
	t_token	*node;

	node = *lst;
	i = 0;
	while (i < size)
	{
		node = ft_redirect_one(node, cmd + i);
		if (node)
			node = node->next;
		i++;
	}
	ft_delete_redirect_lst(lst);
}

t_token	*ft_redirect_one(t_token *node, t_cmd *cmd)
{
	while (1)
	{
		if (!node || (ft_strncmp(node->word, "|", 2) == 0 && node->is_op))
			return (node);
		if ((!ft_strcmp(node->word, "<") || !ft_strcmp(node->word, "<<"))
			&& node->is_op)
		{
			cmd->read_fd = ft_read_file(node, node->word);
		}
		else if ((!ft_strcmp(node->word, ">") || !ft_strcmp(node->word, ">>"))
					&& node->is_op)
		{
			cmd->write_fd = ft_write_file(node, node->word);
		}
		node = node->next;
	}
}

void	ft_delete_redirect_lst(t_token **lst)
{
	t_token	*node;

	node = *lst;
	while (node && node->next)
	{
		if ((!ft_strcmp(node->word, "<") || !ft_strcmp(node->word, "<<"))
			&& node->is_op)
		{
			node = ft_delete_redirect_node(node);
		}
		else if ((!ft_strcmp(node->word, ">") || !ft_strcmp(node->word, ">>"))
					&& node->is_op)
		{
			node = ft_delete_redirect_node(node);
		}
		else
		{
			node = node->next;
		}
	}
	while (node->prev)
	{
		node = node->prev;
	}
	*lst = node;
}

/*
	delete '> file' or '< file' etc
	always delete two consecutive node
*/
t_token	*ft_delete_redirect_node(t_token *node1)
{
	t_token	*prev;
	t_token	*node2;
	t_token	*next;
	
	prev = node1->prev;
	node2 = node1->next;
	next = node1->next->next;
	free(node1->word);
	free(node1);
	free(node2->word);
	free(node2);
	if (prev)
	{
		prev->next = next;
	}
	if (next)
	{
		next->prev = prev;
	}
	return (next);
}