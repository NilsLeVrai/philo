/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niabraha <niabraha@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 16:39:23 by niabraha          #+#    #+#             */
/*   Updated: 2023/11/09 17:28:53 by niabraha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t n)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(little);
	if (len == 0 || !little)
		return ((char *)big);
	while (i < n && big[i] != '\0')
	{
		if (ft_strncmp(&big[i], little, len) == 0 && little [0] == big[i])
		{
			if (i + len > n)
				return (NULL);
			return ((char *)&big[i]);
		}
		i++;
	}
	return (NULL);
}
