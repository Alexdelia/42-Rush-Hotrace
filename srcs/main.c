/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 10:45:38 by adelille          #+#    #+#             */
/*   Updated: 2021/12/09 22:27:40 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/hotrace.h"

t_data	g_d;

// clear function free items, tab, g_d.stdin

int	main(void)
{
	g_d.stdin = NULL;
	g_d.tab = (t_item *)malloc(sizeof(t_item) * TABLE_SIZE);
	if (!g_d.tab)
		return (ft_pser("Error: Malloc failed\n") + 1);
	if (!read_stdin())
		return (clear(1));
	if (!parse())
		return (clear(2));
	process();
	return (clear(0));
}
