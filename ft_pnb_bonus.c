/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pnb.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsarai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 18:07:34 by bsarai            #+#    #+#             */
/*   Updated: 2021/12/06 18:07:36 by bsarai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static long int	ft_negative(t_conv_spec *set, long int nb);
static void		ft_double_zero(t_conv_spec *set);
static void		ft_flag_min(t_conv_spec *set, long int nb, int len);
static void		ft_put_zeros(t_conv_spec *set, int len);

void	ft_put_d(t_conv_spec *set)
{
	long int	nb;
	int			len;

	nb = va_arg(set->args, int);
	if (set->s_prec && !set->prec && !nb)
		ft_double_zero(set);
	nb = ft_negative(set, nb);
	set->wdt = set->wdt - set->plus - set->negative;
	len = ft_len_d(nb);
	if (!(set->s_prec && !set->prec && !nb))
	{
		if (set->wdt > ft_max(len, set->prec)
			&& !set->min && !(set->zero && !set->s_prec))
			set->p_b += ft_printf_spaces(set,
					(set->wdt - ft_max(len, set->prec)));
		else if (set->sp && !set->plus && !set->negative)
			set->p_b += ft_printf_spaces(set, 1);
		set->p_b += ft_printf_sign(set);
		ft_put_zeros(set, len);
		ft_printf_sd(set, nb);
	}
	if (set->min)
		ft_flag_min(set, nb, len);
}

static void	ft_put_zeros(t_conv_spec *set, int len)
{
	if (set->prec > len && !(set->zero && !set->s_prec))
		set->p_b += ft_printf_zeros(set, (set->prec - len));
	else if (set->zero && !set->prec
		&& !set->exp_zero && !set->min && set->wdt > len)
		set->p_b += ft_printf_zeros(set, (set->wdt - len));
}

static void	ft_double_zero(t_conv_spec *set)
{
	if (set->plus && set->wdt)
		set->wdt--;
	if (!set->min)
		set->p_b += ft_printf_spaces(set, (set->wdt));
	set->p_b += ft_printf_sign(set);
}

static long int	ft_negative(t_conv_spec *set, long int nb)
{
	if (nb < 0)
	{
		set->negative = 1;
		set->plus = 0;
		return (nb * -1);
	}
	else
		return (nb);
}

static void	ft_flag_min(t_conv_spec *set, long int nb, int len)
{
	if (set->s_prec && !set->prec && !nb)
		set->p_b += ft_printf_spaces(set, (set->wdt));
	else if (set->wdt > ft_max(len, set->prec))
		set->p_b += ft_printf_spaces(set, (set->wdt - ft_max(len, set->prec)));
}
