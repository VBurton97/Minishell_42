/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasha <sasha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 22:44:07 by sasha             #+#    #+#             */
/*   Updated: 2023/02/01 23:05:52 by sasha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

/*
    the line read is first splitted into word by space
	unless the space is between quotes
	The quote is then removed, with the state recorded.
	flag = 0 : no quote
    flag = 1 : single quote
    flag = 2 : double quote
*/
typedef struct s_word{
	char	*word;
	int		quote;
	t_word	*next;
}	t_word;


#endif