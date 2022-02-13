/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsarai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 11:37:25 by bsarai            #+#    #+#             */
/*   Updated: 2021/11/29 11:37:26 by bsarai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
#include <stdlib.h>

static int	ft_write(t_conv_spec *set, const char *format)
{
	int	i;
	int	p_bytes;

	p_bytes = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			p_bytes += ft_conversion_check((format + i + 1), set);
			i += set->index_f;
			p_bytes += set->p_b;
			ft_initialize(set);
		}
		else
			p_bytes += write(1, format + i, 1);
		if (p_bytes == -1)
		{
			free(set);
			return (-1);
		}
		i++;
	}
	return (p_bytes);
}

int	ft_printf(const char *format, ...)
{
	int			p_bytes;
	t_conv_spec	*set;
	int			i;

	i = 0;
	set = (t_conv_spec *) malloc(sizeof(t_conv_spec));
	if (!set)
		return (-1);
	va_start(set->args, format);
	p_bytes = 0;
	ft_initialize(set);
	p_bytes = ft_write(set, format);
	if (p_bytes == -1)
		return (-1);
	va_end(set->args);
	free(set);
	return (p_bytes);
}
