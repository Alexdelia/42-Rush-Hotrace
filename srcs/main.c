/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 10:45:38 by adelille          #+#    #+#             */
/*   Updated: 2021/12/09 16:14:16 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/hotrace.h"

t_data	d;

int	main(void)
{
	size_t	i;

	d.tab = (t_item *)malloc(sizeof(t_item) * TABLE_SIZE);
	if (!d.tab)
		return (1);
	i = parse();
	if (i == 0)
		return (1);
	process(/*i*/);
	return (0);
}
