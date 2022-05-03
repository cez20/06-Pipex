/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 15:56:42 by cemenjiv          #+#    #+#             */
/*   Updated: 2021/12/01 13:25:54 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nb_length(long long n)
{
	int	length;

	length = 0;
	if (n < 0)
	{
		n = -n;
		length++;
	}
	while (n >= 10)
	{
		n = n / 10;
		length++;
	}
	if (n >= 0 && n < 10)
		length++;
	return (length);
}

char	*ft_itoa(int n)
{
	char			*str;
	int				size;
	int				i;
	long long		nb;

	nb = (long long)n;
	size = nb_length(nb);
	str = (char *)malloc((size + 1) * sizeof(*str));
	if (!str)
		return (NULL);
	i = 0;
	if (nb < 0)
	{
		str[i] = '-';
		nb = -nb;
	}
	i = size - 1;
	while (nb >= 10)
	{
		str[i--] = (nb % 10 + 48);
		nb = nb / 10;
	}
	str[i] = (char)(nb % 10 + 48);
	str[size] = '\0';
	return (str);
}
