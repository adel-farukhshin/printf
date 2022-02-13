/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsarai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 20:42:35 by bsarai            #+#    #+#             */
/*   Updated: 2021/12/11 20:42:37 by bsarai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

static void	ft_flag_min(t_conv_spec *set, unsigned int nb, int len);

void	ft_put_u(t_conv_spec *set)
{
	unsigned int	nb;
	int				len;

	nb = va_arg(set->args, unsigned int);
	if (set->s_prec && !set->prec && !nb && !set->min)
		set->p_b += ft_printf_spaces(set, (set->wdt));
	len = ft_len_ud(nb);
	if (!(set->s_prec && !set->prec && !nb))
	{
		if (set->wdt > ft_max(len, set->prec)
			&& !set->min && !(set->zero && !set->s_prec))
			set->p_b += ft_printf_spaces(set,
					(set->wdt - ft_max(len, set->prec)));
		if (set->prec > len && !(set->zero && !set->s_prec))
			set->p_b += ft_printf_zeros(set, (set->prec - len));
		else if (set->zero && !set->prec
			&& !set->exp_zero && !set->min && set->wdt > len)
			set->p_b += ft_printf_zeros(set, (set->wdt - len));
		ft_printf_sd(set, nb);
	}
	if (set->min)
		ft_flag_min(set, nb, len);
}

static void	ft_flag_min(t_conv_spec *set, unsigned int nb, int len)
{
	if (set->s_prec && !set->prec && !nb)
		set->p_b += ft_printf_spaces(set, (set->wdt));
	else if (set->wdt > ft_max(len, set->prec))
		set->p_b += ft_printf_spaces(set, (set->wdt - ft_max(len, set->prec)));
}
