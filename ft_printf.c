/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amema <amema@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 16:29:18 by amema             #+#    #+#             */
/*   Updated: 2023/09/28 12:46:36 by amema            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h" // Assumendo che ft_putchar, ft_putstr, ft_putptr, ft_putnbr, ft_putnbr_un e ft_hex siano definite in ft_printf.h

void ft_type(va_list args, const char c, int *n)
{
    if (c == 'c')
        *n += ft_putchar(va_arg(args, int));
    else if (c == 's')
        *n += ft_putstr(va_arg(args, char *));
    else if (c == 'p')
    {
        *n += ft_putstr("0x");
        *n += ft_putptr(va_arg(args, unsigned long long));
    }
    else if (c == 'd' || c == 'i')
        *n += ft_putnbr(va_arg(args, int));
    else if (c == 'u')
        *n += ft_putnbr_un(va_arg(args, unsigned int));
    else if (c == 'x' || c == 'X')
        *n += ft_hex(va_arg(args, unsigned int), c, 1);
    else if (c == '%')
        *n += ft_putchar('%');
}


// void ft_format(va_list args, const char c, int *nchar)
// {
//     if (c == 'c')
//         *nchar += ft_putchar(va_arg(args, int));
//     else if (c == 's')
//         *nchar += ft_putstr(va_arg(args, char *));
//     else if (c == 'p')
//     {
//         *nchar += ft_putstr("0x");
//         *nchar += ft_putptr(va_arg(args, unsigned long long), 1);
//     }
//     else if (c == 'd' || c == 'i')
//         *nchar += ft_putnbr(va_arg(args, int), 1);
//     else if (c == 'u')
//         *nchar += ft_putnbr_un(va_arg(args, unsigned int), 1);
//     else if (c == 'x' || c == 'X')
//         *nchar += ft_exa(va_arg(args, unsigned int), c, 1);
//     else if (c == '%')
//         *nchar += ft_putchar('%');
// }

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
