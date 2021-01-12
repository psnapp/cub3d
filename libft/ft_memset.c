/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psnapp <psnapp@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 12:05:30 by psnapp            #+#    #+#             */
/*   Updated: 2020/10/30 16:34:47 by psnapp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *memptr, int val, size_t num)
{
	unsigned char	*mem;
	unsigned char	c;

	mem = (unsigned char *)memptr;
	c = (unsigned char)val;
	while (num)
	{
		*mem = c;
		num--;
		mem++;
	}
	return (memptr);
}
