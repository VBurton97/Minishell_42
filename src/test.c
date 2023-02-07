/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasha <sasha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 14:00:28 by sasha             #+#    #+#             */
/*   Updated: 2023/02/07 14:36:35 by sasha            ###   ########.fr       */
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

int	ft_dollar_exps_lst(t_token *lst, t_token *env_lst)
{
	char	*exp_word;
	
	while (lst)
	{
		exp_word = ft_dollar_exps(lst->word, env_lst);
		if (!exp_word)
		{
			return (1);
		}
		free(lst->word);
		lst->word = exp_word;
		lst = lst->next;
	}
	return (0);
}

int main()
{
	extern char **environ;
	t_shell		shell;

	/** temporary env_lst setting **/
	t_token	*env_lst;
	t_token	*token;
	int		i;

	i = 0;
	env_lst = NULL;
	while (environ[i])
	{
		token = ft_new_token(environ[i], ft_strlen(environ[i]));
		if (!token)
		{
			write(2, "malloc fails\n", 13);
			ft_delete_lst(&(env_lst));
			break ;
		}
		ft_add_token(&env_lst, token);
		i++;
	}
	
	/**  end **/
	
	char		*buffer;
	buffer = readline("Enter: ");
	if (ft_parsing(buffer, &shell))
	{
		return (0);
	}
	free(buffer);
	ft_print_lst(shell.parsed_input);
	printf("\n");
	//ft_print_lst(env_lst);
	if (ft_dollar_exps_lst(shell.parsed_input, env_lst))
		write(2, "exps fails\n", 11);
	//char	*res;
//	res = ft_dollar_exps(shell.parsed_input->word, env_lst);
	//ft_printf("%s\n", res);
// test end
	ft_print_lst(shell.parsed_input);
	printf("\n");
	ft_delete_lst(&(shell.parsed_input));
}

