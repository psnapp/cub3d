/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psnapp <psnapp@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 15:30:58 by psnapp            #+#    #+#             */
/*   Updated: 2020/11/03 18:10:06 by psnapp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *arr, int c, size_t n)
{
	char	*str;
	char	c1;
	int		i;

	str = (char *)arr;
	c1 = c;
	i = 0;
	if (n == 0)
		return (0);
	while (n > 0)
	{
		if (c1 == str[i])
			return ((void *)&str[i]);
		n--;
		i++;
	}
	return (NULL);
}
