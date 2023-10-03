/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amema <amema@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 16:40:41 by amema             #+#    #+#             */
/*   Updated: 2023/10/03 12:51:10 by amema            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "ft_printf.h"


int ft_putptr(unsigned long long ptr, int i)
{

    if (!ptr)
    {
        ft_putchar('0');
        return i + 1;
    }

	i = 0;
    if (ptr >= 16)
    {
        i += ft_putptr(ptr / 16, i);
    }
    ft_putchar("0123456789abcdef"[ptr % 16]);
    return i + 1;
}
