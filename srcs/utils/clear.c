/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 22:26:28 by adelille          #+#    #+#             */
/*   Updated: 2021/12/09 23:02:55 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/hotrace.h"

static void	clear_chain(t_item *head)
{
	t_item	*tmp;

	while (head && head->next)
	{
		tmp = head->next;
		while (tmp && tmp->next)
			tmp = tmp->next;
		free(tmp->keyword);
		free(tmp->value);
		free(tmp);
	}
	free(head->keyword);
	free(head->value);
}

// clear take awful time
/*int	clear(int ret)
{
	size_t	i;

	if (g_d.stdin)
	{
		free(g_d.stdin);
		i = 0;
		while (i <= TABLE_SIZE)
		{
			if (&g_d.tab[i] && g_d.tab[i].value)
				clear_chain(&g_d.tab[i]);
			i++;
		}
	}
	free(g_d.tab);
	return (ret);
}*/

int	clear(int ret)
{
	size_t	hash;

	g_d.i = 0;
	while (g_d.stdin[g_d.i] && g_d.stdin[g_d.i] != '\n')
	{
		g_d.i++;
	}
}
