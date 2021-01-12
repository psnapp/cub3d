/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psnapp <psnapp@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 12:33:24 by psnapp            #+#    #+#             */
/*   Updated: 2020/11/04 09:55:14 by psnapp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcpy(char *dst, const char *str, size_t n)
{
	size_t	i;

	i = 0;
	if (!dst || !str)
		return (0);
	if (n == 0)
		return (ft_strlen((char *)str));
	if (n > 0)
	{
		while (str[i] && i < (n - 1))
		{
			dst[i] = str[i];
			i++;
		}
		dst[i] = '\0';
		return (ft_strlen((char *)str));
	}
	return (0);
}
