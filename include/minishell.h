/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasha <sasha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 15:37:01 by sasha             #+#    #+#             */
/*   Updated: 2023/02/15 15:39:56 by sasha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libftprintf/ft_printf.h"
# include "../libftprintf/libft/libft.h"

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_token	t_token;
typedef struct s_shell	t_shell;
typedef struct s_cmd	t_cmd;

/*
    Once the line is read by readline
	The content of the buffer will be divided into token
	according to the rule described in "Token recogtion" on
	pubs.opengroup.org

	if is_op = 1, then the token is an operator
*/
typedef struct s_token{
	char	*word;
	int		is_op;
	t_token	*next;
	t_token	*prev;
}	t_token;

typedef struct s_shell{
	char	**env;
	t_token	*env_lst;
	int		exit_status;
	t_cmd	*cmd;
	t_token	*parsed_input;
}	t_shell;

typedef struct s_cmd{
	//command
	//args
	int	write_fd;
	int	read_fd;
}	t_cmd;

#endif