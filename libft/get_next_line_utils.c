/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guferrei <guferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 18:48:51 by guferrei          #+#    #+#             */
/*   Updated: 2021/08/26 12:23:06 by guferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "libft.h"

char	*safety_first(int fd, char **ptr)
{
	char	*buffer;

	if (fd < 0 || !ptr)
		return (NULL);
	buffer = malloc(2 * sizeof(char));
	if (!buffer)
		return (NULL);
	else
	{
		*buffer = '\0';
		return (buffer);
	}
}

int	gnl_strchr(char *ptr)
{
	while (ptr && *ptr)
	{
		if (*ptr == '\n')
			return (-1);
		else
			ptr++;
	}
	return (1);
}

int	gnl_strlen(char *str)
{
	int	c;

	if (!str)
		return (0);
	c = 0;
	while (*(str + c))
		c++;
	return (c);
}

void	gnl_strcpy(char *src, char *dest)
{
	while (*src)
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
}

char	*gnl_strjoin(char *src, char **dest)
{
	char	*new_dest;
	int		i;
	int		c;

	i = gnl_strlen(src) + gnl_strlen(*dest) + 1;
	c = 0;
	new_dest = malloc(i * sizeof(char));
	if (!new_dest)
	{
		free (*dest);
		return (NULL);
	}
	if (*dest)
	{
		gnl_strcpy(*dest, new_dest);
		while (*(new_dest + c))
			c++;
	}
	gnl_strcpy(src, (new_dest + c));
	free (*dest);
	dest = NULL;
	return (new_dest);
}
