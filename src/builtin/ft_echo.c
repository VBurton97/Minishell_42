/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburton <vburton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 16:06:57 by sasha             #+#    #+#             */
/*   Updated: 2023/02/20 11:10:40 by vburton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

static int	ft_write_protected(char *str, int size);

/*
    return 0 on success
    return 1 on failure
    argv[0] is the command itself
*/
int ft_echo(char **argv)
{
    int i;
    
    i = 1;
	if (argv[1] == NULL)
        return (ft_write_protected("\n", 1));
    if (ft_strncmp(argv[1], "-n", 3) == 0)
        i = 2;
    while (argv[i])
    {
        if (ft_write_protected(argv[i], ft_strlen(argv[i])))
			return (1);
        if (argv[i + 1])
		{
			if (ft_write_protected(" ", 1))
				return (1);
		}
		i++;
    }
    if (ft_strncmp(argv[1], "-n", 3) == 0)
		return (0);
	if (ft_write_protected("\n", 1))
		return (1);
    return (0);
}

static int	ft_write_protected(char *str, int size)
{
	if (write(1, str, size) == -1)
	{
		return (1);
	}
	return (0);
}
