/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meakar <meakar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 20:45:58 by meakar            #+#    #+#             */
/*   Updated: 2023/07/29 20:45:58 by meakar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_putstr(char *str)
{
    int i;

    i = 0;
    if (str == NULL)
    {
        write(1, "(null)", 6);
        return (6);
    }
    while (str[i])
    {
        ft_putchar(str[i]);
        i++;
    }
    return (i);
}