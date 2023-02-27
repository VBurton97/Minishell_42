/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_pipe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsliu <hsliu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 16:43:58 by sasha             #+#    #+#             */
/*   Updated: 2023/02/27 12:18:44 by hsliu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

/*
	malloc cmd according to how many pipe counted in the lst
	with write_fd and read_fd all init and connected by pipe
*/
t_cmd	*ft_get_cmd(t_token *lst, int *size)
{
	int		*p;
	t_cmd	*cmd;
	int		n;

	n = ft_count_pipe(lst);
	cmd = ft_malloc_cmd(n + 2);
	if (n == 0)
	{
		return (cmd);
	}
	if (n > 0)
	{
		p = ft_malloc_pipe(n);
		if (p == NULL || cmd == NULL)
		{
			return (free(cmd), free(p), NULL);
		}
		ft_set_pipe(cmd, n + 1, p);
		free(p);
	}
	return (cmd);
}

/*
	this function can only be called if there is pipe involved
	cmd is an array of size n, p is an array of 2n - 2
	the function will use dup
*/
void	ft_set_pipe(t_cmd *cmd, int n, int *p)
{
	int	i;

	cmd[0].write_fd = dup(p[1]);
	close(p[1]);
	i = 1;
	while (i < n - 1)
	{
		cmd[i].read_fd = dup(p[2 * (i - 1)]);
		cmd[i].write_fd = dup(p[i * 2 + 1]);
		close(p[2 * (i - 1)]);
		close(p[i * 2 + 1]);
		i++;
	}
	cmd[n - 1].read_fd = dup(p[2 * n - 4]);
	close(p[2 * n - 4]);
}

/*
	malloc an array of size 2n and called pipe on every two element
	array[0  1]
	array[2  3]
	...
	array[2n-2 2n-1]
*/
int	*ft_malloc_pipe(int n)
{
	int	*p;
	int	i;

	p = malloc(sizeof(int) * n * 2);
	if (!p)
	{
		write(2, "malloc fails\n", 13);
		return (NULL);
	}
	i = 0;
	while (i < 2 * n)
	{
		if (pipe(p + i))
		{
			write(2, "pipe fails\n", 11);
			free(p);
			return (NULL);
		}
		i = i + 2;
	}
	return (p);
}

/*
	malloc n cmd and init the fd to stdin and stdout
*/
t_cmd	*ft_malloc_cmd(int n)
{
	t_cmd	*cmd;
	int		i;

	cmd = malloc(sizeof(t_cmd) * n);
	if (!cmd)
	{
		write(2, "malloc fails\n", 13);
		return (NULL);
	}
	i = 0;
	while (i < n)
	{
		cmd[i].read_fd = 0;
		cmd[i].write_fd = 1;
		i++;
	}
	return (cmd);
}

/*
	count how many | are there in the lst
*/
int	ft_count_pipe(t_token *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		if (ft_strncmp(lst->word, "|", 1) == 0 && lst->is_op)
			i++;
		lst = lst->next;
	}
	return (i);
}
