/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niabraha <niabraha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 14:33:36 by niabraha          #+#    #+#             */
/*   Updated: 2024/06/12 15:58:36 by niabraha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	valid_fmt(const char *format)
{
	if (ft_strchr("cspdiuxX%", *format) != NULL)
		return (1);
	return (0);
}

static int	check_args(const char *format, va_list args)
{
	if (*format == 'c')
		return (args_char(args));
	else if (*format == 'd' || *format == 'i')
		return (args_digit(args));
	else if (*format == 'p')
		return (args_pointer(args));
	else if (*format == 's')
		return (args_string(args));
	else if (*format == 'u')
		return (args_unsigned(args));
	else if (*format == 'x')
		return (args_lowerhexa(args));
	else if (*format == 'X')
		return (args_upperhexa(args));
	else if (*format == '%')
		return (args_percent());
	return (0);
}

static int	ft_parser(const char *format, va_list args)
{
	int	write_response;
	int	num_args;

	write_response = 0;
	num_args = 0;
	while (*format)
	{
		if (*format == '%' && *(format + 1) != '\0' && valid_fmt(format + 1))
		{
			write_response = check_args((++format), args);
			if (write_response == -1)
				return (-1);
			num_args += write_response;
		}
		else
		{
			write_response = ft_putchar_fd_safe(*format, 1);
			if (write_response == -1)
				return (-1);
			num_args += write_response;
		}
		++format;
	}
	return (num_args);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		len;

	len = 0;
	if (!format)
		return (-1);
	va_start(args, format);
	len = ft_parser(format, args);
	va_end(args);
	return (len);
}
