/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psnapp <psnapp@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 20:07:06 by psnapp            #+#    #+#             */
/*   Updated: 2020/11/04 21:00:28 by psnapp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*list;
	t_list	*tmp;
	void	*i;

	i = 0;
	list = 0;
	tmp = NULL;
	while (lst)
	{
		i = (*f)(lst->content);
		if (!(tmp = ft_lstnew(i)))
		{
			ft_lstclear(&list, del);
			return (0);
		}
		ft_lstadd_back(&list, tmp);
		lst = lst->next;
	}
	return (list);
}
