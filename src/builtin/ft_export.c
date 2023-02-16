/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsliu <hsliu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 19:15:53 by sasha             #+#    #+#             */
/*   Updated: 2023/02/16 11:58:09 by hsliu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

static int	ft_illegal_name(char *name);
static t_token	*ft_new_var(char *str);

/*
	can take multiple args
	each has form name=value
	equal sign cannot be a name
*/
int	ft_export(char **argv, t_shell *shell)
{
	int		ret;
	int		i;
	t_token	*var;

	if (argv[1] == NULL)
	{
		write(2, "export: no argument\n", 20);
		return (0);
	}
	ret = 0;
	i = 1;
	while (argv[i])
	{
		if (ft_illegal_name(argv[i]))
			ret = 1;
		else if (ft_strchr(argv[i], '='))
		{
			var = ft_new_var(argv[i]);
			if (var)
				ft_add_token(&(shell->env_lst), var);
		}
		i++
	}
	return (ret);
}

/*
	str has the form NAME=VALUE, value can be an empty string
	return NULL, if the str is not valid, or the malloc fails
*/
static t_token	*ft_new_var(char *str)
{
	t_token	*token;

	token = ft_new_token(str, ft_strlen(str));
	if (token == NULL)
	{
		return (NULL);
	}
	return (token);
}

/*
	name can only cantains alphabet, number and underscore
	name cannot begin with number
	if name doesn't end with '=', ignore it
*/
static int	ft_illegal_name(char *name)
{
	int	i;
	
	if (ft_is_digit(name[0]))
	{
		write(2, "export: not a valid identifier\n", 31);
		return (0);
	}
	i = 0;
	while (name[i] != '=')
	{
		if (!ft_isalnum(name[i]) && name[i] != '_')
		{
			write(2, "export: not a valid identifier\n", 31);
			return (0);
		}
		i++;
	}
	return (1);
}

