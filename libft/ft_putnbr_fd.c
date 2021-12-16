/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjailbir <gjailbir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 21:13:11 by gjailbir          #+#    #+#             */
/*   Updated: 2021/12/16 21:13:17 by gjailbir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int		i;
	long	num;
	char	list[2048];

	i = 0;
	num = (long) n;
	if (!n)
		ft_putchar_fd('0', fd);
	if (num < 0)
	{
		num = -num;
		ft_putchar_fd('-', fd);
	}
	while (num > 0)
	{
		list[i++] = num % 10 + 48;
		num /= 10;
	}
	while (i-- > 0)
		ft_putchar_fd(list[i], fd);
}
