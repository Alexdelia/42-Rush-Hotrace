/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 10:45:38 by adelille          #+#    #+#             */
/*   Updated: 2021/12/08 22:39:43 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/hotrace.h"

t_item	*g_tab;

int	main(void)
{
	g_tab = (t_item *)malloc(sizeof(t_item) * TABLE_SIZE);
	if (!g_tab)
		return (1);
	if (!parse()) // might put buffer in param
		return (1);
	process(); // might put buffer in param
	return (0);
}
