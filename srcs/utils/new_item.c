/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_item.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 11:46:02 by adelille          #+#    #+#             */
/*   Updated: 2021/12/08 11:54:19 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/hotrace.h"

t_item	*new_item(char *keyword, size_t key_len, char *value, size_t val_len)
{
	t_item	*new;

	new = (t_item *)malloc(sizeof(t_item));
	if (!new)
		return (NULL);
	new->keyword = ft_strdup(keyword);
	new->value = ft_strdup(value);
	if (!new->keyword || !new->value)
		return (NULL);
	new->key_len = key_len;
	new->val_len = val_len;
	new->next = NULL;
	return (new);
}
