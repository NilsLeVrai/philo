/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niabraha <niabraha@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 10:34:41 by niabraha          #+#    #+#             */
/*   Updated: 2023/11/09 17:28:20 by niabraha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*p;
	int		compteur;

	compteur = 0;
	p = (char *) malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (!p)
		return (NULL);
	while (*src)
		p[compteur++] = *src++;
	p[compteur] = '\0';
	return (p);
}
