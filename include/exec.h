#ifndef EXEC_H
# define EXEC_H

t_token	*ft_get_lst_cmd(t_token	*lst);
char	***ft_get_array_cmd(t_token *lst, int nb_cmd);
int	get_number_of_pipe(t_token	*lst);
void	ft_exec(t_token *lst);

#endif