/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psnapp <psnapp@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 15:31:25 by psnapp            #+#    #+#             */
/*   Updated: 2020/11/03 15:59:25 by psnapp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_calloc(size_t n, size_t s)
{
	void	*dst;
	size_t	ss;

	ss = s * n;
	dst = malloc(ss);
	if (dst)
		ft_memset(dst, 0, ss);
	return (dst);
}
