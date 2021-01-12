/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psnapp <psnapp@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 15:30:10 by psnapp            #+#    #+#             */
/*   Updated: 2020/11/06 19:58:12 by psnapp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t		j;
	size_t		i;
	char		*b;

	i = 0;
	j = 0;
	b = (char *)big;
	if (*little == '\0')
		return ((char *)big);
	if (ft_strlen(little) > ft_strlen(big))
		return (0);
	i = ft_strlen(little);
	while (big[j] && j + i <= len)
	{
		if (ft_strncmp(&big[j], little, i) == 0)
			return (&b[j]);
		j++;
	}
	return (0);
}
