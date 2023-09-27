/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amema <amema@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 10:25:27 by amema             #+#    #+#             */
/*   Updated: 2023/09/27 17:14:01 by amema            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_hex(unsigned int n, const char format, int i)
{
	if (n >= 16)
	return ft_exa(n / 16, format, i + 1);

	if (format == 'x')
		write(1, &"0123456789abcdef"[n % 16], 1);
	if (format == 'X')
		write(1, &"0123456789ABCDEF"[n % 16], 1);
	return (i);
}
