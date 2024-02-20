/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meakar <meakar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 21:02:55 by meakar            #+#    #+#             */
/*   Updated: 2023/07/29 21:02:55 by meakar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_putnbr(int nbr)
{
    static char num_str[16];
    int         i;
    int         counter;
    long    num;

    i = 0;
    counter = 0;
    num = nbr;
    if (num == 0)
        return (write(1, "0", 1));
    if (num < 0)
    {
        counter += write(1, "-", 1);
        num = -num;
    }
    while (num)
    {
        num_str[i++] = num % 10 + '0';
        num /= 10;
    }
    while (i--)
        counter += write(1, &num_str[i], 1);
    return (counter);
}