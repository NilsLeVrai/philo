/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niabraha <niabraha@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:25:28 by niabraha          #+#    #+#             */
/*   Updated: 2023/11/09 17:25:56 by niabraha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*var;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		var = *lst;
		*lst = (*lst)->next;
		ft_lstdelone(var, *del);
	}
	lst = NULL;
}
