/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niabraha <niabraha@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 10:52:10 by niabraha          #+#    #+#             */
/*   Updated: 2023/11/09 17:27:43 by niabraha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*string_char;

	string_char = s;
	while (n > 0)
	{
		if (*string_char == (unsigned char) c)
			return ((unsigned char *) string_char);
		string_char++;
		n--;
	}
	return (NULL);
}
