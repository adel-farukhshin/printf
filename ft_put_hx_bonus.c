/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsarai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 16:42:33 by bsarai            #+#    #+#             */
/*   Updated: 2021/12/09 16:42:34 by bsarai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include <unistd.h>

static void	ft_flag_min(t_conv_spec *set, unsigned long nb, int len);
static void	ft_put_pref(t_conv_spec *set, char a);
static void	ft_put_zeros(t_conv_spec *set, int len);

void	ft_put_hx(t_conv_spec *set, char a)
{
	unsigned long	nb;
	int				len;

	nb = va_arg(set->args, unsigned int);
	if (set->s_prec && !set->prec && !nb && !set->min)
		set->p_b += ft_printf_spaces(set, (set->wdt));
	len = ft_len_hx(nb);
	if (!(set->s_prec && !set->prec && !nb))
	{
		if (set->htag)
			set->wdt -= 2;
		if (set->wdt > ft_max(len, set->prec)
			&& !set->min && !(set->zero && !set->s_prec))
			set->p_b += ft_printf_spaces(set,
					(set->wdt - ft_max(len, set->prec)));
		if (set->htag && nb)
			ft_put_pref(set, a);
		ft_put_zeros(set, len);
		ft_printf_hx(set, nb, a);
	}
	if (set->min)
		ft_flag_min(set, nb, len);
}

static void	ft_put_pref(t_conv_spec *set, char a)
{
	set->p_b += write(1, "0", 1);
	set->p_b += write(1, &a, 1);
}

static void	ft_flag_min(t_conv_spec *set, unsigned long nb, int len)
{
	if (set->s_prec && !set->prec && !nb)
		set->p_b += ft_printf_spaces(set, (set->wdt));
	else if (set->wdt > ft_max(len, set->prec))
		set->p_b += ft_printf_spaces(set, (set->wdt - ft_max(len, set->prec)));
}

static void	ft_put_zeros(t_conv_spec *set, int len)
{
	if (set->prec > len)
		set->p_b += ft_printf_zeros(set, (set->prec - len));
	else if (set->zero && !set->prec && !set->exp_zero
		&& !set->min && set->wdt > len)
		set->p_b += ft_printf_zeros(set, (set->wdt - len));
}

void	ft_printf_hx(t_conv_spec *set, unsigned long nb, char a)
{
	char	c;

	if (nb < 16)
	{
		if (nb < 10)
			c = nb + 48;
		else if (a == 'x')
			c = nb + 87;
		else if (a == 'X')
			c = nb + 55;
		set->p_b += write(1, &c, 1);
	}
	else
	{
		ft_printf_hx(set, nb / 16, a);
		ft_printf_hx(set, nb % 16, a);
	}
}
