/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psnapp <psnapp@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 15:30:36 by psnapp            #+#    #+#             */
/*   Updated: 2020/11/08 12:13:27 by psnapp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_words(char const *s, char c)
{
	int i;
	int words;

	i = 0;
	words = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] && s[i] != c)
			words++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (words);
}

int		ft_wordslen(char const *s, char c)
{
	int	len;
	int i;

	i = 0;
	len = 0;
	while (s[i] != '\0' && s[i] != c)
	{
		i++;
		len++;
	}
	return (len);
}

char	**ft_free(char **arr, int i)
{
	int j;

	j = 0;
	while (j < i)
	{
		free(arr[j]);
		j++;
	}
	free(arr);
	return (0);
}

char	**ft_arr(char const *s, char c, int words, char **arr)
{
	int i;
	int j;
	int len;

	i = 0;
	while (i < words)
	{
		while (*s == c)
			s++;
		len = ft_wordslen(s, c);
		if (!(arr[i] = (char *)malloc(sizeof(char) * (len + 1))))
			return (ft_free(arr, i));
		j = 0;
		while (j < len)
		{
			arr[i][j] = *s;
			s++;
			j++;
		}
		arr[i][j] = '\0';
		i++;
	}
	arr[i] = NULL;
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		words;

	if (!s)
		return (0);
	words = ft_words(s, c);
	if (!(arr = (char **)malloc(sizeof(char **) * (words + 1))))
		return (0);
	if (!(arr = ft_arr(s, c, words, arr)))
		return (0);
	return (arr);
}
