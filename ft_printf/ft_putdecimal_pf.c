/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdecimal_pf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brogalsk <brogalsk@student.42warsaw.p      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 10:25:46 by brogalsk          #+#    #+#             */
/*   Updated: 2024/03/25 10:48:50 by brogalsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*static size_t	i_digits(int a)
{
	size_t len;

	len = 0;
	if (a < 0)
	{
		len += 1;
		len *= -1;
	}
	if (a == 0)
		len++;
	while (a > 0)
	{
		a /= 10;
		len++;
	}
	return (len);
}*/

static void	put_int(int a, size_t *counter)
{
	static char	digits[] = "0123456789";

	if (a > 9)
		put_int(a / 10, counter);
	if (a >= 0)
		ft_putchar_pf(digits[a % 10], counter);
}

void	ft_putdecimal_pf(int a, size_t *counter)
{
	if (a == INT_MIN)
	{
		write(1, "-2147483648", 11);
		*counter += 11;
	}
	else if (a < 0)
	{
		write(1, "-", 1);
		a *= -1;
		(*counter)++;
	}
	put_int(a, counter);
}
