/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amema <amema@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 11:48:34 by amema             #+#    #+#             */
/*   Updated: 2023/09/28 12:39:26 by amema            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// int ft_putnbr(int nb, int i)
// {
//     char *str;
//     if (nb == -2147483648)
//     {
//         ft_putstr("-2147483648");
//         return 11;
//     }
//     str = ft_itoa(nb); // Converte l'intero in una stringa
//     ft_putstr(str);   // Stampa la stringa
//     free(str);         // Libera la memoria allocata da itoa
//     return ft_strlen(str);
// }

int ft_putnbr(int nb)
{
    char *str;
    if (nb == -2147483648)
    {
        ft_putstr("-2147483648");
        str = "-2147483648";
    }
    else
    {
        str = ft_itoa(nb); // Converte l'intero in una stringa
        ft_putstr(str);    // Stampa la stringa
        free(str);          // Libera la memoria allocata da itoa
    }
    return ft_strlen(str); // Restituisce la lunghezza della stringa
}

int ft_putnbr_un(unsigned int nb)
{
    char *str;
    str = ft_itoa(nb); // converte l'intero in una stringa
    ft_putstr(str);    // stampa la stringa
    free(str);          // libera la memoria allocata da itoa
    return ft_strlen(str);
}
