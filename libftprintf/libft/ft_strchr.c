/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsliu <hsliu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 13:10:40 by hsliu             #+#    #+#             */
/*   Updated: 2022/12/06 10:38:18 by hsliu            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	char	x;

	x = (char)c;
	while (*s && *s != x)
		s++;
	if (x == *s)
		return ((char *)s);
	return (0);
}
