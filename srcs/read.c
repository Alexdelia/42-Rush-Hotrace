/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 11:51:51 by adelille          #+#    #+#             */
/*   Updated: 2021/12/08 22:48:02 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/hotrace.h"

// read all buffer
// check format: keyword\nvalue\n
// store in t_item with len
// when \n\n, return index or address_index of buffer

// start process // will hash somewhere

char	*read_items(void)
{
	// if use on stack, need to be define in main and put in param
	char	buffer[BUFFER_SIZE + 1]; // might put on heap
	size_t	i;

	//

	return (&buffer[i]); // if malloc, need to test if return is null in main
}
