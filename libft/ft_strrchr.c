/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjailbir <gjailbir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 21:14:40 by gjailbir          #+#    #+#             */
/*   Updated: 2021/12/16 21:14:41 by gjailbir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*res;

	res = NULL;
	i = -1;
	while (s[++i] != '\0')
		if (s[i] == c)
			res = ((char *)(s + i));
	if (c == 0 && s[i] == 0)
		res = ((char *)(s + i));
	return (res);
}
