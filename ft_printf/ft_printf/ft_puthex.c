/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meakar <meakar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 22:15:40 by meakar            #+#    #+#             */
/*   Updated: 2023/07/29 22:15:40 by meakar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void print_hex(unsigned int  u, char *hex)
{
    if (u < 16)
        ft_putchar(hex[u % 16]);
    else
    {
        print_hex(u / 16, hex);
        ft_putchar(hex[u % 16]);
    }
}

static int  hex_len(unsigned int    u)
{
    int i;

    i = 0;
    while ( u != 0)
    {
        i++;
        u /= 16;
    }
    return (i);
}

int ft_puthex(unsigned int u, char *hex)
{
    int len;

    len = 0;
    if (u == 0)
    {
        write (1, "0", 1);
        return (1);
    }
    len += hex_len(u);
    print_hex(u, hex);
    return (len);
}