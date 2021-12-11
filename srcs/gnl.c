/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 16:32:18 by adelille          #+#    #+#             */
/*   Updated: 2021/12/11 19:01:05 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/hotrace.h"

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

char	*reading(char *buffer, size_t *index, char *line, size_t *size)
{
	size_t	res;
	long	n;

	res = 1;
	while (res > 0 && line)
	{
		n = ft_n(&buffer[*index]);
		if (n > -1)
		{
			line = ft_strjoin_n_free(line, size, &buffer[*index], n);
			if (!line)
				return (NULL);
			*index += n + 1;
			return (line);
		}
		else
		{
			line = ft_strjoin_n_free(line, size, &buffer[*index], BUFFER_SIZE);
			res = read(0, buffer, BUFFER_SIZE);
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
		(void)!read(0, buffer, BUFFER_SIZE);
	return (reading(buffer, &index, line, size));
}
