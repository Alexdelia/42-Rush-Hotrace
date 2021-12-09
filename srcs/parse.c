/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 22:37:12 by adelille          #+#    #+#             */
/*   Updated: 2021/12/09 16:50:23 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/hotrace.h"

// check format: keyword\nvalue\n
// store in t_item with len
// when \n\n, return index or address_index of buffer

// start process // will hash somewhere

// will expect to have good input
Bool	parse(void)
{
	size_t	base;
	size_t	key_len;
	size_t	val_len;

	g_d.i = 0;
	while (g_d.stdin[g_d.i] && g_d.stdin[g_d.i] != '\n')
	{
		base = g_d.i;
		key_len = g_d.i;
		while (g_d.stdin[key_len] && g_d.stdin[key_len] != '\n')
			key_len++;
		val_len = key_len + 1;
		while (g_d.stdin[val_len] && g_d.stdin[val_len] != '\n')
			val_len++;
		if (!add_item(base, key_len, val_len))
			return (false);
		g_d.i = val_len + 1;
	}
	g_d.i++; // jumping over second \n
	return (true);
}
