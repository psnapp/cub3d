/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psnapp <psnapp@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 14:04:21 by psnapp            #+#    #+#             */
/*   Updated: 2020/12/03 18:51:52 by psnapp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_valid_args(int argc, char **argv)
{
	int len;

	if (argc < 2 || argc > 3)
	{
		write (1, "Error: Invalid number of arguments\n", 35);
		return (0);
	}
	len = ft_strlen(argv[1]);
	len = len - 4;
	if (argv[1][len] != '.' || argv[1][len + 1] != 'c' || argv[1][len + 2] != 'u' || argv[1][len + 3] != 'b' || argv[1][len + 4] != '\0')
	{
		write (1, "Error: Invalid argument\n", 24);
		return (0);
	}
	return (1);
}