/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 18:05:16 by ridalgo-          #+#    #+#             */
/*   Updated: 2022/09/22 00:20:47 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lstadd_back(t_list **lst, t_list *newlst)
{
	t_list	*last;

	if (!lst || !newlst)
		return ;
	last = ft_lstlast(*lst);
	if (last != NULL)
		last->next = newlst;
	else
		*lst = newlst;
}
