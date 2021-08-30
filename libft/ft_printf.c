/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guferrei <guferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 08:52:26 by guferrei          #+#    #+#             */
/*   Updated: 2021/07/23 08:05:52 by guferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_format(const char *type, va_list args)
{
	int	ret;

	if (*type == '%' || *type == 'c')
		ret = chr_type(*type, args);
	else if (*type == 's')
		ret = str_type(args);
	else if (*type == 'i' || *type == 'd')
		ret = int_type(args);
	else if (*type == 'x' || *type == 'X')
		ret = hexa_type(args, *type);
	else if (*type == 'u')
		ret = unsigned_type(args);
	else if (*type == 'p')
		ret = ptr_type(args);
	else
	{
		write (1, &*type, 1);
		ret = 1;
	}
	return (ret);
}

const char	*get_flags(const char *type)
{
	if (*type == '-')
		t_flags.isMinus = true;
	else if (*type == '0')
		t_flags.isZero = true;
	else if (*type == '.')
	{
		t_flags.isDot = true;
		t_flags.precision = ft_atoi(type);
		while (*(type + 1) >= '0' && *(type + 1) <= '9')
			type++;
	}
	else if (*type == '#')
		t_flags.isHash = true;
	else if (*type == ' ')
		t_flags.isSpace = true;
	else if (*type == '+')
		t_flags.isSignal = true;
	else if (*type >= '1' && *type <= '9')
	{
		t_flags.width = ft_atoi(type);
		while (*(type + 1) >= '0' && *(type + 1) <= '9')
			type++;
	}
	return (type);
}

void	initStruct(void)
{
	t_flags.isDot = false;
	t_flags.isHash = false;
	t_flags.isMinus = false;
	t_flags.isSignal = false;
	t_flags.isSpace = false;
	t_flags.isZero = false;
	t_flags.precision = 0;
	t_flags.width = 0;
}

const char	*get_spec(const char *type)
{
	initStruct();
	while (*type && (*type == '-' || *type == '#'
			|| *type == '.' || *type == ' ' || *type == '+'
			|| (*type >= '0' && *type <= '9')))
	{
		type = get_flags(type);
		type++;
	}
	return (type);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		count;

	va_start(args, str);
	count = 0;
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			str = get_spec(str);
			if (!*str)
				break ;
			count += get_format(str++, args);
		}
		else
		{
			write(1, &*str, 1);
			count++;
			str++;
		}
	}
	va_end(args);
	return (count);
}
