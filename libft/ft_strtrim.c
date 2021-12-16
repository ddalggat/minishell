/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjailbir <gjailbir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 21:14:44 by gjailbir          #+#    #+#             */
/*   Updated: 2021/12/16 21:14:46 by gjailbir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_ltrim(char const *s1, char const *set, int arg)
{
	int	i;

	i = 0;
	while (set[i] && s1[arg])
		if (s1[arg] == set[i++])
			arg = ft_ltrim(s1, set, ++arg);
	return (arg);
}

static int	ft_rtrim(char const *s1, char const *set, int arg)
{
	int	i;

	i = 0;
	while (set[i])
		if (s1[arg] == set[i++])
			arg = ft_rtrim(s1, set, --arg);
	return (arg);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int	begin;
	int	end;

	if (!s1)
		return (NULL);
	begin = ft_ltrim(s1, set, 0);
	if (!s1[begin])
		return (ft_substr(s1, begin, 1));
	end = ft_rtrim(s1, set, ft_strlen(s1) - 1) - begin;
	return (ft_substr(s1, begin, end + 1));
}
