/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_check.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsarai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 13:06:51 by bsarai            #+#    #+#             */
/*   Updated: 2021/12/12 13:06:54 by bsarai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned int	ft_ctoi(const char *str, int *i)
{
	int	nb;
	int	c;

	nb = 0;
	c = 0;
	while (str[c] >= '0' && str[c] <= '9')
	{
		nb = nb * 10 + (str[c] - 48);
		c++;
	}
	*i += c;
	return (nb);
}

static int	ft_flag_check(t_conv_spec *set, const char *format)
{
	int	i;

	i = 0;
	while (format[i] == '#' || format[i]
		== ' ' || format[i] == '-' || format[i] == '+' || format[i] == '0')
	{
		if (format[i] == '#')
			set->htag = 1;
		else if (format[i] == ' ')
			set->sp = 1;
		else if (format[i] == '-')
			set->min = 1;
		else if (format[i] == '+')
			set->plus = 1;
		else if (format[i] == '0')
			set->zero = 1;
		i++;
	}
	return (i);
}

static int	ft_precision(t_conv_spec *set, const char *format, int i)
{
	unsigned int	nb;

	i++;
	set->s_prec = 1;
	if (format[i] >= '0' && format[i] <= '9')
	{	
		nb = ft_ctoi(format + i, &i);
		set->prec = nb;
		if (set->prec == 0)
			set->exp_zero = 1;
	}
	return (i);
}

int	ft_conversion_check(const char *format, t_conv_spec *set)
{
	unsigned int	nb;
	int				i;

	i = 0;
	if (format[i] == '%')
	{
		set->percent = 1;
		i++;
	}
	else
	{
		i = ft_flag_check(set, format);
		if (format[i] >= '0' && format[i] <= '9')
		{
			nb = ft_ctoi(format + i, &i);
			set->wdt = nb;
		}
		if (format[i] == '.')
			i = ft_precision(set, format, i);
	}
	set->index_f += i;
	i = ft_printf_general((format + i), set);
	return (i);
}
