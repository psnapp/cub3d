/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psnapp <psnapp@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 19:16:21 by psnapp            #+#    #+#             */
/*   Updated: 2020/11/05 16:13:30 by psnapp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*list;
	t_list	*tmp;

	list = *lst;
	if (lst != NULL)
	{
		while (list)
		{
			tmp = list->next;
			(*del)(list->content);
			free(list);
			list = tmp;
		}
	}
	*lst = NULL;
}
