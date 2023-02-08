/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_homedir.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasha <sasha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 15:58:26 by sasha             #+#    #+#             */
/*   Updated: 2023/02/08 16:20:50 by sasha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

/*
	return Null when fails
*/
char	*ft_get_homedir(char *login)
{
	char	*line;
	char	*homedir;
	char	**split_line;
	int		i;

	line = ft_find_line(login);
	if (!line)
		return (NULL);
	split_line = ft_split(line, ':');
	if (!split_line)
		return (free(line), NULL);
	homedir = ft_strdup(split_line[5]);
	free(line);
	i = 0;
	while (split_line[i])
	{
		free(split_line[i]);
		i++;
	}
	free(split_line);
	return (homedir);
}

/*
    search in /etc/passwd to find the line start with login
    and return the line
*/
char	*ft_find_line(char *login)
{
	int		fd;
	char	*line;

	fd = open("/etc/passwd", O_RDONLY);
	if (fd < 0)
	{
		write(2, "open fails\n", 11);
		return (NULL);
	}
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL || ft_strncmp(line, login, ft_strlen(login)) == 0)
		{
			break ;
		}
		free(line);
	}
	close(fd);
	return (line);
}
