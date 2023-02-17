#include "exec.h"
#include "minishell.h"
#include "parsing.h"

int	ft_read_file(char *file, char *op);
int	ft_write_file(char *file, char *op);

int	ft_open_file(t_token lst, char *op)
{
	int	file_to_open;

	if (ft_strcmp(op, "<") == 0 || ft_strcmp(op, "<<"))
		file_to_open = ft_read_file(lst, op);
	if (ft_strcmp(op, ">") == 0 || ft_strcmp(op, ">>"))
		file_to_open = ft_write_file(lst, op);
	return (file_to_open);
}

int	ft_read_file(t_token lst, char *op)
{
	int	input;

	lst = lst->next;
	if (access(file, R_OK) == -1)
		perror(file);
	else if (strcmp(op, "<") == 0)
		input = open(lst->word, O_RDONLY);
	else if (strcmp(op, "<<") == 0)
		input = ft_here_doc();
	else
		input = -1;
	return (input);
}

int	ft_write_file(t_token lst, char *op)
{
	int	output;

	if (access(file, F_OK) == -1 && access(file, W_OK) == -1)
		perror(file);
	else if (ft_strcmp (op, ">") == 0)
		output = open(file, O_WRONLY | O_TRUNC | O_CREAT, 0644);
	else if (ft_strcmp(file, ">>") == 0)
		output = open(file, O_WRONLY | O_CREAT | O_APPEND, 0644);
	else
		output = -1;
	return (output);
}

int	ft_is_file_operator(char *op)
{
	if (ft_strcmp(op, "<") == 0 || ft_strcmp(op, "<<") \
		|| ft_strcmp(op, ">") == 0 || ft_strcmp(op, ">>"))
		return (1);
	return (0);
}