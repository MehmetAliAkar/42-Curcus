/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meakar <meakar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 19:02:11 by meakar            #+#    #+#             */
/*   Updated: 2023/07/15 20:22:29 by meakar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret_str;
	size_t	s_len;
	size_t	ret_len;

	if (!s)
		return (0);
	s_len = ft_strlen(s);
	if (s[0] == '\0' || s_len < start)
		return (ft_strdup(""));
	ret_len = 0;
	if (start < s_len)
		ret_len = s_len - start;
	if (ret_len > len)
		ret_len = len;
	ret_str = (char *)malloc(sizeof(char) * (ret_len + 1));
	if (!ret_str)
		return (0);
	ft_strlcpy(ret_str, s + start, ret_len + 1);
	return (ret_str);
}
