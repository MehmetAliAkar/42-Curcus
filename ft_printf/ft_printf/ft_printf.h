/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meakar <meakar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 19:40:03 by meakar            #+#    #+#             */
/*   Updated: 2023/07/29 19:40:03 by meakar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>

int ft_putchar(int);
int ft_putstr(char *);
int ft_putnbr(int);
int ft_putptr(unsigned long);
int ft_printuint(unsigned int);
int ft_puthex(unsigned int, char *);

#endif