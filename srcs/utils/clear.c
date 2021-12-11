/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 22:26:28 by adelille          #+#    #+#             */
/*   Updated: 2021/12/11 17:35:07 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/hotrace.h"

static void	clear_chain(t_item *current)
{
	t_item	*tmp;

	while (current && current->next)
	{
		tmp = current;
		current = current->next;
		free(tmp->keyword);
		free(tmp->value);
	}
	free(current->keyword);
	free(current->value);
}

int	clear(int ret)
{
	t_hl	*last;
	t_hl	*current;

	if (g_d.hl)
	{
		last = g_d.hl;
		current = g_d.hl->next;
		while (current)
		{
			clear_chain(&g_d.tab[last->hash]);
			free(last);
			last = current;
			current = current->next;
		}
		clear_chain(&g_d.tab[last->hash]);
		free(last);
	}
	free(g_d.tab);
	return (ret);
}
