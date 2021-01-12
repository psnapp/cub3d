/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psnapp <psnapp@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 15:30:01 by psnapp            #+#    #+#             */
/*   Updated: 2020/11/04 22:02:48 by psnapp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	len;
	char	*ss1;
	char	*sset;
	char	*str;

	if (!s1 || !set)
		return (NULL);
	ss1 = (char *)s1;
	sset = (char *)set;
	i = 0;
	while (ss1[i] && ft_strchr(sset, ss1[i]))
		i++;
	len = ft_strlen(ss1) - 1;
	while (len && ft_strchr(sset, ss1[len]))
		len--;
	if ((int)i == ft_strlen(s1))
		return (ft_strdup(""));
	if (!(str = ft_substr(&ss1[i], 0, len - i + 1)))
		return (NULL);
	return (str);
}
