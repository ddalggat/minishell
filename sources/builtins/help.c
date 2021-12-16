/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjailbir <gjailbir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 18:08:51 by gjailbir          #+#    #+#             */
/*   Updated: 2021/12/16 18:08:55 by gjailbir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_help(t_shell *shell, int i)
{
	ft_put_taebag();
	ft_put_tea();
	write(1, "List of built-in functions:\n", 28);
	while (shell->buil_cmd[++i])
	{
		ft_putstr_fd("- ", 1);
		ft_putendl_fd(shell->buil_cmd[i], 1);
	}
	ft_putstr_fd(RESET, 1);
	return (1);
}
