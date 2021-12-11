/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 18:50:27 by adelille          #+#    #+#             */
/*   Updated: 2021/12/11 18:47:32 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/hotrace.h"

static void	find_in_list(t_item *list, char *line, size_t size)
{
	while (list && list->value)
	{
		if (ft_strcmp(list->keyword, line) == 0)
		{
			if (!list->value[0])
				print(line, size, NULL, 0);
			else
				print(NULL, 0, list->value, list->val_len);
			break ;
		}
		list = list->next;
	}
}

bool	search(void)
{
	char	*line;
	size_t	size;
	size_t	hash;
	t_item	*tmp;

	line = gnl(&size);
	if (!line)
		return (ft_pser("Error: Malloc failed\n"));
	while (line)
	{
		hash = get_hash(line);
		tmp = &g_d.tab[hash];
		find_in_list(tmp, line, size);
		if (!tmp || !tmp->value)
			print(line, size, NULL, 0);
		free(line);
		line = gnl(&size);
	}
	return (true);
}
