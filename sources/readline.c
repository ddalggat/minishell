/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjailbir <gjailbir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 18:06:10 by gjailbir          #+#    #+#             */
/*   Updated: 2021/12/16 21:56:26 by gjailbir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_clear_cmds(t_cmd **cmd)
{
	t_cmd	*next;

	while (*cmd)
	{
		next = (*cmd)->next;
		ft_lstclear(&(*cmd)->lst, free);
		ft_lstclear(&(*cmd)->redirects, free);
		if ((*cmd)->arg)
			ft_split_free((*cmd)->arg);
		(*cmd)->arg = NULL;
		free(*cmd);
		*cmd = next;
	}
}

void	ft_cleaning(t_shell *shell, char *str)
{
	if (shell->cmds)
		ft_clear_cmds(&shell->cmds);
	if (ft_strlen(str))
		shell->cmd_status = g_status;
	g_status = 0;
	free(str);
}

int	ft_loop_hook(t_shell *shell)
{
	char	*str;

	using_history();
	while (true)
	{
		str = readline(YLW"sueta$ "RESET);
		if (g_status == 130)
		{
			shell->cmd_status = 1;
			g_status = 0;
		}
		if (!str)
			str = ft_strdup("exit");
		else
			add_history(str);
		if (!ft_parser(shell, str))
			ft_run_pipes(shell);
		ft_cleaning(shell, str);
	}
}
