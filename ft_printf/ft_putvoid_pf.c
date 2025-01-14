/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putvoid_pf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brogalsk <brogalsk@student.42warsaw.p      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 17:16:41 by brogalsk          #+#    #+#             */
/*   Updated: 2024/03/25 14:24:52 by brogalsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	put_void(unsigned long long s, size_t *counter)
{
	static char	digits[] = "0123456789abcdef";

	if (s >= 16)
		put_void(s / 16, counter);
	ft_putchar_pf(digits[s % 16], counter);
}

void	ft_putvoid_pf(void *s, size_t *counter)
{
	if (!s)
	{
		write(1, "(nil)", 5);
		*counter += 5;
	}
	else
	{
		write(1, "0x", 2);
		put_void((unsigned long long)s, counter);
		*counter += 2;
	}
}
