/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 10:52:50 by adelille          #+#    #+#             */
/*   Updated: 2021/12/09 19:08:31 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOTRACE_H
# define HOTRACE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>

# define BUFFER_INIT	4095

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	280000
# endif

# ifndef TABLE_SIZE
#  define TABLE_SIZE	100000000
# endif

# define HASH			5381

typedef struct s_item
{
	char			*keyword;
	char			*value;
	size_t			key_len;
	size_t			val_len;
	struct s_item	*next;
}				t_item;

typedef struct s_data
{
	t_item	*tab;
	char	*stdin;
	size_t	i;
}			t_data;

typedef struct s_double_len
{
	size_t	key_len;
	size_t	val_len;
}			t_len;

extern t_data	g_d;

bool	read_stdin(void);
bool	parse(void);
void	process(void);
void	print(const char *line, const size_t size,
		const char *value, const size_t val_len);

size_t	get_hash(const char *tag);
t_item	*new_item(char *keyword, size_t key_len, char *value, size_t val_len);

size_t	ft_strlen(const char *str);
char	*ft_strdup_hotrace(size_t base, const size_t size);
char	*ft_strjoin_hotrace(char *s1, const size_t size1,
			char *s2, const size_t size2);
int		ft_strcmp(const char *s1, const char *s2);
bool	ft_pser(const char *str);

#endif
