/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftholoza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 00:04:17 by ftholoza          #+#    #+#             */
/*   Updated: 2023/11/21 13:42:24 by ftholoza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (i);
	while (str[i])
		i++;
	return (i);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*ptr1;
	unsigned char		*ptr2;
	int					i;

	i = 0;
	if (!dest && !src)
		return (NULL);
	ptr1 = (unsigned char *) dest;
	ptr2 = (unsigned char *) src;
	while (n > 0)
	{
		ptr1[i] = ptr2[i];
		i++;
		n--;
	}
	return (dest);
}

void	*ft_memset(void *s, int c, size_t n)
{
	char	*ptr;

	ptr = (char *) s;
	while (n > 0)
	{
		*ptr = c;
		ptr++;
		n--;
	}
	return (s);
}

char	*ft_strjoin(char *rest, char *boeuf)
{
	int		restsize;
	int		boeufsize;
	char	*res;

	if (!rest)
		restsize = 0;
	else
		restsize = ft_strlen(rest);
	boeufsize = ft_strlen(boeuf);
	res = malloc(sizeof (char) * restsize + boeufsize + 1);
	if (!res)
		return (res);
	res[restsize + boeufsize] = '\0';
	ft_memcpy(res, rest, restsize);
	ft_memcpy(res + restsize, boeuf, boeufsize);
	return (res);
}
