/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 18:20:43 by adelille          #+#    #+#             */
/*   Updated: 2021/12/11 19:22:09 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/hotrace.h"

size_t	get_hash(const char *key)
{
	size_t	hash;

	hash = HASH;
	while (*key)
		hash = hash * 101 + *key++;
	return (hash % TABLE_SIZE);
}
