/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 18:06:45 by ridalgo-          #+#    #+#             */
/*   Updated: 2022/09/22 00:21:21 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*ret;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		ret = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = ret;
	}
	*lst = NULL;
}
