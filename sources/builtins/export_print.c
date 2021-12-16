/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjailbir <gjailbir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 18:09:30 by gjailbir          #+#    #+#             */
/*   Updated: 2021/12/16 18:09:32 by gjailbir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_put_str_until_chr(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != 61)
	{
		write(1, &str[i], 1);
		i++;
	}
}

static void	ft_putstr_after_eq(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != 61)
		i++;
	if (str[i])
	{
		i++;
		ft_putstr_fd(&str[i], 1);
	}
}

void	print_export(char **env)
{
	int	i;

	i = -1;
	while (env[++i])
	{
		ft_putstr_fd("declare -x ", 1);
		ft_put_str_until_chr(env[i]);
		if (ft_strrchr(env[i], '='))
		{
			write(1, "=\"", 2);
			ft_putstr_after_eq(env[i]);
			write(1, "\"", 1);
		}
		write(1, "\n", 1);
	}
}
