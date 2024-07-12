/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niabraha <niabraha@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 09:56:17 by niabraha          #+#    #+#             */
/*   Updated: 2023/11/09 17:29:02 by niabraha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	unsigned char	*char1;
	unsigned char	*char2;

	char1 = (unsigned char *) s1;
	char2 = (unsigned char *) s2;
	if (n == 0)
		return (0);
	i = 0;
	while (n - 1 > i && char1[i] == char2[i])
	{
		if (char1[i] != char2[i])
			return (char1[i] - char2[i]);
		else if (char1[i] == '\0' || char2[i] == '\0')
			return (char1[i] - char2[i]);
		i++;
	}
	return (char1[i] - char2[i]);
}
