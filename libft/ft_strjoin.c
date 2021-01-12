/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psnapp <psnapp@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 15:30:26 by psnapp            #+#    #+#             */
/*   Updated: 2020/11/04 09:53:04 by psnapp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ss;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (0);
	i = 0;
	j = 0;
	ss = (char *)malloc(sizeof(*ss) * ((ft_strlen(s1) + ft_strlen(s2)) + 1));
	if (ss)
	{
		while (s1[i] != '\0')
		{
			ss[i] = s1[i];
			i++;
		}
		while (s2[j] != '\0')
			ss[i++] = s2[j++];
		ss[i] = '\0';
		return (ss);
	}
	return (0);
}
