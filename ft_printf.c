/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amema <amema@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 16:29:18 by amema             #+#    #+#             */
/*   Updated: 2023/10/03 12:47:25 by amema            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h" // Assumendo che ft_putchar, ft_putstr, ft_putptr, ft_putnbr, ft_putnbr_s e ft_hex siano definite in ft_printf.h

void ft_type(va_list args, const char c, int *n)
{
    int i;
    i = 1;
    if (c == 'c')
        *n += ft_putchar(va_arg(args, int));
    else if (c == 's')
        *n += ft_putstr(va_arg(args, char *));
    else if (c == 'p')
    {
        unsigned long long ptr = va_arg(args, unsigned long long);
        *n += ft_putstr("0x");
        *n += ft_putptr(ptr, 0);
    }
    else if (c == 'd' || c == 'i')
        *n += ft_putnbr(va_arg(args, int), 1);
    else if (c == 'u')
        *n += ft_putnbr_s(va_arg(args, unsigned int), 1);
    else if (c == 'x' || c == 'X')
        *n += ft_hex(va_arg(args, unsigned int), c, 1);
    else if (c == '%')
        *n += ft_putchar('%');
}

int ft_printf(const char *str, ...)
{
    va_list args;
    int i;
    int n;

    n = 0;
    i = 0;
    va_start(args, str);
    while (str[i])
    {
        if (str[i] == '%')
        {
            ft_type(args, str[++i], &n);
            i++;
        }
        else
        {
            ft_putchar(str[i]);
            i++;
            n++;
        }
    }
    va_end(args);
    return (n);
}
