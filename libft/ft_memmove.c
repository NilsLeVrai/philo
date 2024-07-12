/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niabraha <niabraha@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:21:24 by niabraha          #+#    #+#             */
/*   Updated: 2023/11/09 17:31:49 by niabraha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*dest_ptr;
	unsigned const char	*src_ptr;

	dest_ptr = (unsigned char *) dest;
	src_ptr = (unsigned const char *) src;
	if (dest_ptr <= src_ptr)
		ft_memcpy(dest_ptr, src_ptr, n);
	else if (dest_ptr > src_ptr)
	{
		while (n--)
			dest_ptr[n] = src_ptr[n];
	}
	return (dest_ptr);
}
