/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niabraha <niabraha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 15:42:22 by niabraha          #+#    #+#             */
/*   Updated: 2024/06/12 18:28:23 by niabraha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putchar_fd_safe(char c, int fd)
{
	if (write(fd, &c, 1) == -1)
		return (-1);
	return (1);
}

int	ft_putstr_safe(char *str)
{
	int	len;

	len = 0;
	while (str[len])
	{
		if (ft_putchar_fd_safe(str[len], 1) == -1)
			return (-1);
		len++;
	}
	return (len);
}

int	ft_putnbr_base(unsigned long nbr, const char *base)
{
	unsigned long	base_len;
	int				nb_len;

	nb_len = 0;
	base_len = ft_strlen(base);
	if (nbr >= base_len)
		nb_len += ft_putnbr_base(nbr / base_len, base);
	nb_len += ft_putchar_fd_safe(base[nbr % base_len], 1);
	return (nb_len);
}
