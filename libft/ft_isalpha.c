/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psnapp <psnapp@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 15:31:18 by psnapp            #+#    #+#             */
/*   Updated: 2020/11/05 16:15:52 by psnapp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_islower(int character)
{
	if (character >= 'a' && character <= 'z')
		return (1);
	return (0);
}

int		ft_isupper(int character)
{
	if (character >= 'A' && character <= 'Z')
		return (1);
	return (0);
}

int		ft_isalpha(int character)
{
	return (ft_islower(character) || ft_isupper(character));
}
