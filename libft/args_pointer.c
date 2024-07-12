/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_pointer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niabraha <niabraha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 23:30:02 by niabraha          #+#    #+#             */
/*   Updated: 2024/06/12 15:58:36 by niabraha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	args_pointer(va_list args)
{
	void	*adr;

	adr = va_arg(args, void *);
	if (adr == 0)
		return (ft_putstr_safe("(nil)"));
	ft_putstr_safe("0x");
	return (ft_putnbr_base((unsigned long)adr, "0123456789abcdef") + 2);
}
