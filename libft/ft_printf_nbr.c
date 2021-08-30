/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guferrei <guferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 13:41:02 by guferrei          #+#    #+#             */
/*   Updated: 2021/07/22 11:16:33 by guferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_int(int i)
{
	int				size;
	unsigned int	u;

	size = ft_nbrlen((long long)i, 10);
	if (i < 0)
	{
		write (1, "-", 1);
		u = i * -1;
		if (!t_flags.isDot)
			size++;
	}
	else
	{
		print_signal();
		if (!t_flags.isDot && (t_flags.isSignal || t_flags.isSpace))
			size++;
		u = i;
	}
	if (t_flags.isDot && t_flags.precision == 0 && i == 0)
		return ;
	if (size < t_flags.precision)
		print_width((t_flags.precision - size), '0');
	ft_putuns_fd(u, 1);
}

void	print_hexa(unsigned int i, char x)
{
	int	size;

	if (t_flags.isDot && t_flags.precision == 0 && i == 0)
		return ;
	size = ft_nbrlen((long long )i, 16);
	if (t_flags.isHash && i > 0)
	{
		write (1, "0", 1);
		write (1, &x, 1);
		if (!t_flags.isDot)
			size += 2;
	}
	if (t_flags.precision > size)
		print_width((t_flags.precision - size), '0');
	ft_putnbrX(i, x);
}

int	int_type(va_list args)
{
	int	i;
	int	size;

	i = va_arg(args, int);
	size = ft_nbrlen((long long)i, 10);
	if ((t_flags.precision > size) || (t_flags.isDot && i == 0))
		size = t_flags.precision;
	if (t_flags.isSpace || t_flags.isSignal || i < 0)
		size++;
	if (t_flags.width > size)
	{
		if (t_flags.isMinus)
		{
			print_int(i);
			print_width((t_flags.width - size), ' ');
			return (t_flags.width);
		}
		else if (t_flags.isZero && !t_flags.isDot)
			t_flags.precision += t_flags.width;
		else
			print_width((t_flags.width - size), ' ');
		size = t_flags.width;
	}
	print_int(i);
	return (size);
}

int	unsigned_type(va_list args)
{
	unsigned int	u;
	int				size;

	u = va_arg(args, unsigned int);
	size = ft_nbrlen((long long )u, 10);
	if ((t_flags.precision > size) || (t_flags.isDot && u == 0))
		size = t_flags.precision;
	if (t_flags.width > size)
	{
		if (t_flags.isMinus)
		{
			print_uns(u);
			print_width((t_flags.width - size), ' ');
			return (t_flags.width);
		}
		else if (t_flags.isZero && !t_flags.isDot)
			print_width((t_flags.width - size), '0');
		else
			print_width((t_flags.width - size), ' ');
		size = t_flags.width;
	}
	print_uns(u);
	return (size);
}

int	hexa_type(va_list args, char x)
{
	unsigned int	i;
	int				size;

	i = va_arg(args, unsigned int);
	size = ft_nbrlen((long long )i, 16);
	if ((t_flags.precision > size) || (t_flags.isDot && i == 0))
		size = t_flags.precision;
	if (t_flags.isHash && i > 0)
		size += 2;
	if (t_flags.width > size)
	{
		if (t_flags.isMinus)
		{
			print_hexa(i, x);
			print_width((t_flags.width - size), ' ');
			return (t_flags.width);
		}
		else if (t_flags.isZero && !t_flags.isDot)
			t_flags.precision = t_flags.width;
		else
			print_width((t_flags.width - size), ' ');
		size = t_flags.width;
	}
	print_hexa(i, x);
	return (size);
}
