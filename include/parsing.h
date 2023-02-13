/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsliu <hsliu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 22:44:07 by sasha             #+#    #+#             */
/*   Updated: 2023/02/13 12:43:00 by hsliu            ###   ########.fr       */
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

void	ft_print_lst(t_token *lst);


/***  token_utils.c  ***/
t_token	*ft_new_token(char *str, int size);
void	ft_add_token(t_token **lst, t_token *token);
t_token	*ft_extract_token(t_token **lst, t_token *token);
void	ft_delete_token(t_token **token);
void	ft_delete_lst(t_token **lst);

/***  line_to_token_utils.c  ***/
int		ft_is_operator(char *buffer);
int		ft_is_word(char *buffer);
t_token	*ft_is_token(char **buffer, int length);
int		ft_set_quote_state(char c, int quote_state);

/***  ft_line_to_token.c  ***/
t_token	*ft_line_to_token(char *buffer);
int		ft_syntax_err(t_token *lst);
t_token	*ft_get_token(char **buffer);

/***  ft_set_pipe.c  ***/
t_cmd	*ft_get_cmd(t_token *lst);
void	ft_set_pipe(t_cmd *cmd, int n, int *p);
int		*ft_malloc_pipe(int n);
t_cmd	*ft_malloc_cmd(int n);
int		ft_count_pipe(t_token *lst);

/***  parsing.c  ***/
int		ft_parsing(char *buffer, t_shell *shell);

/***  dollar_exp_utils.c  ***/
char	*ft_strjoin_1(char *new_w, char **old, int n);
char	*ft_strjoin_2(char *new_w, char **old, t_token *env_lst);
int		ft_delimit_dollar(char *key);
char	*ft_add_equal(char *key);
char	*ft_get_para(char *search_key, t_token *env_lst);

/***  ft_dollar_exps  ***/
char	*ft_dollar_exps(char *word, t_token *env_lst);

/***  ft_get_env.c  ***/
int		ft_get_env(t_token **env_lst);
int	ft_dollar_exps_lst(t_token *lst, t_token *env_lst);

/***  ft_get_homedir  ***/
char	*ft_get_homedir(char *login);
char	*ft_find_line(char *login);
int		ft_delimit_login(char *login);

/***  tilde_exps_utils.c  ***/
char	*ft_tilde_exps(char *word, t_token *env_lst);
char	*ft_case_tilde_login(char *word);
char	*ft_case_tilde_slash(char *word, char *home);
char	*ft_case_tilde(char *word, char *home);
char	*ft_get_home(t_token *env_lst);

/***  ft_tilde_exps.c  ***/
int ft_tilde_exps_lst(t_token *lst, t_token *env_lst);

/***  ft_exps_and_split.c  ***/
int	ft_exps_and_split(t_token **lst, t_token *env_lst);
int	ft_syntax_err_2(t_token *lst);
int	ft_exist_unquoted_space(char *word);

/***  ft_field_split.c  ***/
int ft_split_lst(t_token **lst);
int ft_split_word(t_token **node);

/***	ft_rm_quote.c	***/
void	ft_rm_quote_lst(t_token *lst);
void	ft_rm_quote_word(char *word);

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