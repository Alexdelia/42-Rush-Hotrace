/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 18:50:27 by adelille          #+#    #+#             */
/*   Updated: 2021/12/11 17:48:05 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/hotrace.h"

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
		while (tmp && tmp->value)
		{
			if (ft_strcmp(tmp->keyword, line) == 0)
			{
				if (!tmp->value[0])
					print(line, size, NULL, 0);
				else
					print(NULL, 0, tmp->value, tmp->val_len);
				break ;
			}
			tmp = tmp->next;
		}
		if (!tmp || !tmp->value)
			print(line, size, NULL, 0);
		free(line);
		line = gnl(&size);
	}
	return (true);
}
