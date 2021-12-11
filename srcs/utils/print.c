/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 11:35:54 by adelille          #+#    #+#             */
/*   Updated: 2021/12/11 20:46:53 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/hotrace.h"

void	print(const char *line, const size_t size,
		const char *value, const size_t val_len)
{
	if (line)
	{
		(void)!write(1, line, size);
		(void)!write(1, ": Not found.\n", 13);
	}
	else if (value)
	{
		(void)!write(1, value, val_len);
		(void)!write(1, "\n", 1);
	}
}
