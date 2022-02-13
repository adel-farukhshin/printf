/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_ad.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsarai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 22:18:56 by bsarai            #+#    #+#             */
/*   Updated: 2021/12/11 22:18:57 by bsarai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include <unistd.h>

void	ft_put_ad(t_conv_spec *set)
{
	unsigned long	address;
	int				len;

	len = 3;
	address = va_arg(set->args, unsigned long);
	if (address)
	{
		len = ft_len_hx(address);
		if (set->wdt > len + 2 && !set->min)
			set->p_b += ft_printf_spaces(set, (set->wdt - len - 2));
		set->p_b += write(1, "0x", 2);
		ft_printf_hx(set, address, 'x');
		if (set->wdt > len + 2 && set->min)
			set->p_b += ft_printf_spaces(set, (set->wdt - len - 2));
	}
	else
	{
		if (set->wdt > len && !set->min)
			set->p_b += ft_printf_spaces(set, (set->wdt - len));
		set->p_b += write(1, "0x0", 3);
		if (set->wdt > len && set->min)
			set->p_b += ft_printf_spaces(set, (set->wdt - len));
	}
}
