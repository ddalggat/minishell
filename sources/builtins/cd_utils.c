/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjailbir <gjailbir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 18:10:05 by gjailbir          #+#    #+#             */
/*   Updated: 2021/12/16 18:10:07 by gjailbir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_chdir_error(char *dir)
{
	ft_putstr_fd("shell: cd: ", 2);
	ft_putstr_fd(dir, 2);
	ft_putstr_fd(": ", 2);
	return (ft_print_errno());
}

int	ft_set_new_oldpwd(char *pwd_old, t_shell *shell)
{
	char	*pwd;

	pwd = ft_strjoin("OLDPWD=", pwd_old);
	ft_update_el_env(shell, pwd);
	free(pwd);
	return (0);
}

int	ft_set_new_pwd(t_shell *shell)
{
	char	*new_pwd;
	char	*tmp;
	char	*pwd;

	tmp = ft_allocate(1024);
	pwd = getcwd(tmp, 1024);
	if (pwd == NULL)
	{
		free(tmp);
		return (ft_print_errno());
	}
	new_pwd = ft_strjoin("PWD=", pwd);
	ft_update_el_env(shell, new_pwd);
	free(new_pwd);
	free(tmp);
	return (0);
}
