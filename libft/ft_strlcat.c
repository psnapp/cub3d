/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psnapp <psnapp@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 15:30:23 by psnapp            #+#    #+#             */
/*   Updated: 2020/11/04 09:54:35 by psnapp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dst_l;
	size_t	src_l;

	i = 0;
	src_l = ft_strlen(src);
	while (*dst && i < size)
	{
		i++;
		dst++;
	}
	dst_l = i;
	if (size != 0)
	{
		while (*src && i < (size - 1))
		{
			*dst = *src;
			i++;
			dst++;
			src++;
		}
	}
	if (i < size)
		*dst = '\0';
	return (dst_l + src_l);
}
