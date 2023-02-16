#include "exec.h"
#include "minishell.h"
#include "parsing.h"

int	ft_read_file(char *file, char *op);
int	ft_write_file(char *file, char *op);

int	ft_open_file(char *file, char *op)
{
	int	file_to_open;

	if (ft_strcmp(file, "<") == 0 || ft_strcmp(file, "<<"))
		file_to_open = ft_read_file(file, op);
	if (ft_strcmp(file, ">") == 0 || ft_strcmp(file, ">>"))
		file_to_open = ft_write_file(file, op);
	return (file_to_open);
}

int	ft_read_file(char *file, char *op)
{
	int	input;
	if (access(file, R_OK) == -1)
		perror(file);
	if (strcmp(op, "<") == 0)
		input = open(file, O_RDONLY);
	if (strcmp(op, "<<") == 0)
		ft_here_doc();
	return (input);
}

int	ft_write_file(char *file, char *op)
{
	int	output;

	if (access(file, F_OK) == -1 && access(file, W_OK) == -1)
		perror(file);
	if (ft_strcmp (op, ">") == 0)
		output = open(file, O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (ft_strcmp(file, ">>") == 0)
		output = open(file, O_WRONLY | O_CREAT | O_APPEND, 0644);
	return (output);
}