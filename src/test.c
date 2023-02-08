/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasha <sasha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 14:00:28 by sasha             #+#    #+#             */
/*   Updated: 2023/02/08 16:27:55 by sasha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	ft_print_lst(t_token *lst)
{
	if (!lst)
	{
		printf("lst empty\n");
	}
	while (lst)
	{
		printf("%s -> ", lst->word);
		lst = lst->next;
	}
}

/*
int main()
{
	t_shell		shell;
	
	shell.env_lst = NULL;
	if (ft_get_env(&(shell.env_lst)))
	{
		return (0);
	}
	
	char		*buffer;
	buffer = readline("Enter: ");
	if (ft_parsing(buffer, &shell))
	{
		return (0);
	}
	free(buffer);
	ft_print_lst(shell.parsed_input);
	printf("\n");
	if (ft_dollar_exps_lst(shell.parsed_input, shell.env_lst))
		write(2, "exps fails\n", 11);
	ft_print_lst(shell.parsed_input);
	printf("\n");
	ft_delete_lst(&(shell.parsed_input));
}
*/

int main(int argc, char **argv)
{
	char *homedir;

	if (argc != 2)
	{
		write(2, "need 2 args\n", 12);
		return (0);
	}
	homedir = ft_get_homedir(argv[1]);
	ft_printf("homedir of %s is: %s\n", argv[1], homedir);
	free(homedir);
}
