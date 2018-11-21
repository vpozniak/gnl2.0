/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpozniak <vpozniak@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 16:03:15 by vpozniak          #+#    #+#             */
/*   Updated: 2018/11/01 17:51:20 by vpozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(int nb)
{
	int		str;

	str = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		nb = -nb;
		str++;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		str++;
	}
	return (str);
}

char		*ft_itoa(int n)
{
	char	*j;
	size_t	len;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = ft_len(n);
	if (!(j = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	j[len--] = '\0';
	if (n < 0)
	{
		j[0] = '-';
		n = -n;
	}
	if (n == 0)
	{
		j[0] = '0';
		return (j);
	}
	while (n)
	{
		j[len--] = (n % 10) + '0';
		n /= 10;
	}
	return (j);
}
