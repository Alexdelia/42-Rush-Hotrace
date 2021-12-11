/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 16:46:28 by adelille          #+#    #+#             */
/*   Updated: 2021/12/11 17:34:46 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/hotrace.h"

char	*ft_strdup_n(const char *src, const size_t size)
{
	char	*res;
	size_t	i;

	res = (char *)malloc(sizeof(char) * (size + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (i < size)
	{
		res[i] = src[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

/*char	*ft_strdup_hotrace(size_t base, const size_t size)
{
	char	*str;
	size_t	i;

	str = (char *)malloc(sizeof(char) * (size - base + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (base < size)
	{
		str[i] = g_d.stdin[base];
		i++;
		base++;
	}
	str[i] = '\0';
	return (str);
}*/
