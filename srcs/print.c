/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 11:35:54 by adelille          #+#    #+#             */
/*   Updated: 2021/12/08 11:44:17 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/hotrace.h"

static void	ft_putstr(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	write(1, str, i);
}

// might save len from ft_strdup so write don't need to ft_strlen again
/*
static void	ft_putstrn(const char *str, const size_t size)
{
	write(1, str, size);
}
*/

void	print(const char *keyword, const char *value)
{
	if (!value)
	{
		ft_putstr(keyword);
		ft_putstr(": Not found.\n");
	}
	else
	{
		ft_putstr(value);
		write(1, "\n", 1);
	}
}
