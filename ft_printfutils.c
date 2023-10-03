/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfutils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amema <amema@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 10:09:49 by amema             #+#    #+#             */
/*   Updated: 2023/10/03 13:09:16 by amema            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

size_t	ft_strlen(const char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_putstr(char *str)
{
	int	i;

	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (ft_strlen("(null)"));
	}
	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

// static size_t	ft_lenght(long nb)
// {
// 	size_t	count;

// 	count = 0;
// 	if (nb <= 0)
// 	{
// 		count++;
// 		nb = -nb;
// 	}
// 	while (nb > 0)
// 	{
// 		nb = nb / 10;
// 		count++;
// 	}
// 	return (count);
// }

// char	*ft_itoa(int n)
// {
// 	char	*result;
// 	size_t	c;
// 	long	nbr;

// 	nbr = n;
// 	c = ft_lenght(nbr);
// 	result = (char *)malloc(c + 1);
// 	if (!result)
// 		return (NULL);
// 	result[c--] = '\0';
// 	if (nbr < 0)
// 	{
// 		result[0] = '-';
// 		nbr = -nbr;
// 	}
// 	while (nbr >= 10)
// 	{
// 		result[c] = 48 + (nbr % 10);
// 		nbr = nbr / 10;
// 		c--;
// 	}
// 	if (nbr >= 0 && nbr < 10)
// 		result[c] = 48 + nbr;
// 	return (result);
// }
