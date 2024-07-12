/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niabraha <niabraha@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 10:49:57 by niabraha          #+#    #+#             */
/*   Updated: 2023/11/09 17:27:45 by niabraha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned const char	*src;
	unsigned const char	*dest;

	src = (unsigned const char *) s1;
	dest = (unsigned const char *) s2;
	while (n--)
	{
		if (*src != *dest)
			return (*src - *dest);
		src++;
		dest++;
	}
	return (0);
}
