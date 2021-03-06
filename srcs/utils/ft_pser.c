/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pser.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 16:02:03 by adelille          #+#    #+#             */
/*   Updated: 2021/12/12 19:21:06 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/hotrace.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

bool	ft_pser(const char *str)
{
	(void)!write(2, str, ft_strlen(str));
	return (false);
}
