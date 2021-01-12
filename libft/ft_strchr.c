/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psnapp <psnapp@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 15:30:33 by psnapp            #+#    #+#             */
/*   Updated: 2020/11/03 18:23:39 by psnapp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int ch)
{
	int		i;
	char	*str1;
	char	chh;

	i = 0;
	str1 = (char *)str;
	chh = ch;
	while (str1[i])
	{
		if (str1[i] == chh)
			return (&str1[i]);
		i++;
	}
	if (str1[i] == '\0' && chh == 0)
		return (&str1[i]);
	return (0);
}
