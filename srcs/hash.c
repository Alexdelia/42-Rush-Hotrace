/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 18:20:43 by adelille          #+#    #+#             */
/*   Updated: 2021/12/09 18:30:03 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/hotrace.h"

size_t	get_hash(const char *tag)
{
	size_t	hash;
	size_t	i;
	int		c;

	hash = HASH;
	i = 0;
	while (tag[i])
	{
		c = tag[i];
		i++;
		hash = ((hash << 5) + hash) + c;
	}
	hash %= TABLE_SIZE;
	return (hash);
}
