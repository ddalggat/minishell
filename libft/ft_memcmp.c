/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjailbir <gjailbir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 21:12:16 by gjailbir          #+#    #+#             */
/*   Updated: 2021/12/16 21:12:17 by gjailbir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*b1;
	unsigned char	*b2;
	size_t			i;

	i = -1;
	b1 = (unsigned char *) s1;
	b2 = (unsigned char *) s2;
	if (b1 == NULL && b2 == NULL)
		return (0);
	while (++i < n)
		if (b1[i] != b2[i])
			return (b1[i] - b2[i]);
	return (0);
}
