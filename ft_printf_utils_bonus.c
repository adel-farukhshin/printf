/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsarai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 13:00:01 by bsarai            #+#    #+#             */
/*   Updated: 2021/12/12 13:00:02 by bsarai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf_bonus.h"

void	ft_initialize(t_conv_spec *set)
{
	set->percent = 0;
	set->htag = 0;
	set->sp = 0;
	set->zero = 0;
	set->min = 0;
	set->plus = 0;
	set->wdt = 0;
	set->prec = 0;
	set->s_prec = 0;
	set->exp_zero = 0;
	set->index_f = 0;
	set->negative = 0;
	set->p_b = 0;
	set->error = 0;
}

int	ft_printf_general(const char *format, t_conv_spec *set)
{
	int	i;

	i = 0;
	if (set->percent)
		i = write(1, "%", 1);
	else if (*format == 'c')
		i = ft_printf_char(set);
	else if (*format == 's')
		i = ft_putstr(set);
	else if (*format == 'p')
		ft_put_ad(set);
	else if (*format == 'd' || *format == 'i')
		ft_put_d(set);
	else if (*format == 'u')
		ft_put_u(set);
	else if (*format == 'x' || *format == 'X')
		ft_put_hx(set, *format);
	else
		return (-1);
	if (i == -1)
		set->error = -1;
	if (!set->percent)
		set->index_f += 1;
	return (i);
}
