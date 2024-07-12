/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niabraha <niabraha@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:14:29 by niabraha          #+#    #+#             */
/*   Updated: 2023/11/09 17:25:48 by niabraha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*var;

	var = *lst;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	while (var->next != NULL)
		var = var->next;
	var->next = new;
}
