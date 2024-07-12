/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niabraha <niabraha@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 17:07:12 by niabraha          #+#    #+#             */
/*   Updated: 2023/11/09 17:28:17 by niabraha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned int		i;
	unsigned char		char_find;
	size_t				len;

	char_find = (unsigned char) c;
	i = 0;
	len = (size_t) ft_strlen(s);
	while (i <= (unsigned int) len)
	{
		if (s[i] == char_find)
			return ((char *) &s[i]);
		i++;
	}
	return (NULL);
}
