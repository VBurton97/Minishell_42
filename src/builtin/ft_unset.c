/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburton <vburton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 11:10:19 by hsliu             #+#    #+#             */
/*   Updated: 2023/02/17 18:21:35 by vburton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

static void	ft_rm_node(t_token *token);
static void	ft_free_var(char *var, t_token **lst);

int	ft_unset(char **argv, t_shell *shell)
{
	int		ret;
	int		i;
	
	if (argv[1] == NULL)
	{
		return (0);
	}
	ret = 0;
	i = 1;
	while (argv[i])
	{
		if (ft_illegal_name(argv[i]))
			ret = 1;
		else
		{
			ft_free_var(argv[i], &(shell->env_lst));
		}
		i++;
	}
	shell->env_lst = shell->env_lst->prev;
	while (shell->env_lst)
	{
		ft_printf("%s\n", shell->env_lst->word);
		shell->env_lst = shell->env_lst->next;
	}
	return (ret);
}

static void	ft_free_var(char *var, t_token **lst)
{
	t_token	*node;
	
	node = *lst;
	if (ft_strncmp(node->word, var, ft_strlen(var)) == 0 
		&&ft_strncmp(node->word, var, ft_strlen(node->word)) == 0)
	{
		*lst = (*lst)->next;
		free(node->word);
		free(node);
		return ;
	}
	while (node)
	{
		if (ft_strncmp(node->word, var, ft_strlen(var)) == 0 
			&&ft_strncmp(node->word, var, ft_strlen(node->word)) == 0)
		{
			ft_rm_node(node);
			return ;
		}
		node = node->next;
	}
}

static void	ft_rm_node(t_token *token)
{
	t_token	*prev;
	t_token	*next;

	prev = token->prev;
	next = token->next;
	free(token->word);
	free(token);
	if (prev)
	{
		prev->next = next;
	}
	if (next)
	{
		next->prev = prev;
	}
}
