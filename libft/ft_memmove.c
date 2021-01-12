/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psnapp <psnapp@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 11:20:59 by psnapp            #+#    #+#             */
/*   Updated: 2020/11/03 18:17:54 by psnapp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*dst;
	unsigned char	*str;

	dst = (unsigned char*)dest;
	str = (unsigned char*)src;
	if (!dest && !src)
		return (NULL);
	if (n == 0)
		return (dst);
	if (dst > str)
	{
		while (n > 0)
		{
			dst[n - 1] = str[n - 1];
			n--;
		}
	}
	else if (dst < str)
		ft_memcpy(dest, src, n);
	return (dst);
}
