/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meakar <meakar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 01:11:08 by meakar            #+#    #+#             */
/*   Updated: 2023/07/15 01:11:08 by meakar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*ret_arr;
	int		len;
	int		i;

	if (!s || !f)
		return (NULL);
	i = 0;
	len = ft_strlen(s);
	ret_arr = malloc(sizeof(char) * (len + 1));
	if (!ret_arr)
		return (NULL);
	while (s[i])
	{
		ret_arr[i] = f(i, s[i]);
		i++;
	}
	ret_arr[i] = '\0';
	return (ret_arr);
}
