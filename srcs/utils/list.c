/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 11:46:02 by adelille          #+#    #+#             */
/*   Updated: 2021/12/10 11:21:51 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/hotrace.h"

t_item	*new_item(char *keyword, size_t key_len, char *value, size_t val_len)
{
	t_item	*new;

	new = (t_item *)malloc(sizeof(t_item));
	if (!new)
		return (NULL);
	new->keyword = keyword;
	new->value = value;
	if (!new->keyword || !new->value)
		return (NULL);
	new->key_len = key_len;
	new->val_len = val_len;
	new->next = NULL;
	return (new);
}

t_hl	*new_hash(size_t hash)
{
	t_hl	*new;

	new = (t_hl *)malloc(sizeof(t_hl));
	if (!new)
		return (NULL);
	new->hash = hash;
	new->next = NULL;
	return (new);
}

static t_hl	*last_hash(t_hl *lst)
{
	while (lst)
	{
		if (!lst->next)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

void	add_back_hash(t_hl **alst, t_hl *new)
{
	t_hl	*last;

	if (alst)
	{
		if (*alst)
		{
			last = last_hash(*alst);
			last->next = new;
		}
		else
			*alst = new;
	}
}
