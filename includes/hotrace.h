/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 10:52:50 by adelille          #+#    #+#             */
/*   Updated: 2021/12/12 19:20:58 by adelille         ###   ########.fr       */
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
//#  define TABLE_SIZE	100006901
#  define TABLE_SIZE	15999041
# endif

# define HASH			5031

typedef struct s_item
{
	char			*keyword;
	char			*value;
	size_t			key_len;
	size_t			val_len;
	struct s_item	*next;
}				t_item;

typedef struct s_hash_list
{
	size_t				hash;
	struct s_hash_list	*next;
}						t_hl;

typedef struct s_data
{
	t_item	*tab;
	t_hl	*hl;
}			t_data;

typedef struct s_double_len
{
	size_t	key_len;
	size_t	val_len;
}			t_len;

extern t_data	g_d;

char	*gnl(size_t *size);
bool	parse(void);
bool	search(void);
void	print(const char *line, const size_t size,
			const char *value, const size_t val_len);

size_t	get_hash(const char *tag);
t_hl	*new_hash(size_t hash);
t_item	*new_item(char *keyword, size_t key_len, char *value, size_t val_len);
int		clear(int ret);

char	*ft_strdup_n(const char *src, const size_t size);
char	*ft_strjoin_n_free(char *s1, size_t *size1,
			const char *s2, const size_t size2);
int		ft_strcmp(const char *s1, const char *s2);
bool	ft_pser(const char *str);
size_t	ft_strlen(const char *str);

#endif
