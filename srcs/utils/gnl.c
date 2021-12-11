/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 16:32:18 by adelille          #+#    #+#             */
/*   Updated: 2021/12/11 17:42:20 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/hotrace.h"

long	ft_n(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
		return (-1);
	return (i);
}

char	*gnl(size_t *size)
{
	static char	*buffer = NULL;
	char		*line;
	long		n;
	size_t		res;

	if (BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer)
	{
		buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buffer)
			return (NULL);
		buffer[0] = '\0';
	}
	line = ft_strdup_n("", 0);
	if (!line)
		return (NULL);
	*size = 0;
	res = 1;
	if (buffer[0] == '\0')
		res = read(0, buffer, BUFFER_SIZE);
	while (res > 0)
	{
		n = ft_n(buffer);
		if (n > -1)
		{
			line = ft_strjoin_n_free(line, size, buffer, n);
			if (!line)
				return (NULL);
			ft_strcpy_n(buffer, &buffer[n + 1], BUFFER_SIZE);
			return (line);
		}
		else
		{
			line = ft_strjoin_n_free(line, size, buffer, BUFFER_SIZE);
			if (!line)
				return (NULL);
			res = read(0, buffer, BUFFER_SIZE);
		}
	}
	free(buffer);
	free(line);
	return (NULL);
}
