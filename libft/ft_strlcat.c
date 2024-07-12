/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niabraha <niabraha@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 10:34:07 by niabraha          #+#    #+#             */
/*   Updated: 2023/11/09 17:28:22 by niabraha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t	i;
	size_t	len_dest;
	size_t	len_src;

	i = 0;
	len_dest = ft_strlen(dst);
	len_src = ft_strlen(src);
	if (n < len_dest)
		len_src += n;
	else
		len_src += len_dest;
	while (n > len_dest + 1 && src[i])
	{
		dst[len_dest] = src[i];
		len_dest++;
		i++;
	}
	if (n >= len_dest)
		dst[len_dest] = '\0';
	return (len_src);
}
