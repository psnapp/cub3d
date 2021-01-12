/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psnapp <psnapp@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 15:30:06 by psnapp            #+#    #+#             */
/*   Updated: 2020/11/04 10:04:38 by psnapp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	int		i;
	char	*str1;
	char	chh;
	char	*l;

	i = 0;
	str1 = (char *)str;
	chh = ch;
	l = 0;
	while (str1[i])
	{
		if (str1[i] == chh)
			l = &str1[i];
		i++;
	}
	if (l != 0)
		return (l);
	if (str1[i] == '\0' && chh == 0)
		return (&str1[i]);
	return (0);
}
