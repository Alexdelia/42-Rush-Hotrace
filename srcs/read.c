/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 11:51:51 by adelille          #+#    #+#             */
/*   Updated: 2021/12/09 16:31:22 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/hotrace.h"

static bool	read_big_stdin(ssize_t size)
{
	char	*buffer;
	ssize_t	ret;

	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (ft_pser("Error: Malloc failed\n"));
	ret = read(0, buffer, BUFFER_SIZE);
	buffer[ret] = '\0';
	while (ret != 0 && ret != EOF)
	{
		d.stdin = ft_strjoin_hotrace(d.stdin, size, buffer, BUFFER_SIZE);
		if (!d.stdin)
			return (ft_pser("Error: Malloc failed\n"));
		size += ret;
		ret = read(0, buffer, BUFFER_SIZE);
		buffer[ret] = '\0';
	}
	free(buffer);
	return (true);
}

bool	read_stdin(void)
{
	ssize_t		ret;

	d.stdin = (char *)malloc(sizeof(char) * BUFFER_INIT + 1);
	if (!d.stdin)
		return (ft_pser("Error: Malloc failed\n"));
	ret = read(0, d.stdin, BUFFER_INIT);
	d.stdin[ret] = '\0';
	if (ret != 0 && ret != EOF)
		if (!read_big_stdin(ret))
			return (false);
	return (true);
}
