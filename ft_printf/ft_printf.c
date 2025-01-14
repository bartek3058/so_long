/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brogalsk <brogalsk@student.42warsaw.p      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 14:35:39 by brogalsk          #+#    #+#             */
/*   Updated: 2024/03/25 14:26:32 by brogalsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_format(va_list args, char *str, size_t *counter)
{
	if (*str == 'c')
		ft_putchar_pf(va_arg(args, int), counter);
	else if (*str == 's')
		ft_putstr_pf(va_arg(args, char *), counter);
	else if (*str == 'p')
		ft_putvoid_pf(va_arg(args, void *), counter);
	else if (*str == 'd' || *str == 'i')
		ft_putdecimal_pf(va_arg(args, int), counter);
	else if (*str == 'u')
		ft_putunint_pf(va_arg(args, unsigned int), counter);
	else if (*str == 'x')
		ft_hexalower_pf(va_arg(args, unsigned int), counter);
	else if (*str == 'X')
		ft_hexaupper_pf(va_arg(args, unsigned int), counter);
	else if (*str == '%')
		ft_putchar_pf(*str, counter);
}

int	ft_printf(char const *str, ...)
{
	va_list	args;
	size_t	counter;

	if (!str)
		return (0);
	counter = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			ft_format(args, (char *)str, &counter);
		}
		else
			ft_putchar_pf(*str, &counter);
		str++;
	}
	va_end(args);
	return (counter);
}
