/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psnapp <psnapp@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 15:30:30 by psnapp            #+#    #+#             */
/*   Updated: 2020/11/03 18:24:20 by psnapp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*sstr;
	char	*dup;
	size_t	k;
	size_t	i;

	sstr = (char *)str;
	i = 0;
	k = ft_strlen(sstr);
	dup = (char *)malloc(sizeof(*dup) * (k + 1));
	if (!dup)
		return (0);
	if (dup)
	{
		while (k > 0)
		{
			dup[i] = sstr[i];
			i++;
			k--;
		}
	}
	dup[i] = '\0';
	return (dup);
}
