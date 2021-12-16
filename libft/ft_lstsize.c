/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjailbir <gjailbir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 21:12:00 by gjailbir          #+#    #+#             */
/*   Updated: 2021/12/16 21:12:02 by gjailbir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst && ++i)
		lst = lst->next;
	return (i);
}
