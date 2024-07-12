/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niabraha <niabraha@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 17:07:12 by niabraha          #+#    #+#             */
/*   Updated: 2023/11/09 17:28:56 by niabraha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	char_find;
	int				len;

	char_find = (unsigned char) c;
	len = ft_strlen(s);
	while (len >= 0)
	{
		if (s[len] == char_find)
			return ((char *) &s[len]);
		len--;
	}
	return (NULL);
}
