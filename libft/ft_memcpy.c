/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjailbir <gjailbir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 21:12:25 by gjailbir          #+#    #+#             */
/*   Updated: 2021/12/16 21:12:27 by gjailbir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *source, size_t count)
{
	char	*dst;
	char	*src;

	dst = (char *) dest;
	src = (char *) source;
	if (dst == NULL && src == NULL)
		return (NULL);
	while (count-- > 0)
		dst[count] = src[count];
	return (dest);
}
