/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsarai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 18:45:02 by bsarai            #+#    #+#             */
/*   Updated: 2021/12/11 18:45:05 by bsarai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include <unistd.h>

static int	ft_strnull(t_conv_spec *set);
static int	ft_flag_min(t_conv_spec *set, int i);
static int	ft_strlen(char *str);

int	ft_putstr(t_conv_spec *set)
{
	char	*str;
	int		i;
	int		p_bytes;

	p_bytes = 0;
	str = va_arg(set->args, char *);
	if (!str)
	{
		p_bytes = ft_strnull(set);
		return (p_bytes);
	}
	i = ft_strlen(str);
	if (set->wdt > i && !set->min)
		p_bytes += ft_printf_spaces(set, (set->wdt - i));
	if (set->s_prec)
		if (set->prec > i)
			p_bytes += write(1, str, i);
	else
		p_bytes += write(1, str, set->prec);
	else
		p_bytes += write(1, str, i);
	if (set->min)
		p_bytes += ft_flag_min(set, i);
	return (p_bytes);
}

static int	ft_strnull(t_conv_spec *set)
{
	int	p_bytes;

	p_bytes = 0;
	if (!set->exp_zero && !set->prec)
		set->prec = 6;
	if (set->wdt > set->prec)
		p_bytes += ft_printf_spaces(set, (set->wdt - set->prec));
	if (set->prec > 6)
		p_bytes += write(1, "(null)", 6);
	else
		p_bytes += write(1, "(null)", set->prec);
	return (p_bytes);
}

static int	ft_flag_min(t_conv_spec *set, int i)
{
	int	p_bytes;

	p_bytes = 0;
	if ((set->prec > i || !set->s_prec) && set->wdt > i)
		p_bytes += ft_printf_spaces(set, (set->wdt - i));
	else if (set->wdt > set->prec && set->s_prec)
		p_bytes += ft_printf_spaces(set, (set->wdt - set->prec));
	return (p_bytes);
}

static int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
