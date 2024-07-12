/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niabraha <niabraha@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:29:36 by niabraha          #+#    #+#             */
/*   Updated: 2023/11/09 17:28:15 by niabraha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*free_tab(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
	return (NULL);
}

static char	*fill_tab(const char *tab, char c)
{
	char	*word;
	size_t	len;

	len = 0;
	while (tab[len] && tab[len] != c)
		len++;
	word = (char *)malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	word[len] = '\0';
	while (len--)
		word[len] = tab[len];
	return (word);
}

static int	count_words(char const *s, char c)
{
	size_t	words;
	int		is_del;

	words = 0;
	is_del = 0;
	while (*s)
	{
		if (*s != c && is_del == 0)
		{
			is_del = 1;
			words++;
		}
		else if (*s == c)
			is_del = 0;
		s++;
	}
	return (words);
}

char	**ft_split(const char *s, char c)
{
	char	**p;
	int		i;
	int		nb_words;
	size_t	len_sub;

	nb_words = count_words(s, c);
	p = (char **)ft_calloc((nb_words + 1), sizeof(char *));
	if (!p || !s)
		return (NULL);
	i = -1;
	while (nb_words > ++i)
	{
		len_sub = 0;
		while (*s == c && *s)
			s++;
		while (s[len_sub] != c && s[len_sub])
			len_sub++;
		p[i] = fill_tab(s, c);
		if (!p[i])
			return (free_tab(p));
		s += len_sub;
	}
	p[i] = NULL;
	return (p);
}
