/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psnapp <psnapp@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 18:14:16 by psnapp            #+#    #+#             */
/*   Updated: 2020/11/04 18:20:33 by psnapp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstsize(t_list *lst)
{
	int		sum;
	t_list	*list;

	sum = 0;
	list = lst;
	if (lst != 0)
	{
		while (lst)
		{
			sum++;
			lst = lst->next;
		}
	}
	return (sum);
}
