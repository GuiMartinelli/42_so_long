/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_chr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guferrei <guferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 10:31:16 by guferrei          #+#    #+#             */
/*   Updated: 2021/07/22 13:55:04 by guferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_ptr(char *ptr)
{
	unsigned long	adress;

	if (t_flags.isDot && t_flags.precision == 0)
	{	
		write (1, "0x", 2);
		return ;
	}
	else
	{
		adress = (unsigned long)ptr;
		ft_put0x(adress, 'x');
	}
}

int	chr_type(char type, va_list args)
{
	char	c;

	if (type == '%')
		c = '%';
	else
		c = va_arg(args, int);
	if (t_flags.width > 1)
	{
		if (t_flags.isMinus)
		{
			write (1, &c, 1);
			print_width((t_flags.width - 1), ' ');
			return (t_flags.width);
		}
		else if (t_flags.isZero)
			print_width((t_flags.width - 1), '0');
		else
			print_width((t_flags.width - 1), ' ');
		write (1, &c, 1);
		return (t_flags.width);
	}
	write (1, &c, 1);
	return (1);
}

int	str_type(va_list args)
{
	int		size;
	char	*ptr;

	ptr = va_arg(args, char *);
	size = ft_printf_strlen((const char *)ptr);
	if (t_flags.isDot && t_flags.precision < size)
		size = t_flags.precision;
	if (t_flags.width > size)
	{
		if (t_flags.isMinus)
		{
			ft_putnstr(ptr, size);
			print_width((t_flags.width - size), ' ');
			return (t_flags.width);
		}
		else if (t_flags.isZero)
			print_width((t_flags.width - size), '0');
		else
			print_width((t_flags.width - size), ' ');
		ft_putnstr(ptr, size);
		size = t_flags.width;
	}
	else
		ft_putnstr(ptr, size);
	return (size);
}

int	ptr_type(va_list args)
{
	char	*ptr;
	int		size;

	ptr = va_arg(args, char *);
	size = 2;
	if (ptr || !(t_flags.isDot && t_flags.precision == 0))
		size += (ft_nbrlen((long long)ptr, 16));
	if (t_flags.width > size)
	{
		if (t_flags.isMinus)
		{
			print_ptr(ptr);
			print_width((t_flags.width - size), ' ');
			return (t_flags.width);
		}
		else if (t_flags.isZero)
			print_width((t_flags.width - size), '0');
		else
			print_width((t_flags.width - size), ' ');
		print_ptr(ptr);
		return (t_flags.width);
	}
	print_ptr(ptr);
	return (size);
}
