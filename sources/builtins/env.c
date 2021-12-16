/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjailbir <gjailbir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 18:09:46 by gjailbir          #+#    #+#             */
/*   Updated: 2021/12/16 18:09:47 by gjailbir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "minishell.h"

int	ft_env(t_shell *shell)
{
	t_list	*tmp;

	tmp = shell->env;
	while (tmp->next)
	{
		if (ft_strrchr(tmp->content, '='))
			ft_putendl_fd(tmp->content, 1);
		tmp = tmp->next;
	}
	if (ft_strrchr(tmp->content, '='))
		ft_putendl_fd(tmp->content, 1);
	return (0);
}
