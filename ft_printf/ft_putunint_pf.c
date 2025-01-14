/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunint_pf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brogalsk <brogalsk@student.42warsaw.p      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 10:25:32 by brogalsk          #+#    #+#             */
/*   Updated: 2024/03/25 14:15:25 by brogalsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	put_unint(unsigned int b, size_t *counter)
{
	static char	digits[] = "0123456789";

	if (b > 9)
		put_unint(b / 10, counter);
	ft_putchar_pf(digits[b % 10], counter);
}

void	ft_putunint_pf(unsigned int b, size_t *counter)
{
	put_unint(b, counter);
}
