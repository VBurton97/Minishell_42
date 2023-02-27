#include "exec.h"
#include "minishell.h"
#include "parsing.h"

int	ft_read_file(char *file);
int	ft_write_in_file(char *file);
int	ft_append_file(char *file);

void	ft_open_close_dup(t_cmd *cmd)
{
	if (cmd->read_file)
		cmd->read_fd = ft_read_file(cmd->read_file);
	if (cmd->write_file)
		cmd->write_fd = ft_write_file(cmd->write_file);
	if (cmd->append_file)
		cmd->write_fd = ft_append_file(cmd->append_file);
}

int	ft_read_file(char *file)
{
	int	input;

	input = 0;
	if (access(file, R_OK) != 0)
		perror(file);
	else
		input = open(file, O_RDONLY);
	return (input);
}

int	ft_write_in_file(char *file)
{
	int	output;

	output = 1;
	if (access(file, F_OK) == 0 && access(file, W_OK) == -1)
		perror(file);
	else
		output = open(file, O_WRONLY | O_TRUNC | O_CREAT, 0644);
	return (output);
}

int	ft_append_file(char *file)
{
	int	output;

	output = 1;
	if (access(file, F_OK) == 0 && access(file, W_OK) == -1)
		perror(file);
	else
		output = open(file, O_WRONLY | O_APPEND | O_CREAT, 0644);
	return (output);
}
