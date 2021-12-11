/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 10:45:38 by adelille          #+#    #+#             */
/*   Updated: 2021/12/11 20:52:53 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/hotrace.h"

t_data	g_d;

int	main(void)
{
	g_d.tab = (t_item *)malloc(sizeof(t_item) * TABLE_SIZE);
	if (!g_d.tab)
		return (ft_pser("Error: Malloc failed\n") + 1);
	if (!parse())
		return (clear(2));
	if (!search())
		return (clear(3));
	return (clear(0));
}
