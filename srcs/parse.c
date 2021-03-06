/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 22:37:12 by adelille          #+#    #+#             */
/*   Updated: 2021/12/11 22:01:27 by adelille         ###   ########.fr       */
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
			tmp->val_len = l->val_len;
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

static void	add_back_hash(size_t hash, t_hl **last)
{
	if (g_d.hl)
	{
		(*last)->next = new_hash(hash);
		(*last) = (*last)->next;
	}
	else
	{
		g_d.hl = new_hash(hash);
		(*last) = g_d.hl;
	}
}

static bool	add_item(char *keyword, char *value, t_len *l, t_hl **last)
{
	t_item	*tmp;
	size_t	hash;

	hash = get_hash(keyword);
	if (!g_d.tab[hash].value)
	{
		g_d.tab[hash].keyword = keyword;
		g_d.tab[hash].value = value;
		g_d.tab[hash].key_len = l->key_len;
		g_d.tab[hash].val_len = l->val_len;
		add_back_hash(hash, last);
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
	char	*keyword;
	char	*value;
	t_len	l;
	t_hl	*last;

	g_d.hl = NULL;
	last = NULL;
	keyword = gnl(&l.key_len);
	if (!keyword)
		return (ft_pser("Error: Malloc failed\n"));
	while (keyword[0] != '\0')
	{
		value = gnl(&l.val_len);
		if (!value)
			return (ft_pser("Error: Malloc failed\n"));
		if (!add_item(keyword, value, &l, &last))
			return (false);
		keyword = gnl(&l.key_len);
		if (!keyword)
			return (ft_pser("Error: Malloc failed\n"));
	}
	free(keyword);
	return (true);
}
