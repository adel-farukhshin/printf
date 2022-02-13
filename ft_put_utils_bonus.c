/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsarai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 11:58:49 by bsarai            #+#    #+#             */
/*   Updated: 2021/12/07 11:58:51 by bsarai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include <unistd.h>

int	ft_len_d(int nb)
{
	int	i;

	i = 1;
	while (nb / 10 != 0)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

int	ft_len_ud(unsigned int nb)
{
	int	i;

	i = 1;
	while (nb / 10 != 0)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

int	ft_len_hx(unsigned long nb)
{
	int	i;

	i = 1;
	while (nb / 16 != 0)
	{
		nb /= 16;
		i++;
	}
	return (i);
}

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

void	ft_printf_sd(t_conv_spec *set, long int nb)
{
	char	c;

	if (nb < 10)
	{
		c = nb + 48;
		set->p_b += write(1, &c, 1);
	}
	else
	{
		ft_printf_sd(set, nb / 10);
		ft_printf_sd(set, nb % 10);
	}
}
