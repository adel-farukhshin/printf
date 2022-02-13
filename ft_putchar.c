/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsarai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 19:12:00 by bsarai            #+#    #+#             */
/*   Updated: 2021/12/11 19:12:01 by bsarai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	ft_printf_char(t_conv_spec *set)
{
	int		p_bytes;
	char	a;

	p_bytes = 0;
	a = va_arg(set->args, int);
	if (set->wdt > 1 && !set->min)
		p_bytes += ft_printf_spaces(set, (set->wdt - 1));
	if (p_bytes == -1)
		return (-1);
	p_bytes += write(1, &a, 1);
	if (set->wdt > 1 && set->min)
		p_bytes += ft_printf_spaces(set, (set->wdt - 1));
	return (p_bytes);
}
