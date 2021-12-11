/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_hotrace.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 22:26:06 by adelille          #+#    #+#             */
/*   Updated: 2021/12/11 16:59:56 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/hotrace.h"

size_t	ft_strcpy_n(char *dst, const char *src, const size_t size)
{
	size_t	i;

	i = 0;
	while (i < size && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (i);
}

char	*ft_strjoin_n_free(char *s1, size_t *size1,
		const char *s2, const size_t size2)
{
	char	*res;

	res = (char *)malloc(sizeof(char) * (*size1 + size2 + 1));
	if (!res)
		return (NULL);
	ft_strcpy_n(res, s1, *size1);
	*size1 = ft_strcpy_n(&res[*size1], s2, size2);
	free(s1);
	return (res);
}

char	*ft_strjoin_hotrace(char *s1, const size_t size1,
		char *s2, const size_t size2)
{
	char	*res;

	res = (char *)malloc(sizeof(char) * (size1 + size2 + 1));
	if (!res)
		return (NULL);
	ft_strcpy_n(res, s1, size1);
	ft_strcpy_n(&res[size1], s2, size2);
	free(s1);
	return (res);
}
