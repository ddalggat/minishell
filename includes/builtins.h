/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjailbir <gjailbir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 17:04:20 by gjailbir          #+#    #+#             */
/*   Updated: 2021/12/16 17:06:04 by gjailbir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "includes.h"

int		ft_pwd(void);
int		ft_echo(char **str);
int		ft_env(t_shell *shell);
int		ft_help(t_shell *shell, int i);
int		ft_exit(char **argv, t_shell *msh);
int		ft_cd(char **argv, t_shell *shell);
int		ft_unset(char **argv, t_shell *shell);
int		ft_export(char **argv, t_shell *shell);

int		ft_export_error(char *exp);

void	print_export(char **env);
void	ft_sort_env(t_shell *shell, int len_env);

int		ft_chdir_error(char *dir);
int		ft_set_new_pwd(t_shell *shell);
int		ft_set_new_oldpwd(char *pwd_old, t_shell *shell);

#endif
