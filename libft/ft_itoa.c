/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psnapp <psnapp@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 15:31:04 by psnapp            #+#    #+#             */
/*   Updated: 2020/11/05 16:01:07 by psnapp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*zero(void)
{
	char	*str;

	if (!(str = (char *)malloc(sizeof(char) * 2)))
		return (NULL);
	str[0] = 0 + '0';
	str[1] = '\0';
	return (str);
}

static int		num(int n)
{
	int		count;

	count = 0;
	if (n < 0)
	{
		n = n * -1;
		count++;
	}
	while (n > 9)
	{
		n = n / 10;
		count++;
	}
	count++;
	return (count);
}

static	char	*max_or_min(int n)
{
	if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	else
		return (ft_strdup("2147483647"));
}

char			*ft_itoa(int n)
{
	int		len;
	int		i;
	char	*str;

	if (n == INT_MIN || n == INT_MAX)
		return (max_or_min(n));
	if (n == 0 || n == -0)
		return (zero());
	i = 0;
	len = num(n);
	if (!(str = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	if (n < 0)
	{
		str[i++] = '-';
		n = n * (-1);
	}
	str[len--] = '\0';
	while (len >= i)
	{
		str[len--] = (n % 10) + '0';
		n = n / 10;
	}
	return (str);
}
