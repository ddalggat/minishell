/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjailbir <gjailbir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 21:12:39 by gjailbir          #+#    #+#             */
/*   Updated: 2021/12/16 21:12:47 by gjailbir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	max(size_t a, size_t b)
{
	if (a < b)
		return (b);
	return (a);
}

size_t	min(size_t a, size_t b)
{
	if (a < b)
		return (a);
	return (b);
}
