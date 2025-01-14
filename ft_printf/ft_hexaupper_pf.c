/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexaupper_pf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brogalsk <brogalsk@student.42warsaw.p      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 10:25:10 by brogalsk          #+#    #+#             */
/*   Updated: 2024/03/25 14:30:27 by brogalsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_hexa(unsigned int b, size_t *counter)
{
	static char	hexaupper[] = "0123456789ABCDEF";

	if (b >= 16)
		ft_hexa(b / 16, counter);
	ft_putchar_pf(hexaupper[b % 16], counter);
}

void	ft_hexaupper_pf(unsigned int b, size_t *counter)
{
	ft_hexa(b, counter);
}
