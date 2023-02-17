#ifndef EXEC_H
# define EXEC_H

# include "minishell.h"
# include "parsing.h"

t_token	*ft_get_lst_cmd(t_token	*lst);
char	***ft_get_array_cmd(t_token *lst, int nb_cmd);
int		get_number_of_pipe(t_token	*lst);
void	ft_exec(t_shell *shell, t_token lst, char ***cmd, int nb_pipe);
int		ft_open_file(char *file, char *op);
int		ft_here_doc(char *limiter);
int		exec_builtin(t_shell *shell, char **cmd);
int	ft_is_file_operator(char *op);

#endif