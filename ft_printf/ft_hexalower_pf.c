/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexalower_pf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brogalsk <brogalsk@student.42warsaw.p      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 10:24:34 by brogalsk          #+#    #+#             */
/*   Updated: 2024/03/25 10:24:41 by brogalsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_hexa(unsigned int b, size_t *counter)
{
	static char	hexalower[] = "0123456789abcdef";

	if (b >= 16)
		ft_hexa(b / 16, counter);
	ft_putchar_pf(hexalower[b % 16], counter);
}

void	ft_hexalower_pf(unsigned int b, size_t *counter)
{
	ft_hexa(b, counter);
}
