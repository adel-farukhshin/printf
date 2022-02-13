/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsarai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 13:05:14 by bsarai            #+#    #+#             */
/*   Updated: 2021/12/12 13:05:15 by bsarai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "ft_printf_bonus.h"

int	ft_printf_spaces(t_conv_spec *set, int q)
{
	int	p_bytes;	

	p_bytes = 0;
	while (q)
	{
		p_bytes += write(1, " ", 1);
		if (p_bytes == -1)
			set->error = -1;
		q--;
	}
	set->wdt = 0;
	return (p_bytes);
}

int	ft_printf_zeros(t_conv_spec *set, int q)
{
	int	p_bytes;

	p_bytes = 0;
	while (q)
	{
		p_bytes += write(1, "0", 1);
		if (p_bytes == -1)
			set->error = -1;
		q--;
	}
	set->exp_zero = 0;
	return (p_bytes);
}

int	ft_printf_sign(t_conv_spec *set)
{
	int	p_bytes;

	p_bytes = 0;
	if (set->negative == 1)
		p_bytes += write(1, "-", 1);
	else if (set->plus == 1)
		p_bytes += write(1, "+", 1);
	if (p_bytes == -1)
		set->error = -1;
	set->negative = 0;
	set->plus = 0;
	return (p_bytes);
}
