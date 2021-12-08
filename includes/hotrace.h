/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 10:52:50 by adelille          #+#    #+#             */
/*   Updated: 2021/12/08 22:36:40 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOTRACE_H
# define HOTRACE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 280000
# endif

# ifndef TABLE_SIZE
#  define TABLE_SIZE 100000000
# endif

typedef struct	s_item
{
	char			*keyword;
	char			*value;
	size_t			key_len;
	size_t			val_len;
	struct s_item	*next;
}				t_item;

extern t_item	*g_tab;

// will get len in read
t_item	*new_item(char *keyword, size_t key_len, char *value, size_t val_len);

size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *src); // might save ft_strlen in t_item // might get and save ft_strlen before
int		ft_strcmp(const char *s1, const char *s2);

#endif
