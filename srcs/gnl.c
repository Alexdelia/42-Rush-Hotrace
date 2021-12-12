/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 19:10:06 by adelille          #+#    #+#             */
/*   Updated: 2021/12/12 19:21:19 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/hotrace.h"

static ssize_t	ft_n(const char *str)
{
	ssize_t	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
		return (-1);
	return (i);
}

static char	*calc_size(char *line, size_t *size, size_t *index, const ssize_t n)
{
	if (!line)
		return (NULL);
	*index += n + 1;
	*size = ft_strlen(line);
	return (line);
}

static char	*reading(char *buffer, size_t *index, char *line, size_t *size)
{
	ssize_t	res;
	ssize_t	n;

	res = 1;
	while (res > 0 && line)
	{
		n = ft_n(&buffer[*index]);
		if (n > -1)
		{
			line = ft_strjoin_n_free(line, size, &buffer[*index], n);
			return (calc_size(line, size, index, n));
		}
		else
		{
			line = ft_strjoin_n_free(line, size, &buffer[*index], BUFFER_SIZE);
			res = read(0, buffer, BUFFER_SIZE);
			buffer[res] = '\0';
			*index = 0;
		}
	}
	free(buffer);
	free(line);
	return (NULL);
}

char	*gnl(size_t *size)
{
	static char		*buffer = NULL;
	static size_t	index = 0;
	char			*line;
	ssize_t			res;

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
	if (buffer[0] == '\0')
	{
		res = read(0, buffer, BUFFER_SIZE);
		buffer[res] = '\0';
	}
	return (reading(buffer, &index, line, size));
}
