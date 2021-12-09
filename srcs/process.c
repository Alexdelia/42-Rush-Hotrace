/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 18:50:27 by adelille          #+#    #+#             */
/*   Updated: 2021/12/09 22:45:52 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/hotrace.h"

static size_t	ft_strcpy_n(char *line)
{
	size_t	i;

	i = 0;
	while (g_d.stdin[g_d.i] && g_d.stdin[g_d.i] != '\n')
	{
		line[i] = g_d.stdin[g_d.i];
		g_d.i++;
		i++;
	}
	line[i] = '\0';
	if (g_d.stdin[g_d.i])
		g_d.i++;
	return (i);
}

void	process(void)
{
	char	line[1024];
	size_t	size;
	size_t	hash;
	t_item	*tmp;

	while (g_d.stdin[g_d.i])
	{
		size = ft_strcpy_n(line);
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
	}
}
