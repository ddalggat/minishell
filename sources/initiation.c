/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjailbir <gjailbir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 18:47:58 by nluya             #+#    #+#             */
/*   Updated: 2021/12/16 21:05:31 by gjailbir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_init_env(t_shell *shell, char *envp[])
{
	char	*tmp;
	char	*shlvl;

	tmp = ft_itoa(ft_atoi(getenv("SHLVL")) + 1);
	shlvl = ft_strjoin("SHLVL=", tmp);
	while (*envp)
	{
		if (ft_strncmp(*envp, "SHLVL=", 6))
			ft_lstadd_front(&shell->env, ft_lstnew(ft_strdup(*envp)));
		envp++;
	}
	ft_lstadd_front(&shell->env, ft_lstnew(shlvl));
	shell->arr_env = ft_lst_to_array(shell->env);
	free(tmp);
}

void	ft_initiation(t_shell *shell, char *envp[])
{
	g_status = 0;
	rl_outstream = stderr;
	shell->env = NULL;
	shell->cmds = NULL;
	shell->arr_env = NULL;
	shell->buil_cmd = ft_split(BUIL_CMD, ':');
	ft_init_env(shell, envp);
	ft_copy_std_io(shell);
	ft_restore_std_io(shell);
}
