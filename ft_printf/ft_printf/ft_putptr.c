/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meakar <meakar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 21:28:06 by meakar            #+#    #+#             */
/*   Updated: 2023/07/29 21:28:06 by meakar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int  len_ptr_calc(unsigned long  ptr)
{
    int i;

    i = 0;
    while (ptr)
    {
        ptr /= 16;
        i++;
    }
    return (i);
}

static void ft_parse_ptr(unsigned long  ptr, char *hex)
{
    if (ptr < 16)
        ft_putchar(hex[ptr % 16]);
    else
    {
        ft_parse_ptr(ptr / 16, hex);
        ft_putchar(hex[ptr % 16]);
    }
}

int ft_putptr(unsigned long ptr)
{
    int counter;

    counter = 0;
    counter += write(1, "0x", 2);
    if (ptr == 0)
        counter += write(1, "0", 1);
    else
    {
        ft_parse_ptr(ptr, "0123456789abcdef");
        counter += len_ptr_calc(ptr);
    }
    return (counter);
}