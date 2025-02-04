/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brogalsk <brogalsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 14:27:35 by brogalsk          #+#    #+#             */
/*   Updated: 2025/02/03 09:23:28 by brogalsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>
# include <unistd.h>
# include <stdint.h>
# include <stdlib.h>
# include <fcntl.h>

void	ft_hexalower_pf(unsigned int b, size_t *counter);
int		ft_printf(char const *str, ...);
void	ft_putchar_pf(char s, size_t *counter);
void	ft_putstr_pf(char *s, size_t *counter);
void	ft_putvoid_pf(void *s, size_t *counter);
void	ft_hexaupper_pf(unsigned int b, size_t *counter);
void	ft_putdecimal_pf(int a, size_t *counter);
void	ft_putunint_pf(unsigned int b, size_t *counter);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*get_next_line(int fd);

#endif
