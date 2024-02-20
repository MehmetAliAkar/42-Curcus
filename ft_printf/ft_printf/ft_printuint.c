/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printuint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meakar <meakar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 21:45:11 by meakar            #+#    #+#             */
/*   Updated: 2023/07/29 21:45:11 by meakar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printuint(unsigned int   nbr)
{
    static char uint_str[16];
    int         i;
    int         counter;

    if (nbr == 0)
        return (write(1, "0", 1));
    i = 0;
    counter = 0;
    while (nbr)
    {
        uint_str[i++] = nbr % 10 + '0';
        nbr /= 10;
    }
    while (i--)
        counter += write(1, &uint_str[i], 1);
    return (counter);
}
