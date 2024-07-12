/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niabraha <niabraha@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 11:47:50 by niabraha          #+#    #+#             */
/*   Updated: 2023/11/09 17:27:50 by niabraha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*newvar;
	void	*deleter;

	newlst = NULL;
	if (!lst || !f || !del)
		return (NULL);
	while (lst)
	{
		deleter = (*f)(lst->content);
		newvar = ft_lstnew(deleter);
		if (!newvar)
		{
			del(deleter);
			ft_lstclear(&newlst, (*del));
			break ;
		}
		ft_lstadd_back(&newlst, newvar);
		lst = lst->next;
	}
	return (newlst);
}
