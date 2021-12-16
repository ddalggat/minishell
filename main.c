/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjailbir <gjailbir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 17:03:59 by gjailbir          #+#    #+#             */
/*   Updated: 2021/12/16 21:55:19 by gjailbir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char *argv[], char *envp[])
{
	t_shell	shell;

	if (argc > 1)
	{
		printf(RED"Error\nUsage: %s\n"RESET, argv[0]);
		return (1);
	}
	ft_initiation(&shell, envp);
	ft_signal_main();
	ft_loop_hook(&shell);
	return (0);
}
