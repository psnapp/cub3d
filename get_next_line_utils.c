/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psnapp <psnapp@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 10:45:52 by psnapp            #+#    #+#             */
/*   Updated: 2020/12/04 16:46:29 by psnapp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

int		ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

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

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char*)s;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}
