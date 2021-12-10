/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 22:37:12 by adelille          #+#    #+#             */
/*   Updated: 2021/12/10 14:26:18 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/hotrace.h"

static bool	insert(t_item *tmp, char *keyword, char *value, t_len *l)
{
	while (tmp && tmp->value)
	{
		if (ft_strcmp(tmp->keyword, keyword) == 0)
		{
			free(tmp->value);
			free(keyword);
			tmp->value = value;
			tmp->val_len = l->val_len - (l->key_len + 1);
			return (true);
		}
		else if (!tmp->next)
		{
			tmp->next = new_item(keyword, l->key_len, value, l->val_len);
			if (!tmp->next)
			{
				free(keyword);
				free(value);
				return (ft_pser("Error: Malloc failed\n"));
			}
			return (true);
		}
		tmp = tmp->next;
	}
	return (true);
}

static bool	add_item(size_t base, t_len *l)
{
	t_item	*tmp;
	size_t	hash;
	char	*keyword;
	char	*value;

	keyword = ft_strdup_hotrace(base, l->key_len);
	value = ft_strdup_hotrace(l->key_len + 1, l->val_len);
	if (!keyword | !value)
		return (ft_pser("Error: Malloc failed\n"));
	hash = get_hash(keyword);
	if (!g_d.tab[hash].value)
	{
		g_d.tab[hash].keyword = keyword;
		g_d.tab[hash].value = value;
		g_d.tab[hash].key_len = l->key_len - base;
		g_d.tab[hash].val_len = l->val_len - (l->key_len + 1);
		add_back_hash(&g_d.hl, new_hash(hash));
	}
	else
	{
		tmp = &g_d.tab[hash];
		return (insert(tmp, keyword, value, l));
	}
	return (true);
}

bool	parse(void)
{
	size_t	base;
	t_len	l;

	g_d.hl = NULL;
	g_d.i = 0;
	while (g_d.stdin[g_d.i] && g_d.stdin[g_d.i] != '\n')
	{
		base = g_d.i;
		l.key_len = g_d.i;
		while (g_d.stdin[l.key_len] && g_d.stdin[l.key_len] != '\n')
			l.key_len++;
		l.val_len = l.key_len + 1;
		while (g_d.stdin[l.val_len] && g_d.stdin[l.val_len] != '\n')
			l.val_len++;
		if (!add_item(base, &l))
			return (false);
		g_d.i = l.val_len + 1;
	}
	g_d.i++;
	return (true);
}
