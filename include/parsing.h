/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasha <sasha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 22:44:07 by sasha             #+#    #+#             */
/*   Updated: 2023/02/04 15:33:08 by sasha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "../libftprintf/ft_printf.h"
# include "../libftprintf/libft/libft.h" 

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_token	t_token;
/*
    Once the line is read by readline
	The content of the buffer will be divided into token
	according to the rule described in "Token recogtion" on
	pubs.opengroup.org
*/
typedef struct s_token{
	char	*word;
	t_token	*next;
	t_token	*prev;
}	t_token;

/***  token_utils.c  ***/
t_token	*ft_new_token(char *str, int size);
void	ft_add_token(t_token **lst, t_token *token);
t_token	*ft_extract_token(t_token **lst, t_token *token);
void	ft_delete_token(t_token **token);
void	ft_delete_lst(t_token **lst);

/***  line_to_token_utils.c  ***/
int 	ft_is_operator(char *buffer);
int		ft_is_quote(char *buffer);
int		ft_is_word(char *buffer);
t_token	*ft_get_token(char **buffer, int length);

/***  ft_line_to_token.c  ***/
t_token	*ft_line_to_token(char *buffer);
int		ft_syntax_err(t_token *lst);
t_token *ft_is_token(char **buffer);

typedef struct s_shell	t_shell;
typedef struct s_cmd	t_cmd;

typedef struct s_shell{
	char	**env;
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