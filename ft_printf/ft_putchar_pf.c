/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_pf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brogalsk <brogalsk@student.42warsaw.p      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 16:01:36 by brogalsk          #+#    #+#             */
/*   Updated: 2024/03/25 14:38:16 by brogalsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_pf(char s, size_t *counter)
{
	ft_putchar_fd(s, 1);
	(*counter)++;
}
