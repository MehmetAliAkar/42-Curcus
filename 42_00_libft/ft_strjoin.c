/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meakar <meakar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 19:55:35 by meakar            #+#    #+#             */
/*   Updated: 2023/07/15 20:22:03 by meakar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t			s1_len;
	size_t			s2_len;
	size_t			i;
	unsigned char	*new_s;

	i = 0;
	if (!s1 || !s2)
		return (0);
	s1_len = ft_strlen (s1);
	s2_len = ft_strlen (s2);
	new_s = malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!new_s)
		return (NULL);
	while (s1[i])
	{
		new_s[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
		new_s[s1_len++] = s2[i++];
	new_s[s1_len] = '\0';
	return ((char *)new_s);
}
