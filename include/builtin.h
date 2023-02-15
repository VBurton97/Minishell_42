/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasha <sasha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 16:05:27 by sasha             #+#    #+#             */
/*   Updated: 2023/02/15 16:21:20 by sasha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include "minishell.h"

int ft_echo(char **argv);
int ft_cd(char **argv, t_shell *shell);
int ft_pwd(char **argv);
int ft_export(char **argv, t_shell *shell);
int ft_unset(char **argv, t_shell *shell);
int ft_env(char **argv, t_shell *shell);
int ft_exit(char **argv, t_shell *shell);

#endif
