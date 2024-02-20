/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meakar <meakar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 20:56:58 by meakar            #+#    #+#             */
/*   Updated: 2023/07/15 20:22:06 by meakar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	d_len;
	size_t	s_len;

	i = 0;
	d_len = ft_strlen(dst);
	s_len = ft_strlen(src);
	if (d_len >= size)
		return (s_len + size);
	else
	{
		while (d_len + i < size - 1 && src[i])
		{
			dst[d_len + i] = src[i];
			i++;
		}
	}
	dst[d_len + i] = '\0';
	return (s_len + d_len);
}
