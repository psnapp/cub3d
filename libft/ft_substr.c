/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psnapp <psnapp@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 15:29:56 by psnapp            #+#    #+#             */
/*   Updated: 2020/11/04 10:09:25 by psnapp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*nstr;
	unsigned int	i;
	unsigned int	len1;

	if (!s)
		return (NULL);
	i = 0;
	len1 = ft_strlen(s);
	if (len1 <= start)
	{
		if (!(nstr = (char *)malloc(sizeof(*nstr) * (len + 1))))
			return (0);
		nstr[0] = '\0';
		return (nstr);
	}
	nstr = (char *)malloc(sizeof(*nstr) * (len + 1));
	if (!nstr)
		return (NULL);
	while (len-- > 0)
	{
		nstr[i++] = s[start++];
	}
	nstr[i] = '\0';
	return (nstr);
}
